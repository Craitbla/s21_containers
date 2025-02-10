#ifndef S21QUEUE_H
#define S21QUEUE_H

#include "../s21_list/s21_list.h"

namespace s21 {

template <class T> class Queue : protected List<T> {
public:
  using value_type = T;
  using reference = T &;
  using const_reference = const T &;
  using size_type = size_t;

  Queue() : List<T>() {}
  Queue(std::initializer_list<value_type> const &items) : List<T>(items) {}
  Queue(const Queue &q) : List<T>(q) {}
  Queue(Queue &&q) : List<T>(std::move(q)) {}
  ~Queue() { List<T>::clear_del(); }

  Queue &operator=(const Queue &q) {
    List<T>::operator=(q);
    return *this;
  }
  Queue &operator=(Queue &&q) {
    List<T>::operator=(std::move(q));
    return *this;
  }

  const_reference front() { return List<T>::front(); }

  const_reference back() { return List<T>::back(); };

  bool empty() { return List<T>::empty(); };

  size_type size() { return List<T>::size(); };

  void push(const_reference value) { List<T>::push_back(value); };

  void pop() {
    if (empty()) {
      throw std::out_of_range("Queue is empty");
    } else
      List<T>::pop_front();
  };

  void swap(Queue &other) { List<T>::swap(other); };

  template <class... Args> void insert_many_back(Args &&...args) {
    List<T>::insert_many_back(args...);
  }
};

} // namespace s21

#endif // S21QUEUE_H