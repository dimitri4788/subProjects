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

/**
 * @brief Initializes the log.
 *
 * @param l Pointer to the log data structure to be initialized.
 */
void logConstructor(log *l);

/**
 * @brief Frees all internal memory associated with the log.
 *
 * @param l Pointer to the log data structure to be destoryed.
 */
void logDestructor(log *l);

/**
 * @brief Inserts an item to the end of the log.
 *
 * @param l Pointer to the log data structure.
 * @param data Pointer to a string to be added to the log.
 */
void logInsert(log *l, char *data);

/**
 * @brief Removes and returns the last item in the log.
 *
 * @param l Pointer to the log data structure.
 *
 * @returns The last item in the log, or NULL if the log is empty.
 */
char *logPop(log *l);

/**
 * @brief Returns a pointer to the index-th element in the log,
 *  where the 0-th element is the first element.
 *
 * @param l Pointer to the log data structure.
 * @param index Zero-based index into the log, where the 0-th entry corresponds to
 *  the first (oldest) entry in the log and the (n-1)-th entry corresponds to
 *  the latest (newest) entry in the log.
 *
 * @returns The index-th entry in the log, or NULL if such an extry does not exist.
 */
char *logAt(log *l, unsigned int index);

/**
 * @brief Preforms a newest-to-oldest search of log entries for an entry matching a
 *  given prefix.
 *
 *  This search starts with the newest or (n-1)-th entry in the log and
 *  compares each entry to determine if query is a prefix of the log entry.
 *  Upon reaching a match, a pointer to that element is returned.  If no match
 *  is found, a NULL pointer is returned.
 *
 *  For example, a log may be built with five entries: logInsert(&l, "ab  1");
 *                                                     logInsert(&l, "a   2");
 *                                                     logInsert(&l, "abc 3");
 *                                                     logInsert(&l, "ab  4");
 *                                                     logInsert(&l, "a   5");
 *
 *  Using the log that was build above:
 *  - logSearch(&l, "ab")   will return the pointer to the string "ab  4".
 *  - logSearch(&l, "a")    will return the pointer to the string "a   5".
 *  - logSearch(&l, "abc")  will return the pointer to the string "abc 3".
 *  - logSearch(&l, "d")    will return a NULL pointer.
 *
 * @param l Pointer to the log data structure.
 * @param prefix The prefix to test each entry in the log for a match.
 *
 * @returns The newest entry in the log whose string matches the specified prefix.
 *  If no strings has the specified prefix, NULL is returned.
 */
char *logSearch(log *l, const char *prefix);

/**
 * @brief Returns the number of elements in the log.
 *
 * @param l Pointer to the log data structure.
 *
 * @returns Number of entires in the log.
 */
unsigned int logSize(log *l);

#endif /* LOG_HISTORY_H */
