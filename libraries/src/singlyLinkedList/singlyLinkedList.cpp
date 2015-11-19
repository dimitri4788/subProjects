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

void Node::setNext(const Node *next)
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

unsigned int SinglyLinkedList::getSize() const
{
    return _size;
}

bool SinglyLinkedList::insertFront(int data)
{
    Node *newNode = new Node(data);
    newNode->_next = _head;
    _head = newNode;
    _size++;
}

bool SinglyLinkedList::insertBack(int data)
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
        return true;

    if(_size == 1 && _head->_data == data)
    {
        delete _head;
        _head = nullptr;
        _size--;
        return true;
    }
    else
    {
        return false;
    }
    Node *curr = _head;
    while(curr->_next != null)
    {

    }

}

bool SinglyLinkedList::find(int data)
{

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
