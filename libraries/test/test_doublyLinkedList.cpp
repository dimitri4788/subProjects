#include "doublyLinkedList.hpp"
#include "gtest/gtest.h"

//Test getData() and getNext() and getPrev()
TEST(DoublyLinkedListTest, TestGetDataGetNextForNode)
{
    Node node(7);
    EXPECT_EQ(7, node.getData());
    EXPECT_EQ(nullptr, node.getNext());
    EXPECT_EQ(nullptr, node.getPrev());
}

//Test getData() and getNext() for Node with two parameter constructor
TEST(DoublyLinkedListTest, TestGetDataGetNextForUsingTwoParameterConstructor)
{
    Node nodeNext(7);
    Node nodePrev(8);
    Node nodeSecond(69, &nodeNext, &nodePrev);

    EXPECT_EQ(7, nodeNext.getData());
    EXPECT_EQ(nullptr, nodeNext.getNext());
    EXPECT_EQ(nullptr, nodeNext.getPrev());

    EXPECT_EQ(8, nodePrev.getData());
    EXPECT_EQ(nullptr, nodePrev.getNext());
    EXPECT_EQ(nullptr, nodePrev.getPrev());

    EXPECT_EQ(69, nodeSecond.getData());
    EXPECT_NE(nullptr, nodeSecond.getNext());
    EXPECT_NE(nullptr, nodeSecond.getPrev());
}

//Test setData() for Node
TEST(DoublyLinkedListTest, TestSetDataForNode)
{
    Node node(7);
    node.setData(8);
    EXPECT_EQ(8, node.getData());
    EXPECT_EQ(nullptr, node.getNext());
    EXPECT_EQ(nullptr, node.getPrev());
}

//Test setNext() for Node
TEST(DoublyLinkedListTest, TestSetNextForNode)
{
    Node nodeFirst(7);
    Node nodeSecond(8);

    EXPECT_EQ(7, nodeFirst.getData());
    EXPECT_EQ(nullptr, nodeFirst.getNext());
    EXPECT_EQ(nullptr, nodeFirst.getPrev());

    nodeFirst.setNext(&nodeSecond);
    EXPECT_EQ(7, nodeFirst.getData());
    EXPECT_NE(nullptr, nodeFirst.getNext());
    EXPECT_EQ(nullptr, nodeFirst.getPrev());
}

//Test setPrev() for Node
TEST(DoublyLinkedListTest, TestSetPrevForNode)
{
    Node nodeFirst(7);
    Node nodeSecond(8);

    EXPECT_EQ(7, nodeFirst.getData());
    EXPECT_EQ(8, nodeSecond.getData());
    EXPECT_EQ(nullptr, nodeFirst.getNext());
    EXPECT_EQ(nullptr, nodeFirst.getPrev());

    nodeFirst.setPrev(&nodeSecond);
    EXPECT_EQ(7, nodeFirst.getData());
    EXPECT_EQ(nullptr, nodeFirst.getNext());
    EXPECT_NE(nullptr, nodeFirst.getPrev());
}

//Test setNext() for Node with two parameter constructor
TEST(DoublyLinkedListTest, TestSetNextForNodeWithTwoParameterConstructor)
{
    Node nodeFirst(7, nullptr, nullptr);
    Node nodeSecond(8);

    EXPECT_EQ(7, nodeFirst.getData());
    EXPECT_EQ(8, nodeSecond.getData());
    EXPECT_EQ(nullptr, nodeFirst.getNext());
    EXPECT_EQ(nullptr, nodeFirst.getPrev());

    nodeFirst.setNext(&nodeSecond);
    EXPECT_EQ(7, nodeFirst.getData());
    EXPECT_NE(nullptr, nodeFirst.getNext());
    EXPECT_EQ(nullptr, nodeFirst.getPrev());
}

//Test setPrev() for Node with two parameter constructor
TEST(DoublyLinkedListTest, TestSetPrevForNodeWithTwoParameterConstructor)
{
    Node nodeFirst(7, nullptr, nullptr);
    Node nodeSecond(8);

    EXPECT_EQ(7, nodeFirst.getData());
    EXPECT_EQ(nullptr, nodeFirst.getNext());
    EXPECT_EQ(nullptr, nodeFirst.getPrev());

    nodeFirst.setPrev(&nodeSecond);
    EXPECT_EQ(7, nodeFirst.getData());
    EXPECT_EQ(nullptr, nodeFirst.getNext());
    EXPECT_NE(nullptr, nodeFirst.getPrev());
}

//Test list getSize() and insertFront()
TEST(DoublyLinkedListTest, TestSizeInsertFront)
{
    DoublyLinkedList dl;
    dl.insertFront(2);
    EXPECT_EQ(1, dl.getSize());

    dl.insertFront(56);
    EXPECT_EQ(2, dl.getSize());
}

