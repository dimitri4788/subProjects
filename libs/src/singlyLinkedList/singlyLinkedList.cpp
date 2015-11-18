#include "singlyLinkedList.hpp"

#include <iostream>

/*
 ********************
 ******* Node *******
 ********************
*/
Node::Node(int data)
{
    _data = data;
    _next = nullptr;
}

Node::Node(int data, Node *nextNode)
{
    _data = data;
    _next = nextNode;
}

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
SinglyLinkedList::SinglyLinkedList()
{
    _head = nullptr;
    _size = 0;
}

SinglyLinkedList::~SinglyLinkedList()
{
    clear();
}

unsigned int SinglyLinkedList::getSize() const
{
    return _size;
}

bool SinglyLinkedList::addNodeInFront(int data)
{
    Node *newNode = new Node(data);
    newNode->_next = _head;
    _head = newNode;
    _size++;
}

bool SinglyLinkedList::addNodeAtBack(int data)
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

bool SinglyLinkedList::deleteNodeByIndex(int index)
{
    if((index+1) > _size)
        return false;
    if(_head == nullptr)
        return true;

    Node *curr = _head;
    if(index == 0)
    {
        _head = _head->_next;
        delete curr;
        _size--;
        return true;
    }

    index--;
    while(index > 0)
    {
        curr = curr->_next;
        index--;
    }

    Node *temp = curr->_next;
    curr->_next = temp->_next;
    delete temp;
    _size--;
    return true;
}

bool SinglyLinkedList::deleteNodeByData(int Data)
{

}

int SinglyLinkedList::getNodeValue(int index)
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
