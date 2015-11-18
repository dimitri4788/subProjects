#ifndef SINGLY_LINKED_LIST_HPP
#define	SINGLY_LINKED_LIST_HPP

class Node
{
    public:
        Node(int data);
        Node(int data, Node *nextNode);
        ~Node();

        int getData() const;
        Node *getNext() const;
        void setData(const int data);
        void setNext(const Node *next);

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

        bool addNodeInFront(int data);
        bool addNodeAtBack(int data);
        bool deleteNodeByIndex(int index);
        bool deleteNodeByData(int Data);
        int getNodeValue(int index);
        bool isEmpty() const;
        void printList();

    private:
        void clear();

        Node *_head;
        unsigned int _size;
};

#endif	/* SINGLY_LINKED_LIST_HPP */
