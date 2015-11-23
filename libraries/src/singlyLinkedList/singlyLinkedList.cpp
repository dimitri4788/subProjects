#include "singlyLinkedList.hpp"

#include <iostream>

/*
 ********************
 ******* Node *******
 ********************
*/
Node::Node(int data) : _data(data), _next(nullptr)
{}

Node::Node(int data, Node *nextNode) : _data(data), _next(nextNode)
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

void Node::setData(const int data)
{
    _data = data;
}

void Node::setNext(Node * const next)
{
    _next = next;
}

/*
 **********************************
 ******* Singly Linked List *******
 **********************************
*/
SinglyLinkedList::SinglyLinkedList() : _head(nullptr), _size(0)
{}

SinglyLinkedList::~SinglyLinkedList()
{
    clear();
}

Node * SinglyLinkedList::getHead() const
{
    return _head;
}

unsigned int SinglyLinkedList::getSize() const
{
    return _size;
}

void SinglyLinkedList::insertFront(int data)
{
    Node *newNode = new Node(data);
    newNode->_next = _head;
    _head = newNode;
    _size++;
}

void SinglyLinkedList::insertBack(int data)
{
    Node *newNode = new Node(data);
    if(_head == nullptr)
    {
        _head = newNode;
    }
    else
    {
        Node *curr = _head;
        while(curr->_next != nullptr)
            curr = curr->_next;

        curr->_next = newNode;
    }
    _size++;
}

bool SinglyLinkedList::remove(int data)
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

bool SinglyLinkedList::find(int data)
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

bool SinglyLinkedList::isEmpty() const
{
    return _head == nullptr;
}

void SinglyLinkedList::printList()
{
    if(_head == nullptr)
    {
        std::cout << "List is empty." << std::endl;
        return;
    }

    Node *curr = _head;
    while(curr->_next != nullptr)
    {
        std::cout << curr->_data << " -> " << std::endl;
        curr = curr->_next;
    }
    std::cout << curr->_data << std::endl;
}

void SinglyLinkedList::clear()
{
    Node *curr = _head;
    while(curr != nullptr)
    {
        _head = _head->_next;
        delete curr;
        curr = _head;
    }

    _head = nullptr;
    _size = 0;
}
