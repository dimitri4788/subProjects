#include "log.h"

#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

int main(int argc, char **argv)
{
    log l;
    logConstructor(&l);

    while(1)
    {
        //Print a command prompt
        printf("[simpleShell]> ");

        //Read the command from the stdin
        char *command = NULL;
        size_t commandLen = 0;
        ssize_t nBytesRead;
        nBytesRead = getline(&command, &commandLen, stdin);
        *(command + (nBytesRead-1)) = '\0';
        printf("command: %s\n", command);
        printf("nBytesRead: %zu\n", nBytesRead);

        //Execute the command
        if()
        {

        }
        else if()
        {

        }
        else if()
        {

        }
        else
        {

        }

        free(command);
    }

    return 0;
}
