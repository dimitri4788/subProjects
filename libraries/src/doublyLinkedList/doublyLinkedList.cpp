#include "doublyLinkedList.hpp"

#include <iostream>

/*
 ********************
 ******* Node *******
 ********************
*/
Node::Node(int data) : _data(data), _next(nullptr), _prev(nullptr)
{}

Node::Node(int data, Node *nextNode, Node *prevNode) : _data(data), _next(nextNode), _prev(prevNode)
{}

Node::~Node()
{}

int Node::getData() const
{
    return _data;
}

Node * Node::getNext() const
{
    return _next;
}

Node * Node::getPrev() const
{
    return _prev;
}

void Node::setData(const int data)
{
    _data = data;
}

void Node::setNext(Node * const next)
{
    _next = next;
}

void Node::setPrev(Node * const prev)
{
    _prev = prev;
}

/*
 **********************************
 ******* Doubly Linked List *******
 **********************************
*/
DoublyLinkedList::DoublyLinkedList() : _head(nullptr), _tail(nullptr), _size(0)
{}

DoublyLinkedList::~DoublyLinkedList()
{
    clear();
}

Node * DoublyLinkedList::getHead() const
{
    return _head;
}

Node * DoublyLinkedList::getTail() const
{
    return _tail;
}

unsigned int DoublyLinkedList::getSize() const
{
    return _size;
}

void DoublyLinkedList::insertFront(int data)
{
    _size++;
    Node *newNode = new Node(data);
    if(_head == nullptr)
    {
        _head = newNode;
        _tail = newNode;
        return;
    }
    newNode->_next = _head;
    _head = newNode;
}

void DoublyLinkedList::insertBack(int data)
{
    _size++;
    Node *newNode = new Node(data);
    if(_tail == nullptr)
    {
        _head = newNode;
        _tail = newNode;
        return;
    }
    newNode->_prev = _tail;
    _tail = newNode;
}

bool DoublyLinkedList::remove(int data)
{
    if(_head == nullptr)
        return false;

    Node *curr = _head;
    if(_head->_data == data)
    {
        _head = _head->_next;
        delete curr;
        _size--;
        return true;
    }

    bool retVal = false;
    while(curr->_next != nullptr && curr != nullptr)
    {
        if(curr->_next->_data == data)
        {
            Node *temp = curr->_next;
            curr->_next = temp->_next;
            delete temp;
            curr = curr->_next;
            _size--;
            retVal = true;
        }
    }
    return retVal;
}

bool DoublyLinkedList::find(int data)
{
    if(_head == nullptr)
        return false;

    Node *curr = _head;
    while(curr != nullptr)
    {
        if(curr->_data == data)
            return true;
    }
    return false;
}

bool DoublyLinkedList::isEmpty() const
{
    return _head == nullptr;
}

void DoublyLinkedList::printList()
{
    if(_head == nullptr)
    {
        std::cout << "List is empty." << std::endl;
        return;
    }

    Node *curr = _head;
    while(curr->_next != nullptr)
    {
        std::cout << curr->_data << " -> ";
        curr = curr->_next;
    }
    std::cout << curr->_data << std::endl;
}

void DoublyLinkedList::clear()
{
    Node *curr = _head;
    while(curr != nullptr)
    {
        _head = _head->_next;
        delete curr;
        curr = _head;
    }

    _head = nullptr;
    _tail = nullptr;
    _size = 0;
}
