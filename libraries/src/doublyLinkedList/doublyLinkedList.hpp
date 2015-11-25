#ifndef DOUBLY_LINKED_LIST_HPP
#define	DOUBLY_LINKED_LIST_HPP

class Node
{
    friend class DoublyLinkedList

    public:
        Node(int data);
        Node(int data, Node *nextNode, Node *prevNode);
        ~Node();

        int getData() const;
        Node *getNext() const;
        Node *getPrev() const;
        void setData(const int data);
        void setNext(Node * const next);
        void setPrev(Node * const prev);

    private:
        int _data;
        Node *_next;
        Node *_prev;
};

class DoublyLinkedList
{
    public:
        DoublyLinkedList();
        ~DoublyLinkedList();

        Node *getHead() const;
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
        Node *_tail;
        unsigned int _size;
};

#endif	/* DOUBLY_LINKED_LIST_HPP */
