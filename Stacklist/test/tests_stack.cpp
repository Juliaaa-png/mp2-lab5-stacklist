#include "gtest.h"
#include "../Stacklist/Stack.h"


TEST(Stack, can_create_stack)
{
    ASSERT_NO_THROW(Stack<int> a);
}

TEST(Stack, can_copy_the_stack)
{
    Stack<int> a;
    a.Push(3);
    ASSERT_NO_THROW(Stack<int> copy(a));
}
TEST(Stack, when_you_change_the_original_stack_the_copied_stack_does_not_change)
{
    Stack<int> a;
    a.Push(3);
    Stack<int> copy(a);
    copy.Pop();
    EXPECT_EQ(true, copy.Empty());
    EXPECT_EQ(3, a.Top());
}
TEST(Stack, can_assign_stacks_of_the_same_data_types)
{
    Stack<int> a;
    Stack<int> b;
    a.Push(5);
    a.Push(7);
    b.Push(3);
    ASSERT_NO_THROW(b = a);
    EXPECT_EQ(a.Pop(), b.Pop());
}

TEST(Stack, comparing_the_stack_with_itself_gives_the_truth)
{
    Stack<int> a;
    EXPECT_EQ(true, a == a);
}

TEST(Stack, comparing_the_same_stack_gives_the_truth)
{
    Stack<int> a;
    Stack<int> b;
    a.Push(3);
    b.Push(3);
    EXPECT_EQ(true, a == b);
}

TEST(Stack, comparing_different_stack_gives_the_lie)
{
    Stack<int> a;
    Stack<int> b;
    a.Push(0);
    b.Push(5);
    EXPECT_EQ(true, a!= b);
}
TEST(Stack, can_check_the_stack_for_emptiness)
{
    Stack<int> a;
    ASSERT_NO_THROW(a.Empty());
}
TEST(Stack, initially_the_stack_is_empty)
{
    Stack<int> a;
    EXPECT_EQ(true, a.Empty());
}
TEST(Stack, checking_for_the_emptiness_of_a_non_empty_stack_returns_false)
{
    Stack<int> a;
    a.Push(3);
    EXPECT_EQ(false, a.Empty());
}
TEST(Stack, can_add_an_item_to_an_incomplete_stack)
{
    Stack<int> a;
    ASSERT_NO_THROW(a.Push(3));
}
TEST(Stack, can_see_what_is_at_the_top_of_a_non_empty_stack)
{
    Stack<int> a;
    a.Push(3);
    ASSERT_NO_THROW(a.Top());
}
TEST(Stack, viewing_the_top_of_the_stack_does_not_change_the_state_of_the_stack)
{
    Stack<int> a;
    a.Push(3);
    int b = a.Top();
    EXPECT_EQ(b, a.Top());
}
TEST(Stack, cant_look_at_the_top_of_an_empty_stack)
{
    Stack<int> a;
    ASSERT_ANY_THROW(a.Top());
}
TEST(Stack, can_take_an_element_from_a_non_empty_non_empty_stack)
{
    Stack<int> a;
    a.Push(5);
    ASSERT_NO_THROW(a.Pop());
}
TEST(Stack, taking_an_element_from_the_stack_reduces_its_size_by_one)
{
    Stack<int> a;
    a.Push(5);
    a.Pop();
    EXPECT_EQ(true, a.Empty());
}
TEST(Stack, cant_take_an_element_from_an_empty_stack)
{
    Stack<int> a;
    ASSERT_ANY_THROW(a.Pop());
}