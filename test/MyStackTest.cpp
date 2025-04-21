#include "MyStack.hpp"
#include <gtest/gtest.h>
#include <string>

TEST(MyStackTest, IsEmptyOnNewStack)
{
    MyStack<int> stack;
    EXPECT_TRUE(stack.IsEmpty());
    EXPECT_EQ(stack.Size(), 0);
}

TEST(MyStackTest, PushAndSize)
{
    MyStack<int> stack;

    stack.Push(1);
    EXPECT_FALSE(stack.IsEmpty());
    EXPECT_EQ(stack.Size(), 1);

    stack.Push(2);
    stack.Push(3);
    EXPECT_EQ(stack.Size(), 3);
}

TEST(MyStackTest, Top)
{
    MyStack<int> stack;
    stack.Push(10);
    EXPECT_EQ(stack.Top(), 10);

    stack.Push(20);
    EXPECT_EQ(stack.Top(), 20);

    EXPECT_EQ(stack.Size(), 2);
}

TEST(MyStackTest, Pop)
{
    MyStack<int> stack;
    stack.Push(5);
    stack.Push(10);
    stack.Push(15);

    stack.Pop();
    EXPECT_EQ(stack.Top(), 10);
    EXPECT_EQ(stack.Size(), 2);

    stack.Pop();
    EXPECT_EQ(stack.Top(), 5);
    EXPECT_EQ(stack.Size(), 1);

    stack.Pop();
    EXPECT_TRUE(stack.IsEmpty());
}

TEST(MyStackTest, DifferentTypes)
{
    MyStack<std::string> stringStack;
    stringStack.Push("Hello");
    stringStack.Push("World");
    EXPECT_EQ(stringStack.Top(), "World");

    MyStack<double> doubleStack;
    doubleStack.Push(3.14);
    doubleStack.Push(2.71);
    EXPECT_DOUBLE_EQ(doubleStack.Top(), 2.71);
}

TEST(MyStackTest, MoveSemantics)
{
    MyStack<std::string> stack;
    std::string str = "TestString";
    stack.Push(std::move(str));
    EXPECT_TRUE(str.empty());
    EXPECT_EQ(stack.Top(), "TestString");
}

TEST(MyStackTest, ConstTop)
{
    MyStack<int> stack;
    stack.Push(42);

    const MyStack<int> &constStack = stack;
    EXPECT_EQ(constStack.Top(), 42);

    stack.Push(84);
    EXPECT_EQ(constStack.Top(), 84);
}

TEST(MyStackTest, EmptyStackOperations)
{
    MyStack<int> stack;

    EXPECT_THROW(stack.Pop(), std::out_of_range);

    EXPECT_THROW(stack.Top(), std::out_of_range);

    const MyStack<int> &constStack = stack;
    EXPECT_THROW(constStack.Top(), std::out_of_range);
}

TEST(MyStackTest, TopModification)
{
    MyStack<int> stack;
    stack.Push(10);

    stack.Top() = 20;
    EXPECT_EQ(stack.Top(), 20);
}

#include "MyVector.hpp"
TEST(MyStackTest, CustomContainer)
{
    MyStack<std::string, MyVector> stack;
    stack.Push("CustomContainerTest");

    EXPECT_EQ(stack.Top(), "CustomContainerTest");
    EXPECT_EQ(stack.Size(), 1);
    EXPECT_FALSE(stack.IsEmpty());
}