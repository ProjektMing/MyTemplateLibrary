#include "MyList.hpp"
#include <gtest/gtest.h>

TEST(MyListTest, Constructor)
{
    MyList<int> list;
    EXPECT_TRUE(list.IsEmpty());
    EXPECT_EQ(list.Size(), 0);
}

TEST(MyListTest, CopyConstructor)
{
    MyList<int> list1;
    list1.PushBack(1);
    list1.PushBack(2);
    MyList<int> list2(list1);
    EXPECT_EQ(list2.Size(), 2);
    EXPECT_EQ(list2.Front(), 1);
    EXPECT_EQ(list2.Back(), 2);
}

TEST(MyListTest, MoveConstructor)
{
    MyList<int> list1;
    list1.PushBack(1);
    list1.PushBack(2);
    MyList<int> list2(std::move(list1));
    EXPECT_EQ(list2.Size(), 2);
    EXPECT_EQ(list2.Front(), 1);
    EXPECT_EQ(list2.Back(), 2);
    EXPECT_TRUE(list1.IsEmpty());
}

TEST(MyListTest, AssignmentOperator)
{
    MyList<int> list1;
    list1.PushBack(1);
    list1.PushBack(2);
    MyList<int> list2;
    list2 = list1;
    EXPECT_EQ(list2.Size(), 2);
    EXPECT_EQ(list2.Front(), 1);
    EXPECT_EQ(list2.Back(), 2);
}

TEST(MyListTest, MoveAssignmentOperator)
{
    MyList<int> list1;
    list1.PushBack(1);
    list1.PushBack(2);
    MyList<int> list2;
    list2 = std::move(list1);
    EXPECT_EQ(list2.Size(), 2);
    EXPECT_EQ(list2.Front(), 1);
    EXPECT_EQ(list2.Back(), 2);
    EXPECT_TRUE(list1.IsEmpty());
}

TEST(MyListTest, PushFront)
{
    MyList<int> list;
    list.PushFront(1);
    EXPECT_FALSE(list.IsEmpty());
    EXPECT_EQ(list.Size(), 1);
    EXPECT_EQ(list.Front(), 1);
    list.PushFront(2);
    EXPECT_EQ(list.Size(), 2);
    EXPECT_EQ(list.Front(), 2);
}

TEST(MyListTest, MovePushFront)
{
    MyList<int> list;
    int value = 1;
    list.PushFront(std::move(value));
    EXPECT_FALSE(list.IsEmpty());
    EXPECT_EQ(list.Size(), 1);
    EXPECT_EQ(list.Front(), 1);
}

TEST(MyListTest, PushBack)
{
    MyList<int> list;
    list.PushBack(1);
    EXPECT_FALSE(list.IsEmpty());
    EXPECT_EQ(list.Size(), 1);
    EXPECT_EQ(list.Back(), 1);
    list.PushBack(2);
    EXPECT_EQ(list.Size(), 2);
    EXPECT_EQ(list.Back(), 2);
}

TEST(MyListTest, MovePushBack)
{
    MyList<int> list;
    int value = 1;
    list.PushBack(std::move(value));
    EXPECT_FALSE(list.IsEmpty());
    EXPECT_EQ(list.Size(), 1);
    EXPECT_EQ(list.Back(), 1);
}

TEST(MyListTest, PopFront)
{
    MyList<int> list;
    list.PushBack(1);
    list.PushBack(2);
    list.PopFront();
    EXPECT_EQ(list.Size(), 1);
    EXPECT_EQ(list.Front(), 2);
}

TEST(MyListTest, PopBack)
{
    MyList<int> list;
    list.PushBack(1);
    list.PushBack(2);
    list.PopBack();
    EXPECT_EQ(list.Size(), 1);
    EXPECT_EQ(list.Back(), 1);
}

TEST(MyListTest, Clear)
{
    MyList<int> list;
    list.PushBack(1);
    list.PushBack(2);
    list.Clear();
    EXPECT_TRUE(list.IsEmpty());
    EXPECT_EQ(list.Size(), 0);
}