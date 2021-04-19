#include <gtest/gtest.h>
#include <Stack2.hpp>

TEST(Stack2, correct_primitive) {
  Stack2<int> stack;
  stack.push(10);
  int value1 = 15, value2 = 33;
  stack.push_emplace(value1);
  EXPECT_EQ(value1, stack.pop());
  EXPECT_EQ(10, stack.head());
  stack.push_emplace(value2);
  EXPECT_EQ(value2, stack.head());
  stack.push(1200);
  EXPECT_EQ(1200, stack.head());
}

class My_class {
 public:
  My_class() {
    value_i = 0;
    value_f = 0.1;
    value_s = "0";
  }
  My_class(int a, double b, std::string c){
    value_i = a;
    value_f = b;
    value_s = c;
  }
  int value_i;
  double value_f;
  std::string value_s;
};

TEST(Stack2, correct_my_class) {
  Stack2<My_class> stack;
  My_class my_class1;
  My_class my_class2(15, 1.1, "1");
  stack.push_emplace(my_class1);
  EXPECT_EQ(my_class1.value_f, stack.head().value_f);
  EXPECT_EQ(my_class1.value_s, stack.head().value_s);
  EXPECT_EQ(my_class1.value_i, stack.head().value_i);
  stack.push_emplace(my_class2);
  EXPECT_EQ(my_class2.value_f, stack.head().value_f);
  EXPECT_EQ(my_class2.value_s, stack.head().value_s);
  EXPECT_EQ(my_class2.value_i, stack.pop().value_i);
  EXPECT_EQ(my_class1.value_f, stack.head().value_f);
  EXPECT_EQ(my_class1.value_s, stack.head().value_s);
  EXPECT_EQ(my_class1.value_i, stack.head().value_i);
}

TEST(Stack2, emplace) {
  Stack2<My_class> stack;
  int value_i = 5;
  double value_f = 5.5;
  std::string value_s = "Hi";
  stack.push_emplace(100, 10.1, "102");
  stack.push_emplace(value_i, value_f, value_s);
  EXPECT_EQ(value_i, stack.head().value_i);
  EXPECT_EQ(value_f, stack.head().value_f);
  EXPECT_EQ(value_s, stack.pop().value_s);
  EXPECT_EQ(100, stack.head().value_i);
  EXPECT_EQ(10.1, stack.head().value_f);
  EXPECT_EQ("102", stack.head().value_s);
}

TEST(Stack2, type_traits) {
  EXPECT_TRUE(std::is_move_constructible<int>::value);
  EXPECT_TRUE(std::is_move_assignable<int>::value);
  EXPECT_TRUE(std::is_move_constructible<My_class>::value);
  EXPECT_TRUE(std::is_move_assignable<My_class>::value);
}