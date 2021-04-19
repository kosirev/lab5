
#ifndef LAB_05_STACK_STACK2_H
#define LAB_05_STACK_STACK2_H
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
class Stack2
{
 public:
  template <typename ... Args>
  void push_emplace(Args&&... value){
    if (!pHead){
      pHead = new Node<T>(T(std::forward<Args>(value)...));
    } else {
      pHead = new Node<T>(T(std::forward<Args>(value)...), pHead);
    }
  }
  void push(T&& value){
    if (!pHead){
      pHead = new Node<T>(std::forward<T>(value));
    } else {
      pHead = new Node<T>(std::forward<T>(value), std::forward<Node<T>*>(pHead));
    }
  };
  const T& head() const{return pHead->get_data();};
  T pop(){
    Node<T> *pTemp = pHead->get_pointer_past();
    T out = pHead->get_data();
    delete pHead;
    pHead = pTemp;
    return out;
  };

  Stack2(){pHead = nullptr;}
  Stack2(const Stack2&) = delete;
  Stack2 operator=(const Stack2&) = delete;
  ~Stack2(){
    while (pHead){
      pop();
    }
  }

 private:
  Node<T> *pHead;
};
#endif  // LAB_05_STACK_STACK2_H