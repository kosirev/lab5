#ifndef INCLUDE_HEADER_HPP_
#define INCLUDE_HEADER_HPP_
#include <memory>
#include <iostream>
#include <string>

template <typename T>
class Node
{
 public:
  Node(T data_ = T(), Node<T> *pPast_ = nullptr) {
    data = data_;
    pPast = pPast_;
  }

  const T& get_data(){return data;}

  Node<T>*& get_pointer_past(){return pPast;}
 private:
  Node<T> *pPast;
  T data;
};

template <typename T>
class Stack1 {
 private:
  struct Node {
    explicit Node(T data_ = T(), Node *pPast_ = nullptr) {
      data = data_;
      pPast = pPast_;
    }

    Node *pPast;
    T data;
  }* pHead;

 public:
  void push(T &value) {
    pHead = new Node(std::move(value), std::move(pHead));
  };
  void push(const T &&value) {
    pHead = new Node(value, std::move(pHead));
  };

  void pop() {
    Node *pTemp = pHead->pPast;
    delete pHead;
    pHead = pTemp;
  };

  [[nodiscard]] T &head() const { return pHead->data; };

  Stack1() : pHead{} {}

  explicit Stack1(const T &value) : pHead{new Node(value)} {}

  explicit Stack1(T &&value) : pHead{new Node(std::move(value))} {}

  Stack1(const Stack1 &) = delete;

  Stack1 operator=(const Stack1 &) = delete;

  ~Stack1() {
    while (pHead) {
      pop();
    }
  }
};
#endif // INCLUDE_HEADER_HPP_