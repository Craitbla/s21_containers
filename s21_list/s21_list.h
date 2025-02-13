#ifndef S21LIST_H
#define S21LIST_H

#include <iostream>
#include <limits>
#include <utility>

namespace s21 {

template <class T> class List {

  using value_type = T;
  using reference = T &;
  using const_reference = const T &;
  using size_type = size_t;

private:
  template <class value_type> class node {
  public:
    value_type data_;
    node *prev_ = nullptr;
    node *next_ = nullptr;
    node() = default;
    node(value_type data) : data_(data) {}

    node(value_type data, node *prev) : data_(data), prev_(prev) {}

    node(value_type data, node *prev, node *next)
        : data_(data), prev_(prev), next_(next) {}
    node(node &&n) {
      data_ = std::exchange(n.data_, 0);
      prev_ = std::exchange(n.prev_, nullptr);
      next_ = std::exchange(n.next_, nullptr);
    }
    ~node() {
      prev_ = nullptr;
      next_ = nullptr;
    }
  };

  node<value_type> *begin_;
  node<value_type> *end_;
  size_type size_;

public:
  void defoult();
  List();
  List(size_type n);
  List(std::initializer_list<value_type> const &items);
  List(const List &l);
  List(List &&l);
  ~List();

  List &operator=(const List &l);
  List &operator=(List &&l) noexcept;

  const_reference front();
  const_reference back();

  template <class value_type> class ListConstIterator;
  template <class value_type> class ListIterator;
  using const_iterator = ListConstIterator<value_type>;
  using iterator = ListIterator<value_type>;

  const_iterator cbegin();
  const_iterator cend();
  iterator begin();
  iterator end();

  bool empty();
  size_type size() { return size_; };
  size_type max_size();

  void clear_del();
  void clear();

  iterator insert(iterator pos, const_reference value);
  void erase(iterator pos);
  void push_back(const_reference value);
  void pop_back();
  void push_front(const_reference value);
  void pop_front();
  void swap(List &other);
  void merge(List &other);
  void splice(const_iterator pos, List &other);
  void reverse();
  void unique();
  void sort();

  template <class... Args>
  iterator insert_many(const_iterator pos, Args &&...args);
  template <class... Args> void insert_many_back(Args &&...args);
  template <class... Args> void insert_many_front(Args &&...args);

  bool check_iterator_membership_to_list(const_iterator pos);
  void swap_nodes_by_iterators(iterator &it_a, iterator &it_b,
                               bool iterator_remain_flag);
  void swap_beg_and_com(iterator &it_beg, iterator &it_com);
  void swap_com_and_com(iterator &it_com_a, iterator &it_com_b);
  void swap_com_neighboring(iterator &it_com_a, iterator &it_com_b);
};

} // namespace s21

#include "s21_auxiliary_methods.hpp"
#include "s21_iterators.hpp"
#include "s21_list.hpp"

#endif // S21LIST_H