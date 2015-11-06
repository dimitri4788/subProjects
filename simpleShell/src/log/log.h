#ifndef LOG_HISTORY_H
#define LOG_HISTORY_H

//A single node containing the command
typedef struct _nodeDS
{
    char *command;
    struct _nodeDS *next;
    struct _nodeDS *prev;

} node;

//A doubly-linked-list to hold all the shell commands for keeping the history saved
typedef struct _loglist
{
    unsigned int size;
    node *head;
    node *tail;

} log;

void logConstructor(log *l);
void logDestructor(log *l);

void logInsert(log *l, const char *data);
char *logDelete(log *l);
char *logAt(log *l, const unsigned int index);
char *logSize(log *l, const char *prefix);
unsigned int logSize(log *l);

#endif /* LOG_HISTORY_H */
