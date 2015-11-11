#include "log.h"

#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

/**
 * @brief Trims the leading/trailing whitespaces
 *
 * @param str The string from which the whitespaces need to be trimmed
 *
 * @return Returns the modified string
 */
char *trimWhiteSpaces(char *str)
{
    //Trim from the beginning
    while(*str == ' ')
        str++;

    //Case of all spaces
    if(*str == 0)
        return str;

    //Trim from the end
    char *end = str + (strlen(str) - 1);
    while(end > str && *end == ' ')
        end--;

    *(end + 1) = '\0';

    return str;
}

char **parseCommandAndFillArgs(char *command)
{
    //Copy the command to use with strtok() in the second run
    char *commandCopy = (char *)malloc((strlen(command)+1) * sizeof(char));
    strcpy(commandCopy, command);

    char **args = NULL;
    int counter = 0;
    int i = 0;

    //First run to count the number of tokens
    char *token;
    token = strtok(command, " ");
    while(token != NULL)
    {
        counter++;
        token = strtok(NULL, " ");
    }

    //Second run to fill args
    args = (char **)malloc((counter+1) * sizeof(char *));
    token = strtok(commandCopy, " ");
    while(token != NULL)
    {
        *(args+i) = (char *)malloc((strlen(token)+1) * sizeof(char));
        strcpy(*(args+i), token);
        token = strtok(NULL, " ");
        i++;
    }

    //Assign NULL to the last pointer in args
    *(args + counter) = NULL;

    return args;
}

/**
 * @brief Executes the non built-in commands
 *
 * @param command The command to execute
 *
 * @return On success, it returns 0 and 1 on failure.
 */
int executeNonBuiltInCommand(char *command)
{
    printf("executeNonBuiltInCommand(): command is: %s\n", command);//XXX

    char **argsToExec = parseCommandAndFillArgs(command);
    printf("argsToExec[0] = %s\n", argsToExec[0]); 
    printf("argsToExec[1] = %s\n", argsToExec[1]); 
    printf("argsToExec[2] = %s\n", argsToExec[2]); 
    exit(0);

    int childStatus;
    pid_t waitPid;
    pid_t childPid = fork();
    if(childPid >= 0)
    {
        if(childPid == 0) //child process
        {
            pid_t parentPid = getppid();
            printf("Parent pid = %d", parentPid);
            //int execRetval = execvp(args[0], args);
        }
        else //parent process
        {
            printf("Child pid = %d", childPid);
            //Wait for the child to terminate
            waitPid = wait(&childStatus);
            if(waitPid == -1)
            {
                perror("wait() failed");
                exit(1);
            }
            else
            {
                printf("Command executed by child with pid=%d\n", waitPid);
            }
        }
    }
    else
    {
        printf("fork() failed.\n");
        exit(1);
    }

    return 0;
}

int main(int argc, char **argv)
{
    log l;
    logConstructor(&l);

    pid_t simpleShellPid = getpid();
    char buff[PATH_MAX+1];
    char *cwd = NULL;

    while(1)
    {
        cwd = getcwd(buff, PATH_MAX+1);
        if(cwd == NULL)
        {
            cwd = "/dummy/path";
        }

        //Print a command prompt
        printf("(pid=%d)%s$ ", simpleShellPid, cwd);

        //Read the command from the stdin
        char *command = NULL;
        size_t commandLen = 0;
        ssize_t nBytesRead;
        nBytesRead = getline(&command, &commandLen, stdin);
        *(command + (nBytesRead-1)) = '\0';
        //printf("command: '%s'\n", command); //XXX
        //printf("nBytesRead: %zu\n", nBytesRead); //XXX

        //Remove the leading/trailing whitespaces from the command
        char *trimmedCommand = trimWhiteSpaces(command);
        //printf("command after trimming: '%s'\n", trimmedCommand); //XXX

        /*
         * Execute the command: built-in command and non built-in command.
         * Built-in commands are executed without creating a new process, whereas
         * a non built-in command is executed by creating a new process to execute the program for that
         * particular command.
         *
         * Built-in commands: cd, exit and two commands (!# and !) based on a history feature.
         *     !#: Prints a list of all the commands saved in the history separated by newlines.
         *     !query: Re-executes the last command whose prefix matches query
         *
         * Non built-in commands: ls, pwd, ps, echo hello, and etc.
         */
        if(strncmp(trimmedCommand, "exit", 4) == 0)
        {
            exit(0);
        }
        else if(strncmp(trimmedCommand, "cd", 2) == 0)
        {
            char *path = NULL;
            int error;
            if((nBytesRead-1) == 2)
            {
                //Change to home directory
                path = getenv("HOME");
                error = chdir(path);
            }
            else
            {
                //Change to the specified directory
                path = trimmedCommand + 3;
                error = chdir(path);
            }

            if(error == -1)
            {
                perror("Error while changing directory");
            }
            else
            {
                //Add the command to the log
                logInsert(&l, trimmedCommand);
            }
        }
        else if((strncmp(trimmedCommand, "!#", 2) == 0) && ((nBytesRead-1) == 2))
        {
            unsigned int sizeOfLog = logSize(&l);
            if(sizeOfLog == 0)
            {
                printf("Nothing in the log history yet.\n");
            }

            for(int i = (sizeOfLog-1); i>=0; --i)
            {
                printf("%s\n", logAt(&l, i));
            }
        }
        else if((strncmp(trimmedCommand, "!", 1) == 0) && (*(trimmedCommand+1) != '#') && ((nBytesRead-1) > 1))
        {
            char *retCommand = logSearch(&l, trimmedCommand+1);
            if(retCommand != NULL)
            {
                printf("%s matches %s\n", (trimmedCommand+1), retCommand);

                int retVal = executeNonBuiltInCommand(retCommand);
                if(retVal == 0) //success
                {
                    //Add the command to the log
                    logInsert(&l, retCommand);
                }
                else
                {
                    printf("%s: not found.\n", retCommand);
                }
            }
            else
            {
                printf("No match found.\n");
            }
        }
        else
        {
            int retVal = executeNonBuiltInCommand(trimmedCommand);
            if(retVal == 0) //success
            {
                //Add the command to the log
                logInsert(&l, trimmedCommand);
            }
            else
            {
                printf("%s: not found.\n", trimmedCommand);
            }
        }
    }

    return 0;
}
