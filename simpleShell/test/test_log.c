#include "log.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char **argv)
{
    uint8_t totalNumberOfTests = 0;
    uint8_t numberOfTestsPassed = 0;
    uint8_t numberOfTestsFailed = 0;
    char *retString = NULL;

    //Create a log variable
    log l;
    logConstructor(&l);

    //Insert some data in the log
    logInsert(&l, "cd ..");
    logInsert(&l, "pwd");
    logInsert(&l, "ls");
    logInsert(&l, "cd");
    logInsert(&l, "ls -l");

    //Test 1
    totalNumberOfTests++;
    if(logSize(&l) == 5)
        numberOfTestsPassed++;

    //Test 2
    retString = logPop(&l);
    totalNumberOfTests++;
    if(strcmp(retString, "ls -l") == 0)
        numberOfTestsPassed++;

    //Test 3
    totalNumberOfTests++;
    retString = logPop(&l);
    if(strcmp(retString, "cd") == 0)
        numberOfTestsPassed++;

    //Test 4
    totalNumberOfTests++;
    if(logSize(&l) == 3)
        numberOfTestsPassed++;

    //Test 5
    totalNumberOfTests++;
    retString = logPop(&l);
    if(strcmp(retString, "ls") == 0)
        numberOfTestsPassed++;

    //Test 6
    totalNumberOfTests++;
    retString = logPop(&l);
    if(strcmp(retString, "pwd") == 0)
        numberOfTestsPassed++;

    //Test 7
    totalNumberOfTests++;
    if(logSize(&l) == 1)
        numberOfTestsPassed++;

    //Test 8
    totalNumberOfTests++;
    retString = logPop(&l);
    if(strcmp(retString, "cd ..") == 0)
        numberOfTestsPassed++;

    //Test 9
    totalNumberOfTests++;
    if(logSize(&l) == 0)
        numberOfTestsPassed++;

    //Test 10
    totalNumberOfTests++;
    retString = logPop(&l);
    if(retString == NULL)
        numberOfTestsPassed++;

    //Insert some data in the log
    logInsert(&l, "cd ..");
    logInsert(&l, "pwd");
    logInsert(&l, "ls");

    //Test 11
    totalNumberOfTests++;
    if(logSize(&l) == 3)
        numberOfTestsPassed++;

    //Test 12
    totalNumberOfTests++;
    retString = logAt(&l, 0);
    if(strcmp(retString, "cd ..") == 0)
        numberOfTestsPassed++;

    //Test 13
    totalNumberOfTests++;
    retString = logAt(&l, 1);
    if(strcmp(retString, "pwd") == 0)
        numberOfTestsPassed++;

    //Test 14
    totalNumberOfTests++;
    retString = logAt(&l, 2);
    if(strcmp(retString, "ls") == 0)
        numberOfTestsPassed++;

    //Test 15
    totalNumberOfTests++;
    retString = logAt(&l, 3);
    if(retString == NULL)
        numberOfTestsPassed++;

    //Test 16
    totalNumberOfTests++;
    if(logSize(&l) == 3)
        numberOfTestsPassed++;

    //Insert some data in the log
    logInsert(&l, "ab 1");
    logInsert(&l, "abc 2");
    logInsert(&l, "a 3");

    //Test 17
    totalNumberOfTests++;
    retString = logSearch(&l, "pw");
    if(strcmp(retString, "pwd") == 0)
        numberOfTestsPassed++;

    //Test 18
    totalNumberOfTests++;
    retString = logSearch(&l, "a");
    if(strcmp(retString, "a 3") == 0)
        numberOfTestsPassed++;

    //Test 19
    totalNumberOfTests++;
    retString = logSearch(&l, "ab");
    if(strcmp(retString, "abc 2") == 0)
        numberOfTestsPassed++;

    //Test 20
    totalNumberOfTests++;
    retString = logSearch(&l, "ab ");
    if(strcmp(retString, "ab 1") == 0)
        numberOfTestsPassed++;

    //Test 21
    totalNumberOfTests++;
    retString = logSearch(&l, "cd");
    if(strcmp(retString, "cd ..") == 0)
        numberOfTestsPassed++;

    //Test 22
    totalNumberOfTests++;
    retString = logSearch(&l, "devil");
    if(retString == NULL)
        numberOfTestsPassed++;

    logPop(&l);
    logPop(&l);
    logPop(&l);
    logPop(&l);
    logPop(&l);
    logPop(&l);

    //Test 23
    totalNumberOfTests++;
    if(logSize(&l) == 0)
        numberOfTestsPassed++;

    numberOfTestsFailed = totalNumberOfTests - numberOfTestsPassed;
    printf("totalNumberOfTests = %d\n", totalNumberOfTests);
    printf("numberOfTestsPassed = %d\n", numberOfTestsPassed);
    printf("numberOfTestsFailed = %d\n", numberOfTestsFailed);

    return 0;
}
