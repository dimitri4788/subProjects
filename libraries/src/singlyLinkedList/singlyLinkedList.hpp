#ifndef SINGLY_LINKED_LIST_HPP
#define	SINGLY_LINKED_LIST_HPP

class Node
{
    friend class SinglyLinkedList;

    public:
        Node(int data);
        Node(int data, Node *nextNode);
        ~Node();

        int getData() const;
        Node *getNext() const;
        void setData(const int data);
        void setNext(Node * const next);

    private:
        int _data;
        Node *_next;
};

class SinglyLinkedList
{
    public:
        SinglyLinkedList();
        ~SinglyLinkedList();

        unsigned int getSize() const;

        void insertFront(int data);
        void insertBack(int data);
        bool remove(int data);
        bool find(int data);
        bool isEmpty() const;
        void printList();

    private:
        void clear();

        Node *_head;
        unsigned int _size;
};

#endif	/* SINGLY_LINKED_LIST_HPP */
