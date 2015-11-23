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

//Test list remove() with element not part of list
TEST(SinglyLinkedListTest, TestListRemoveWrongElement)
{
    SinglyLinkedList sl;
    EXPECT_EQ(false, sl.remove(2));
}

//Test insertBack() with single element
TEST(SinglyLinkedListTest, TestInsertBackWithSingleElement)
{
    SinglyLinkedList sl;
    EXPECT_EQ(0, sl.getSize());
    sl.insertBack(2);
    EXPECT_EQ(1, sl.getSize());
}

//Test insertBack() with multiple elements
TEST(SinglyLinkedListTest, TestInsertBackWithMultipleElements)
{
    SinglyLinkedList sl;
    EXPECT_EQ(0, sl.getSize());
    sl.insertBack(2);
    sl.insertBack(3);
    sl.insertBack(4);
    EXPECT_EQ(3, sl.getSize());
}

//Test insertBack() with multiple duplicate elements
TEST(SinglyLinkedListTest, TestInsertBackWithMultipleDuplicateElements)
{
    SinglyLinkedList sl;
    EXPECT_EQ(0, sl.getSize());
    sl.insertBack(2);
    sl.insertBack(2);
    sl.insertBack(2);
    EXPECT_EQ(3, sl.getSize());
}

//Test insertFront() with single element
TEST(SinglyLinkedListTest, TestInsertFrontWithSingleElement)
{
    SinglyLinkedList sl;
    EXPECT_EQ(0, sl.getSize());
    sl.insertFront(2);
    EXPECT_EQ(1, sl.getSize());
}

//Test insertFront() with multiple elements
TEST(SinglyLinkedListTest, TestInsertFrontWithMultipleElements)
{
    SinglyLinkedList sl;
    EXPECT_EQ(0, sl.getSize());
    sl.insertFront(2);
    sl.insertFront(3);
    sl.insertFront(4);
    sl.insertFront(5);
    EXPECT_EQ(4, sl.getSize());
}

//Test insertFront() with multiple duplicate elements
TEST(SinglyLinkedListTest, TestInsertFrontWithMultipleDuplicateElements)
{
    SinglyLinkedList sl;
    EXPECT_EQ(0, sl.getSize());
    sl.insertFront(2);
    sl.insertFront(2);
    sl.insertFront(2);
    sl.insertFront(2);
    EXPECT_EQ(4, sl.getSize());
}

//Test find()
TEST(SinglyLinkedListTest, TestFind)
{
    SinglyLinkedList sl;
    EXPECT_EQ(0, sl.getSize());
    sl.insertFront(2);
    EXPECT_EQ(true, sl.find(2));
    sl.remove(2);
    EXPECT_EQ(false, sl.find(2));
    EXPECT_EQ(false, sl.find(44));
}

//Test isEmpty()
TEST(SinglyLinkedListTest, TestIsEmpty)
{
    SinglyLinkedList sl;
    EXPECT_EQ(0, sl.getSize());
    EXPECT_EQ(true, sl.isEmpty());
    sl.insertFront(2);
    EXPECT_EQ(false, sl.isEmpty());
    sl.remove(2);
    EXPECT_EQ(true, sl.isEmpty());
}

//Test getHead()
TEST(SinglyLinkedListTest, TestGetHead)
{
    SinglyLinkedList sl;
    EXPECT_EQ(nullptr, sl.getHead());
    sl.insertFront(2);
    EXPECT_NE(nullptr, sl.getHead());
    sl.remove(2);
    EXPECT_EQ(nullptr, sl.getHead());
}

//Test printList()
TEST(SinglyLinkedListTest, TestPrintList)
{
    //Capture stdout and save into a buffer
    std::stringstream buffer; //This can be an ofstream as well or any other ostream
    std::streambuf *sbuf = std::cout.rdbuf(); //Save cout's buffer here
    std::cout.rdbuf(buffer.rdbuf()); //Redirect cout to stringstream buffer or any other ostream

    SinglyLinkedList sl;
    sl.insertFront(2);
    sl.insertFront(37);
    sl.insertFront(6);
    sl.insertFront(89);
    sl.printList();

    EXPECT_EQ("89 -> 6 -> 37 -> 2\n", buffer.str());

    //Redirect cout to its old self
    std::cout.rdbuf(sbuf);
}

//Test printList() with empty list
TEST(SinglyLinkedListTest, TestPrintListWithEmptyList)
{
    //Capture stdout and save into a buffer
    std::stringstream buffer; //This can be an ofstream as well or any other ostream
    std::streambuf *sbuf = std::cout.rdbuf(); //Save cout's buffer here
    std::cout.rdbuf(buffer.rdbuf()); //Redirect cout to stringstream buffer or any other ostream

    SinglyLinkedList sl;
    sl.printList();

    EXPECT_EQ("List is empty.\n", buffer.str());

    //Redirect cout to its old self
    std::cout.rdbuf(sbuf);
}
