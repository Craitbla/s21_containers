#ifndef S21STACK_H
#define S21STACK_H

#include "../s21_list/s21_list.h"

namespace s21 {
template <class T> class Stack : private List<T> {
public:
  using value_type = T;
  using reference = T &;
  using const_reference = const T &;
  using size_type = size_t;

  Stack() : List<T>() {}
  Stack(std::initializer_list<value_type> const &items) : List<T>(items) {}
  Stack(const Stack &s) : List<T>(s) {}
  Stack(Stack &&s) : List<T>(std::move(s)) {}

  Stack &operator=(const Stack &s) {
    List<T>::operator=(s);
    return *this;
  }

  Stack &operator=(Stack &&s) {
    List<T>::operator=(std::move(s));
    return *this;
  }

  const_reference top() { return List<T>::back(); }

  bool empty() { return List<T>::empty(); };

  size_type size() { return List<T>::size(); };

  void push(const_reference value) { List<T>::push_back(value); };

  void pop() {
    if (empty()) {
      throw std::out_of_range("Stack is empty");
    } else
      List<T>::pop_back();
  };

  void swap(Stack &other) { List<T>::swap(other); };

  template <class... Args> void insert_many_back(Args &&...args) {
    List<T>::insert_many_back(args...);
  }
};
} // namespace s21

#endif // S21STACK_H