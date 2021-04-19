#include <gtest/gtest.h>
#include <Stack1.hpp>

TEST(Example, EmptyTest) {
  EXPECT_TRUE(true);
}

TEST(Stack1, correct_primitive) {
  Stack1<int> stack;
  stack.push(10);
  int value1 = 15, value2 = 33;
  stack.push(value1);
  EXPECT_EQ(value1, stack.head());
  stack.pop();
  EXPECT_EQ(10, stack.head());
  stack.push(value2);
  EXPECT_EQ(value2, stack.head());
  stack.push(1200);
  EXPECT_EQ(1200, stack.head());
}

class My_class {
 public:

  My_class(){
    value_i = 0;
    value_f = 0.1;
    value_s = "0";
  }
  int value_i;
  double value_f;
  std::string value_s;
};

TEST(Stack1, correct_my_class) {
  Stack1<My_class> stack;
  My_class my_class1;
  My_class my_class2;
  my_class2.value_i = 15;
  my_class2.value_s = "1";
  my_class2.value_f = 1.1;
  stack.push(my_class1);
  EXPECT_EQ(my_class1.value_f, stack.head().value_f);
  EXPECT_EQ(my_class1.value_s, stack.head().value_s);
  EXPECT_EQ(my_class1.value_i, stack.head().value_i);
  stack.push(my_class2);
  EXPECT_EQ(my_class2.value_f, stack.head().value_f);
  EXPECT_EQ(my_class2.value_s, stack.head().value_s);
  EXPECT_EQ(my_class2.value_i, stack.head().value_i);
  stack.pop();
  EXPECT_EQ(my_class1.value_f, stack.head().value_f);
  EXPECT_EQ(my_class1.value_s, stack.head().value_s);
  EXPECT_EQ(my_class1.value_i, stack.head().value_i);
}

TEST(Stack1, type_traits) {
  EXPECT_TRUE(std::is_move_constructible<int>::value);
  EXPECT_TRUE(std::is_move_assignable<int>::value);
  EXPECT_TRUE(std::is_move_constructible<My_class>::value);
  EXPECT_TRUE(std::is_move_assignable<My_class>::value);
}