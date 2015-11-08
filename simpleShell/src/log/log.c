#include "log.h"

#include <stdlib.h>
#include <string.h>

void logConstructor(log *l)
{
    l->size = 0;
    l->head = NULL;
    l->tail = NULL;
}

void logDestructor(log *l)
{
    if(l->head == NULL)
        return;

    node *curr = l->head;
    node *nextNode = NULL;
    while(curr != NULL)
    {
        nextNode = curr->next;
        free(curr);
        curr = nextNode;
    }
}

void logInsert(log *l, char *data)
{
    l->size++;
    node *newNode = (node *)malloc(sizeof(node));
    newNode->command = data;

    if(l->head == NULL)
    {
        newNode->next = NULL;
        newNode->prev = NULL;
        l->head = newNode;
        l->tail = newNode;
    }
    else
    {
        newNode->next = NULL;
        newNode->prev = l->tail;
        l->tail->next = newNode;
        l->tail = newNode;
    }
}

char *logPop(log *l)
{
    if(l->head == NULL)
        return NULL;

    l->size--;
    char *lastItem = l->tail->command;
    node *temp = l->tail;
    l->tail = temp->prev;
    l->tail->next = NULL;
    free(temp);

    return lastItem;
}

char *logAt(log *l, unsigned int index)
{
    if(l->head == NULL)
        return NULL;
    if((index+1) > l->size)
        return NULL;

    node *curr = l->head;
    while(index > 0)
    {
        curr = curr->next;
        index--;
    }

    return curr->command;
}

char *logSearch(log *l, const char *prefix)
{
    if(l->head == NULL)
        return NULL;

    node *curr = l->tail;
    unsigned int len = strlen(prefix);
    while(curr != NULL)
    {
        if(strncmp(curr->command, prefix, len) == 0)
        {
            break;
        }
        curr = curr->prev;
    }

    return curr->command;
}

unsigned int logSize(log *l)
{
    return l->size;
}
