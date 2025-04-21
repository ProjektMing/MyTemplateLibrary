#include "MyQueue.hpp"
#include <gtest/gtest.h>
#include <string>

TEST(MyQueueTest, IntQueueOperations)
{
    MyQueue<int> queue;

    EXPECT_TRUE(queue.IsEmpty());
    EXPECT_EQ(queue.Size(), 0);

    queue.Enqueue(1);
    queue.Enqueue(2);
    queue.Enqueue(3);

    EXPECT_FALSE(queue.IsEmpty());
    EXPECT_EQ(queue.Size(), 3);

    EXPECT_EQ(queue.Front(), 1);

    queue.Dequeue();
    EXPECT_EQ(queue.Front(), 2);
    EXPECT_EQ(queue.Size(), 2);

    queue.Dequeue();
    EXPECT_EQ(queue.Front(), 3);
    EXPECT_EQ(queue.Size(), 1);

    queue.Dequeue();
    EXPECT_TRUE(queue.IsEmpty());
}

TEST(MyQueueTest, StringQueueOperations)
{
    MyQueue<std::string> queue;

    queue.Enqueue("Hello");
    queue.Enqueue("World");

    EXPECT_EQ(queue.Size(), 2);
    EXPECT_EQ(queue.Front(), "Hello");

    queue.Dequeue();
    EXPECT_EQ(queue.Front(), "World");
}

TEST(MyQueueTest, MoveSemantics)
{
    MyQueue<std::string> queue;
    std::string str = "Test String";

    queue.Enqueue(std::move(str));
    EXPECT_TRUE(str.empty());
    EXPECT_EQ(queue.Front(), "Test String");

    std::string str2 = "Another String";
    queue.Enqueue(std::move(str2));
    EXPECT_TRUE(str2.empty());
}

TEST(MyQueueTest, ConstFront)
{
    MyQueue<int> queue;
    queue.Enqueue(1);
    queue.Enqueue(2);

    const MyQueue<int> &constQueue = queue;
    EXPECT_EQ(constQueue.Front(), 1);

    queue.Dequeue();
    EXPECT_EQ(constQueue.Front(), 2);
}

TEST(MyQueueTest, ModifyFrontReference)
{
    MyQueue<int> queue;
    queue.Enqueue(10);

    queue.Front() = 20;
    EXPECT_EQ(queue.Front(), 20);
}

#include "MyList.hpp"
TEST(MyQueueTest, CustomContainer)
{
    MyQueue<std::string, MyList> queue;
    queue.Enqueue("Custom Container Test");

    EXPECT_EQ(queue.Size(), 1);
    EXPECT_EQ(queue.Front(), "Custom Container Test");
}