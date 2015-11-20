#include "singlyLinkedList.hpp"
#include "gtest/gtest.h"

//Test getData() and getNext() for Node
TEST(SinglyLinkedListTest, TestGetDataGetNextForNode)
{
    Node node(7);
    EXPECT_EQ(7, node.getData());
    EXPECT_EQ(nullptr, node.getNext());
}

//Test getData() and getNext() for Node with two parameter constructor
TEST(SinglyLinkedListTest, TestGetDataGetNextForUsingTwoParameterConstructor)
{
    Node nodeFirst(7);
    Node nodeSecond(69, &nodeFirst);

    EXPECT_EQ(7, nodeFirst.getData());
    EXPECT_EQ(nullptr, nodeFirst.getNext());

    EXPECT_EQ(69, nodeSecond.getData());
    EXPECT_NE(nullptr, nodeSecond.getNext());
}

//Test setData() for Node
TEST(SinglyLinkedListTest, TestSetDataForNode)
{
    Node node(7);
    node.setData(8);
    EXPECT_EQ(8, node.getData());
    EXPECT_EQ(nullptr, node.getNext());
}

//Test setNext() for Node
TEST(SinglyLinkedListTest, TestSetNextForNode)
{
    Node nodeFirst(7);
    Node nodeSecond(8);

    EXPECT_EQ(7, nodeFirst.getData());
    EXPECT_EQ(nullptr, nodeFirst.getNext());

    nodeFirst.setNext(&nodeSecond);
    EXPECT_EQ(7, nodeFirst.getData());
    EXPECT_NE(nullptr, nodeFirst.getNext());
}

//Test setNext() for Node with two parameter constructor
TEST(SinglyLinkedListTest, TestSetNextForNodeWithTwoParameterConstructor)
{
    Node nodeFirst(7, nullptr);
    Node nodeSecond(8);

    EXPECT_EQ(7, nodeFirst.getData());
    EXPECT_EQ(nullptr, nodeFirst.getNext());

    nodeFirst.setNext(&nodeSecond);
    EXPECT_EQ(7, nodeFirst.getData());
    EXPECT_NE(nullptr, nodeFirst.getNext());
}

//Test list getSize() and insertFront()
TEST(SinglyLinkedListTest, TestSizeInsertFront)
{
    SinglyLinkedList sl;
    sl.insertFront(2);
    EXPECT_EQ(1, sl.getSize());

    sl.insertFront(56);
    EXPECT_EQ(2, sl.getSize());
}

//Test list getSize() and insertBack()
TEST(SinglyLinkedListTest, TestSizeInsertBack)
{
    SinglyLinkedList sl;
    sl.insertBack(2);
    EXPECT_EQ(1, sl.getSize());

    sl.insertBack(56);
    EXPECT_EQ(2, sl.getSize());
}

//Test list remove()
TEST(SinglyLinkedListTest, TestListRemove)
{
    SinglyLinkedList sl;
    sl.insertBack(2);
    sl.insertBack(56);
    EXPECT_EQ(2, sl.getSize());

    EXPECT_EQ(true, sl.remove(2));
    EXPECT_EQ(1, sl.getSize());
}

/*
//Test list remove() with one element and empty case
TEST(SinglyLinkedListTest, TestListRemoveWithOneElementAndEmptyCase)
{
    SinglyLinkedList sl;
    sl.insertBack(2);
    EXPECT_EQ(1, sl.getSize());
    EXPECT_EQ(true, sl.remove(2));
    EXPECT_EQ(0, sl.getSize());

    sl.insertFront(3);
    EXPECT_EQ(true, sl.remove(3));
    EXPECT_EQ(0, sl.getSize());
    EXPECT_EQ(false, sl.remove(3));
}
*/

/*
unsigned int getSize() const;

void insertFront(int data);
void insertBack(int data);
bool remove(int data);
bool find(int data);
bool isEmpty() const;
void printList();

void clear();

Node *_head;
unsigned int _size;
*/