//Test list getSize() and insertBack()
TEST(DoublyLinkedListTest, TestSizeInsertBack)
{
    DoublyLinkedList dl;
    dl.insertBack(2);
    EXPECT_EQ(1, dl.getSize());

    dl.insertBack(56);
    EXPECT_EQ(2, dl.getSize());
}

//Test list remove()
TEST(DoublyLinkedListTest, TestListRemove)
{
    DoublyLinkedList dl;
    dl.insertBack(2);
    dl.insertBack(56);
    EXPECT_EQ(2, dl.getSize());

    EXPECT_EQ(true, dl.remove(2));
    EXPECT_EQ(1, dl.getSize());
}

//Test list remove() with one element and empty case
TEST(DoublyLinkedListTest, TestListRemoveWithOneElementAndEmptyCase)
{
    DoublyLinkedList dl;
    dl.insertBack(2);
    EXPECT_EQ(1, dl.getSize());
    EXPECT_EQ(true, dl.remove(2));
    EXPECT_EQ(0, dl.getSize());

    dl.insertFront(3);
    EXPECT_EQ(true, dl.remove(3));
    EXPECT_EQ(0, dl.getSize());
    EXPECT_EQ(false, dl.remove(3));
}

//Test list remove() with element not part of list
TEST(DoublyLinkedListTest, TestListRemoveWrongElement)
{
    DoublyLinkedList dl;
    EXPECT_EQ(false, dl.remove(2));
}

//Test insertBack() with single element
TEST(DoublyLinkedListTest, TestInsertBackWithSingleElement)
{
    DoublyLinkedList dl;
    EXPECT_EQ(0, dl.getSize());
    dl.insertBack(2);
    EXPECT_EQ(1, dl.getSize());
}

//Test insertBack() with multiple elements
TEST(DoublyLinkedListTest, TestInsertBackWithMultipleElements)
{
    DoublyLinkedList dl;
    EXPECT_EQ(0, dl.getSize());
    dl.insertBack(2);
    dl.insertBack(3);
    dl.insertBack(4);
    EXPECT_EQ(3, dl.getSize());
}

//Test insertBack() with multiple duplicate elements
TEST(DoublyLinkedListTest, TestInsertBackWithMultipleDuplicateElements)
{
    DoublyLinkedList dl;
    EXPECT_EQ(0, dl.getSize());
    dl.insertBack(2);
    dl.insertBack(2);
    dl.insertBack(2);
    EXPECT_EQ(3, dl.getSize());
}

//Test insertFront() with single element
TEST(DoublyLinkedListTest, TestInsertFrontWithSingleElement)
{
    DoublyLinkedList dl;
    EXPECT_EQ(0, dl.getSize());
    dl.insertFront(2);
    EXPECT_EQ(1, dl.getSize());
}

//Test insertFront() with multiple elements
TEST(DoublyLinkedListTest, TestInsertFrontWithMultipleElements)
{
    DoublyLinkedList dl;
    EXPECT_EQ(0, dl.getSize());
    dl.insertFront(2);
    dl.insertFront(3);
    dl.insertFront(4);
    dl.insertFront(5);
    EXPECT_EQ(4, dl.getSize());
}

//Test insertFront() with multiple duplicate elements
TEST(DoublyLinkedListTest, TestInsertFrontWithMultipleDuplicateElements)
{
    DoublyLinkedList dl;
    EXPECT_EQ(0, dl.getSize());
    dl.insertFront(2);
    dl.insertFront(2);
    dl.insertFront(2);
    dl.insertFront(2);
    EXPECT_EQ(4, dl.getSize());
}

//Test find()
TEST(DoublyLinkedListTest, TestFind)
{
    DoublyLinkedList dl;
    EXPECT_EQ(0, dl.getSize());
    dl.insertFront(2);
    EXPECT_EQ(true, dl.find(2));
    dl.remove(2);
    EXPECT_EQ(false, dl.find(2));
    EXPECT_EQ(false, dl.find(44));
}

//Test isEmpty()
TEST(DoublyLinkedListTest, TestIsEmpty)
{
    DoublyLinkedList dl;
    EXPECT_EQ(0, dl.getSize());
    EXPECT_EQ(true, dl.isEmpty());
    dl.insertFront(2);
    EXPECT_EQ(false, dl.isEmpty());
    dl.remove(2);
    EXPECT_EQ(true, dl.isEmpty());
}

