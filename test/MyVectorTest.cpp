#include "MyVector.hpp"
#include <gtest/gtest.h>

TEST(MyVectorTest, Constructor)
{
    MyVector<int> vec;
    EXPECT_EQ(vec.Size(), 0);
    EXPECT_EQ(vec.GetCapacity(), 16);
    EXPECT_TRUE(vec.IsEmpty());
}

TEST(MyVectorTest, CopyConstructor)
{
    MyVector<int> vec1;
    vec1.Push(1);
    vec1.Push(2);
    vec1.Push(3);

    MyVector<int> vec2(vec1);
    EXPECT_EQ(vec2.Size(), 3);
    EXPECT_FALSE(vec2.IsEmpty());
    EXPECT_EQ(vec2[0], 1);
    EXPECT_EQ(vec2[1], 2);
    EXPECT_EQ(vec2[2], 3);
}

TEST(MyVectorTest, MoveConstructor)
{
    MyVector<int> vec1;
    vec1.Push(1);
    vec1.Push(2);
    vec1.Push(3);

    MyVector<int> vec2(std::move(vec1));
    EXPECT_EQ(vec2.Size(), 3);
    EXPECT_FALSE(vec2.IsEmpty());
    EXPECT_EQ(vec2[0], 1);
    EXPECT_EQ(vec2[1], 2);
    EXPECT_EQ(vec2[2], 3);

    EXPECT_EQ(vec1.Size(), 0);
    EXPECT_EQ(vec1.GetCapacity(), 0);
}

TEST(MyVectorTest, CopyAssignmentOperator)
{
    MyVector<int> vec1;
    vec1.Push(1);
    vec1.Push(2);
    vec1.Push(3);

    MyVector<int> vec2;
    vec2 = vec1;
    EXPECT_EQ(vec2.Size(), 3);
    EXPECT_FALSE(vec2.IsEmpty());
    EXPECT_EQ(vec2[0], 1);
    EXPECT_EQ(vec2[1], 2);
    EXPECT_EQ(vec2[2], 3);
}

TEST(MyVectorTest, MoveAssignmentOperator)
{
    MyVector<int> vec1;
    vec1.Push(1);
    vec1.Push(2);
    vec1.Push(3);

    MyVector<int> vec2;
    vec2 = std::move(vec1);
    EXPECT_TRUE(vec1.IsEmpty());
    EXPECT_EQ(vec2.Size(), 3);
    EXPECT_FALSE(vec2.IsEmpty());
    EXPECT_EQ(vec2[0], 1);
    EXPECT_EQ(vec2[1], 2);
    EXPECT_EQ(vec2[2], 3);

    EXPECT_EQ(vec1.Size(), 0);
    EXPECT_EQ(vec1.GetCapacity(), 0);
}

TEST(MyVectorTest, PushToAllocateAndClear)
{
    MyVector<int> vec;
    vec.Push(1);
    vec.Push(2);
    vec.Push(3);
    EXPECT_EQ(vec.Size(), 3);
    EXPECT_EQ(vec.GetCapacity(), 16);
    EXPECT_FALSE(vec.IsEmpty());
    for (int i = 4; i <= 18; i++)
    {
        vec.Push(i);
    }
    for (int i = 0; i < 18; i++)
    {
        EXPECT_EQ(vec[i], i + 1);
    }
    EXPECT_EQ(vec.Size(), 18);
    EXPECT_EQ(vec.GetCapacity(), 32);
    EXPECT_FALSE(vec.IsEmpty());
    vec.Clear();
    EXPECT_EQ(vec.Size(), 0);
    EXPECT_EQ(vec.GetCapacity(), 32);
    EXPECT_TRUE(vec.IsEmpty());
}

TEST(MyVectorTest, Pop)
{
    MyVector<int> vec;
    vec.Push(1);
    vec.Push(2);
    vec.Push(3);
    EXPECT_EQ(vec.Size(), 3);
    EXPECT_FALSE(vec.IsEmpty());
    vec.Pop();
    EXPECT_EQ(vec.Size(), 2);
    EXPECT_EQ(vec[0], 1);
    EXPECT_EQ(vec[1], 2);
    vec.Pop();
    EXPECT_EQ(vec.Size(), 1);
    EXPECT_EQ(vec[0], 1);
}

TEST(MyVectorTest, OutOfRangeAccess)
{
    MyVector<int> vec;
    vec.Push(1);
    vec.Push(2);
    vec.Push(3);
    EXPECT_EQ(vec.Size(), 3);
    EXPECT_FALSE(vec.IsEmpty());
    EXPECT_THROW(vec[3], std::out_of_range);
}

TEST(MyVectorTest, PushRValueReference)
{
    MyVector<std::string> vec;
    std::string str1 = "test1";
    std::string str2 = "test2";

    vec.Push(str1);
    EXPECT_EQ(vec[0], "test1");

    vec.Push(std::move(str2));
    EXPECT_EQ(vec[1], "test2");
    EXPECT_TRUE(str2.empty());
}

TEST(MyVectorTest, OperatorBracketModification)
{
    MyVector<int> vec;
    vec.Push(1);
    vec.Push(2);
    vec.Push(3);

    vec[1] = 42;
    EXPECT_EQ(vec[0], 1);
    EXPECT_EQ(vec[1], 42);
    EXPECT_EQ(vec[2], 3);
}

TEST(MyVectorTest, ConstOperatorBracket)
{
    MyVector<int> vec;
    vec.Push(1);
    vec.Push(2);
    vec.Push(3);

    const MyVector<int> &constVec = vec;
    EXPECT_EQ(constVec[0], 1);
    EXPECT_EQ(constVec[1], 2);
    EXPECT_EQ(constVec[2], 3);

    EXPECT_THROW(constVec[3], std::out_of_range);
}

TEST(MyVectorTest, MultipleClears)
{
    MyVector<int> vec;
    vec.Push(1);
    vec.Push(2);

    vec.Clear();
    EXPECT_EQ(vec.Size(), 0);
    EXPECT_TRUE(vec.IsEmpty());

    vec.Clear();
    EXPECT_EQ(vec.Size(), 0);
    EXPECT_TRUE(vec.IsEmpty());

    vec.Push(3);
    EXPECT_EQ(vec.Size(), 1);
    EXPECT_EQ(vec[0], 3);
}

TEST(MyVectorTest, EdgeCases)
{
    MyVector<int> vec;

    EXPECT_THROW(vec.Pop(), std::out_of_range);

    vec.Push(1);
    EXPECT_EQ(vec.Size(), 1);
    vec.Pop();
    EXPECT_EQ(vec.Size(), 0);
    EXPECT_TRUE(vec.IsEmpty());

    for (int i = 0; i < 100; i++)
    {
        vec.Push(i);
    }
    EXPECT_EQ(vec.Size(), 100);
    for (int i = 0; i < 100; i++)
    {
        EXPECT_EQ(vec[i], i);
    }
}

TEST(MyVectorTest, LargeCapacityGrowth)
{
    MyVector<int> vec;

    size_t initialCapacity = vec.GetCapacity();

    for (size_t i = 0; i < initialCapacity; i++)
    {
        vec.Push(static_cast<int>(i));
    }
    EXPECT_EQ(vec.GetCapacity(), initialCapacity);

    vec.Push(100);
    EXPECT_EQ(vec.GetCapacity(), initialCapacity * 2);
    EXPECT_EQ(vec.Size(), initialCapacity + 1);
}