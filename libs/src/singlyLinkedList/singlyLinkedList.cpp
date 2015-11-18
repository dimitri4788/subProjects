#include "singlyLinkedList.hpp"

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

Node *_head;
unsigned int _size;

SinglyLinkedList::SinglyLinkedList()
{
    _head = nullptr;
    _size = 0;
}

SinglyLinkedList::~SinglyLinkedList()
{
    if(_head != nullptr)


}

Node * SinglyLinkedList::getHead() const;
{

}

unsigned int SinglyLinkedList::getSize() const
{

}

bool SinglyLinkedList::addNodeInFront(int data)
{

}

bool SinglyLinkedList::addNodeAtBack(int data)
{

}

bool SinglyLinkedList::deleteNode(int index)
{

}

int SinglyLinkedList::getNodeValue(int index)
{

}

void SinglyLinkedList::printList()
{

}