/*
//Test getHead()
TEST(DoublyLinkedListTest, TestGetHead)
{
    DoublyLinkedList dl;
    EXPECT_EQ(nullptr, dl.getHead());

    dl.insertFront(2);
    EXPECT_NE(nullptr, dl.getHead());

    dl.remove(2);
    EXPECT_EQ(nullptr, dl.getHead());

    dl.insertFront(2);
    dl.insertFront(3);
    dl.remove(3);
    EXPECT_NE(nullptr, dl.getHead());
    dl.remove(2);
    EXPECT_EQ(nullptr, dl.getHead());

    dl.insertBack(3);
    dl.insertBack(4);
    EXPECT_EQ(2, dl.getSize());
    dl.remove(4);
    EXPECT_EQ(nullptr, dl.getHead()); //FIXME
    //dl.remove(3);
    //EXPECT_EQ(nullptr, dl.getHead());
}

//Test getTail()
TEST(DoublyLinkedListTest, TestGetTail)
{
    DoublyLinkedList dl;
    EXPECT_EQ(nullptr, dl.getTail());
    dl.insertFront(2);
    EXPECT_NE(nullptr, dl.getTail());
    dl.remove(2);
    EXPECT_EQ(nullptr, dl.getTail());
}

//Test printList()
TEST(DoublyLinkedListTest, TestPrintListInsertFront)
{
    //Capture stdout and save into a buffer
    std::stringstream buffer; //This can be an ofstream as well or any other ostream
    std::streambuf *sbuf = std::cout.rdbuf(); //Save cout's buffer here
    std::cout.rdbuf(buffer.rdbuf()); //Redirect cout to stringstream buffer or any other ostream

    DoublyLinkedList dl;
    dl.insertFront(2);
    dl.insertFront(37);
    dl.insertFront(6);
    dl.insertFront(89);
    dl.printList();

    EXPECT_EQ("89 -> 6 -> 37 -> 2\n", buffer.str());

    //Redirect cout to its old self
    std::cout.rdbuf(sbuf);
}

//Test printList() with empty list
TEST(DoublyLinkedListTest, TestPrintListWithEmptyListInsertFront)
{
    //Capture stdout and save into a buffer
    std::stringstream buffer; //This can be an ofstream as well or any other ostream
    std::streambuf *sbuf = std::cout.rdbuf(); //Save cout's buffer here
    std::cout.rdbuf(buffer.rdbuf()); //Redirect cout to stringstream buffer or any other ostream

    DoublyLinkedList dl;
    dl.printList();

    EXPECT_EQ("List is empty.\n", buffer.str());

    //Redirect cout to its old self
    std::cout.rdbuf(sbuf);
}

//Test printList() with one element
TEST(DoublyLinkedListTest, TestPrintListWithSingleElementInsertFront)
{
    //Capture stdout and save into a buffer
    std::stringstream buffer; //This can be an ofstream as well or any other ostream
    std::streambuf *sbuf = std::cout.rdbuf(); //Save cout's buffer here
    std::cout.rdbuf(buffer.rdbuf()); //Redirect cout to stringstream buffer or any other ostream

    DoublyLinkedList dl;
    dl.insertFront(6);
    dl.printList();

    EXPECT_EQ("6\n", buffer.str());

    //Redirect cout to its old self
    std::cout.rdbuf(sbuf);
}

//Test printList() with one element insertBack()
TEST(DoublyLinkedListTest, TestPrintListWithSingleElementInsertBack)
{
    //Capture stdout and save into a buffer
    std::stringstream buffer; //This can be an ofstream as well or any other ostream
    std::streambuf *sbuf = std::cout.rdbuf(); //Save cout's buffer here
    std::cout.rdbuf(buffer.rdbuf()); //Redirect cout to stringstream buffer or any other ostream

    DoublyLinkedList dl;
    dl.insertBack(6);
    dl.printList();

    EXPECT_EQ("6\n", buffer.str());

    //Redirect cout to its old self
    std::cout.rdbuf(sbuf);
}

//Test printList() insertBack()
TEST(DoublyLinkedListTest, TestPrintListInsertBack)
{
    //Capture stdout and save into a buffer
    std::stringstream buffer; //This can be an ofstream as well or any other ostream
    std::streambuf *sbuf = std::cout.rdbuf(); //Save cout's buffer here
    std::cout.rdbuf(buffer.rdbuf()); //Redirect cout to stringstream buffer or any other ostream

    DoublyLinkedList dl;
    dl.insertBack(2);
    dl.insertBack(37);
    dl.insertBack(6);
    dl.insertBack(89);
    dl.printList();

    EXPECT_EQ("2 -> 37 -> 6 -> 89\n", buffer.str());

    //Redirect cout to its old self
    std::cout.rdbuf(sbuf);
}

//Test printList() insertBack() and insertFront()
TEST(DoublyLinkedListTest, TestPrintListInsertBackInsertFront)
{
    //Capture stdout and save into a buffer
    std::stringstream buffer; //This can be an ofstream as well or any other ostream
    std::streambuf *sbuf = std::cout.rdbuf(); //Save cout's buffer here
    std::cout.rdbuf(buffer.rdbuf()); //Redirect cout to stringstream buffer or any other ostream

    DoublyLinkedList dl;
    dl.insertBack(2);
    dl.insertFront(37);
    dl.insertBack(6);
    dl.insertFront(89);
    dl.printList();

    EXPECT_EQ("89 -> 37 -> 2 -> 6\n", buffer.str());

    //Redirect cout to its old self
    std::cout.rdbuf(sbuf);
}
*/
