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

  template <class value_type> class ListConstIterator {
    using const_iterator = ListConstIterator<value_type>;

  public:
    node<T> *p_node_ = nullptr;
    ListConstIterator() = default;
    ~ListConstIterator() { p_node_ = nullptr; }

    value_type &operator*() const { return p_node_->data_; }

    const_iterator &operator++() {
      p_node_ = p_node_->next_;
      return *this;
    }
    const_iterator operator++(int) {
      const_iterator temp = *this;
      ++(*this);
      return temp;
    }

    const_iterator &operator--() {
      p_node_ = p_node_->prev_;
      return *this;
    }
    const_iterator operator--(int) {
      const_iterator temp = *this;
      --(*this);
      return temp;
    }

    bool equal(const_iterator &other) const {
      return other.p_node_ == (*this).p_node_;
    };

    bool operator==(const_iterator other) const { return (*this).equal(other); }

    bool operator!=(const_iterator other) const {
      return !(*this).equal(other);
    }
  };
  using const_iterator = ListConstIterator<value_type>;

  //////

  template <class value_type>
  class ListIterator : public ListConstIterator<value_type> { // наследует
    using iterator = ListIterator<value_type>;

  public:
    iterator &operator=(const_iterator &it) {
      (*this).p_node_ = it.p_node_;
      return *this;
    }

    iterator operator-(int dist) {
      iterator result = *this;
      for (int i = 0; i < dist; ++i) {
        if (result.p_node_->prev_) {
          result.p_node_ = result.p_node_->prev_;
        } else {
          break;
        }
      }
      return result;
    }

    bool check_advance_with_change(int dist) {
      bool flag = 1;
      if (dist > 0) {
        for (int i = 0; (i < dist) && ((*this).p_node_->next_ != nullptr);
             i++) {
          ++(*this);
          if ((*this).p_node_->next_ == nullptr) {
            flag = 0;
          }
        }
      } else {
        for (int i = 0; (i < -dist) && !(((*this).p_node_->prev_ == nullptr) &&
                                         (i <= -dist - 1));
             i++) {
          --(*this);
          if (((*this).p_node_->prev_ == nullptr) && (i < -dist - 1)) {
            flag = 0;
          }
        }
      }
      return flag;
    }

    bool check_advance(int dist) {
      node<T> *temp_node = (*this).p_node_;
      bool flag = (*this).check_advance_with_change(dist);
      (*this).p_node_ = temp_node;
      return flag;
    }

    bool advance(int dist) {
      node<T> *temp_node = (*this).p_node_;
      bool flag = (*this).check_advance_with_change(dist);
      if (flag == 0) {
        (*this).p_node_ = temp_node;
      }
      return flag;
    };
  };

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

#include "s21_list.hpp"

#include "s21_iterators.hpp"

#include "s21_auxiliary_methods.hpp"

#endif // S21LIST_H