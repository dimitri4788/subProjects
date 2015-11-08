#include "log.h"

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

void logInsert(log *l, const char *data)
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

char *logAt(log *l, const unsigned int index)
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
    //TODO
}

unsigned int logSize(log *l)
{
    return l->size;
}
