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

  List &operator=(List &&l) noexcept {
    if (this != &l) {
      if (!(*this).empty() || this->end_ != nullptr) {
        clear_del();
      }
      this->size_ = l.size_;
      this->begin_ = l.begin_;
      this->end_ = l.end_;
      l.begin_ = nullptr;
      l.end_ = nullptr;
      l.size_ = 0;
    }
    return *this;
  }
  List &operator=(const List &l) {
    (*this).clear();
    node<T> *cur_node = l.begin_;
    if (this->end_ == nullptr) {
      this->end_ = new node<T>();
    }
    for (size_type i = 0; i < l.size_; i++) {
      (*this).push_back(cur_node->data_);
      cur_node = cur_node->next_;
    }
    return *this;
  }

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

  template <class value_type>
  class ListIterator : public ListConstIterator<value_type> {
    using iterator = ListIterator<value_type>;

  public:
    using ListConstIterator<T>::ListConstIterator;

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

  const_iterator cbegin() {
    const_iterator it;
    it.p_node_ = this->begin_;
    return it;
  }

  const_iterator cend() {
    const_iterator it;
    it.p_node_ = this->end_;
    return it;
  }

  iterator begin() {
    iterator it;
    it.p_node_ = this->begin_;
    return it;
  }

  iterator end() {
    iterator it;
    it.p_node_ = this->end_;
    return it;
  }

  bool empty();
  size_type size() { return size_; };
  size_type max_size();

  void clear_del();
  void clear();

  bool check_iterator_membership_to_list(const_iterator pos);

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

  // bool iterator_apply(iterator it);
  void swap_nodes_by_iterators(iterator &it_a, iterator &it_b,
                               bool iterator_remain_flag);
  void swap_beg_and_com(iterator &it_beg, iterator &it_com);
  void swap_com_and_com(iterator &it_com_a, iterator &it_com_b);
  void swap_com_neighboring(iterator &it_com_a, iterator &it_com_b);
};

template <class T> void List<T>::defoult() {
  begin_ = new node<value_type>();
  end_ = begin_;
  size_ = 0;
}

template <class T> List<T>::List() { (*this).defoult(); }

template <class T> List<T>::List(size_type n) {
  (*this).defoult();
  if (n > 0) {

    for (size_type i = 0; i < n; i++) {
      (*this).push_back(0);
    }
  }
}

template <class T>
List<T>::List(std::initializer_list<value_type> const &items) {
  (*this).defoult();
  if (items.size() > 0) {
    for (auto i = items.begin(); i != items.end(); i++) {
      (*this).push_back(*i);
    }
  }
}

template <class T> List<T>::List(const List &l) {
  (*this).defoult();
  (*this) = l;
}

template <class T> List<T>::List(List &&l) {
  this->size_ = l.size_;
  this->begin_ = l.begin_;
  this->end_ = l.end_;
  l.begin_ = nullptr;
  l.end_ = nullptr;
  l.size_ = 0;
}

template <class T> List<T>::~List() { this->clear_del(); }

template <class T> const T &List<T>::front() { return this->begin_->data_; }

template <class T> const T &List<T>::back() {
  if (size_ != 0) {
    return this->end_->prev_->data_;
  } else {
    return this->begin_->data_;
  }
}

template <class T>
void List<T>::swap_nodes_by_iterators(iterator &it_a, iterator &it_b,
                                      bool iterator_remain_flag) {
  if (it_a == it_b) {
    return;
  }

  node<T> *node_a = it_a.p_node_;
  node<T> *node_b = it_b.p_node_;

  if (it_a == begin() || it_b == begin()) {
    if (it_a == begin()) {
      swap_beg_and_com(it_a, it_b);
    } else {
      swap_beg_and_com(it_b, it_a);
    }
  } else {
    swap_com_and_com(it_b, it_a);
  }

  if (iterator_remain_flag) {
    it_a.p_node_ = node_b;
    it_b.p_node_ = node_a;
  }
}

template <class T>
void List<T>::swap_beg_and_com(iterator &it_beg, iterator &it_com) {
  node<T> *n_beg = it_beg.p_node_;
  node<T> *n_com = it_com.p_node_;

  node<T> *beg_next = n_beg->next_;

  node<T> *com_prev = n_com->prev_;
  node<T> *com_next = n_com->next_;

  if (beg_next == n_com) {
    n_beg->prev_ = n_com;
    n_com->prev_ = nullptr;
    com_next->prev_ = n_beg;

    n_beg->next_ = com_next;
    n_com->next_ = n_beg;
  } else {
    n_beg->prev_ = com_prev;
    n_beg->next_ = com_next;
    beg_next->prev_ = n_com;

    n_com->next_ = beg_next;
    n_com->prev_ = nullptr;
    com_prev->next_ = n_beg;
    com_next->prev_ = n_beg;
  }

  (*this).begin_ = n_com;
}

template <class T>
void List<T>::swap_com_and_com(iterator &it_com_a, iterator &it_com_b) {
  node<T> *n_com_a = it_com_a.p_node_;
  node<T> *n_com_b = it_com_b.p_node_;

  node<T> *com_a_prev = n_com_a->prev_;
  node<T> *com_a_next = n_com_a->next_;

  if (com_a_next == n_com_b) {
    swap_com_neighboring(it_com_a, it_com_b);
  } else if (com_a_prev == n_com_b) {
    swap_com_neighboring(it_com_b, it_com_a);
  } else {
    node<T> *com_b_prev = n_com_b->prev_;
    node<T> *com_b_next = n_com_b->next_;

    com_a_prev->next_ = n_com_b;
    n_com_a->next_ = com_b_next;

    n_com_a->prev_ = com_b_prev;
    com_a_next->prev_ = n_com_b;

    com_b_prev->next_ = n_com_a;
    n_com_b->next_ = com_a_next;

    n_com_b->prev_ = com_a_prev;
    com_b_next->prev_ = n_com_a;
  }
}

template <class T>
void List<T>::swap_com_neighboring(iterator &it_com_a, iterator &it_com_b) {
  node<T> *n_com_a = it_com_a.p_node_;
  node<T> *n_com_b = it_com_b.p_node_;

  node<T> *com_a_prev = n_com_a->prev_;

  node<T> *com_b_next = n_com_b->next_;

  com_a_prev->next_ = n_com_b;
  n_com_a->next_ = com_b_next;
  n_com_b->next_ = n_com_a;

  n_com_a->prev_ = n_com_b;
  n_com_b->prev_ = com_a_prev;
  com_b_next->prev_ = n_com_a;
}

template <class T> void List<T>::clear_del() {
  (*this).clear();
  if (end_ != nullptr) {
    delete end_;
    end_ = nullptr;
  }
}

template <class T> void List<T>::clear() {
  while (!(*this).empty()) {
    this->pop_front();
  }
}

template <class T>
bool List<T>::check_iterator_membership_to_list(const_iterator pos) {
  bool check_flag = false;
  auto check_it = (*this).begin();
  for (size_type i{1}; i <= (*this).size() + 1; i++) {
    if (pos.p_node_ == check_it.p_node_) {
      check_flag = true;
    }
    check_it++;
  }
  return check_flag;
}

template <class T>
typename List<T>::iterator List<T>::insert(List<T>::iterator pos,
                                           const T &value) {
  if (!(*this).check_iterator_membership_to_list(pos)) {
    return pos;
  }

  iterator it;
  if (pos == (*this).begin()) {
    (*this).push_front(value);
    it = (*this).begin();
  } else if (pos == (*this).end()) {
    (*this).push_back(value);
    it = --((*this).end());
  } else {
    node<T> *prev_node = pos.p_node_->prev_;
    node<T> *new_node = new node<value_type>(value, prev_node, pos.p_node_);
    prev_node->next_ = new_node;
    pos.p_node_->prev_ = new_node;

    it.p_node_ = new_node;
    (*this).size_++;
  }
  pos.p_node_ = it.p_node_;
  return it;
}

template <class T> void List<T>::erase(iterator pos) { // доработка
  if ((*this).empty()) {
    throw "It is impossible to remove an element from an empty list";
  }
  if (!(*this).check_iterator_membership_to_list(pos))
    return;
  if (pos == (*this).begin()) {
    (*this).pop_front();
  } else if (pos == --(*this).end()) {
    (*this).pop_back();
  } else {
    node<T> *cur_node = this->begin_;
    while ((cur_node != pos.p_node_) && (cur_node != end_)) {
      cur_node = cur_node->next_;
    }
    if (cur_node != end_) {
      node<T> *next_node = cur_node->next_;
      node<T> *prev_node = cur_node->prev_;
      delete cur_node;
      next_node->prev_ = prev_node;
      prev_node->next_ = next_node;

      (*this).size_--;
    }
  }
}

template <class T> bool List<T>::empty() { return (begin_ == end_); }

template <class T> size_t List<T>::max_size() {
  constexpr auto max_size = std::numeric_limits<std::size_t>::max();
  return max_size / sizeof(T) / 2;
}

template <class T> void List<T>::push_front(const_reference value) {
  if (!(*this).empty()) {
    node<T> *new_node = new node<value_type>(value, nullptr, begin_);
    begin_ = new_node;
    begin_->next_->prev_ = new_node;
  } else {
    begin_ = new node<value_type>(value, nullptr, end_);
    end_->prev_ = begin_;
  }
  size_++;
}

template <class T> void List<T>::push_back(const_reference value) {
  if (!(*this).empty()) {
    node<T> *new_node = new node<value_type>(value, end_->prev_, end_);
    end_->prev_->next_ = new_node;
    end_->prev_ = new_node;
  } else {
    begin_ = new node<value_type>(value, nullptr, end_);
    end_->prev_ = begin_;
  }
  size_++;
}

template <class T> void List<T>::pop_front() {
  if (!(*this).empty()) {
    if (begin_->next_ != end_) {
      node<T> *new_beg = this->begin_->next_;
      new_beg->prev_ = nullptr;
      delete begin_;
      begin_ = new_beg;
    } else {
      delete begin_;
      begin_ = end_;
      end_->prev_ = nullptr; ///
    }
    size_--;
  }
}

template <class T> void List<T>::pop_back() {
  if (!(*this).empty()) {
    if (begin_->next_ != end_) {
      node<T> *new_pen = this->end_->prev_->prev_;
      delete new_pen->next_;
      new_pen->next_ = end_;
      end_->prev_ = new_pen;
    } else {
      delete begin_;
      begin_ = end_;
      end_->prev_ = nullptr;
    }
    size_--;
  }
}

template <class T> void List<T>::swap(List &other) {
  std::swap(size_, other.size_);
  std::swap(begin_, other.begin_);
  std::swap(end_, other.end_);
}

template <class T> void List<T>::merge(List &other) {
  splice(begin(), other);
  sort();
}

// template <class T> bool List<T>::iterator_apply(iterator it) {
//   bool flag = 0;
//   node<T> *tmp_node = this->begin_;
//   while ((tmp_node != it.p_node_) && (tmp_node != nullptr)) {
//     tmp_node = tmp_node->next_;
//   }
//   if (tmp_node != nullptr) {
//     flag = 1;
//   }
//   return flag;
// }

template <class T> void List<T>::splice(const_iterator pos, List &other) {
  if (!(*this).check_iterator_membership_to_list(pos))
    return;
  if (!other.empty()) {
    node<T> *next_node = this->begin_;
    while ((next_node != pos.p_node_) && (next_node != nullptr)) {
      next_node = next_node->next_;
    }
    if (next_node != nullptr) {
      node<T> *other_beg = other.begin_;
      node<T> *other_end = other.end_->prev_;
      if (next_node == begin_) {
        next_node->prev_ = other_end;
        other_end->next_ = next_node;
        begin_ = other_beg;

        other.end_->prev_ = nullptr;

        delete other.end_;
        other.end_ = nullptr;
        other.begin_ = nullptr;

      } else if (next_node == end_) {
        node<T> *prev_node = next_node->prev_;
        prev_node->next_ = other_beg;
        other_beg->prev_ = prev_node;
        end_ = other.end_;

      } else {
        node<T> *prev_node = next_node->prev_;

        prev_node->next_ = other_beg;
        next_node->prev_ = other_end;

        other_beg->prev_ = prev_node;
        other_end->next_ = next_node;
      }
      (*this).size_ += other.size_;
      other.end_ = nullptr;
      other.begin_ = nullptr;

      other.size_ = 0;
    }
  }
}

template <class T> void List<T>::reverse() {
  if (size_ > 1) {
    iterator it_a = begin();
    iterator it_b = end();
    it_b--;
    for (size_type i = 0; i < size_ / 2; i++) {
      swap_nodes_by_iterators(it_a, it_b, 1);
      if (i != size_ / 2 - 1) {
        it_a++;
        it_b--;
      }
    }
  }
}

template <class T> void List<T>::unique() {
  if (size_ > 1) {
    iterator cur_it, next_it;
    cur_it.p_node_ = this->begin_;
    next_it.p_node_ = this->begin_->next_;
    while (next_it != end()) {
      if (cur_it.p_node_->data_ == next_it.p_node_->data_) {
        erase(cur_it);
      }
      cur_it = next_it;
      next_it++;
    }
  }
}

template <class T> void List<T>::sort() {
  for (int dist = size_ / 2; dist > 0; dist /= 2) {
    iterator i = begin();
    i.advance(dist);
    i++;
    for (; i.p_node_ != nullptr; ++i) {
      iterator j = i;
      j--;
      iterator tmp_it = j;
      tmp_it.advance(-dist);

      while (j.check_advance(-dist) &&
             j.p_node_->data_ < tmp_it.p_node_->data_) {
        swap_nodes_by_iterators(j, tmp_it, 1);
        j = tmp_it;
        tmp_it.advance(-dist);
      }
    }
  }
}

template <class T>
template <class... Args>
typename List<T>::iterator List<T>::insert_many(const_iterator pos,
                                                Args &&...args) {
  iterator ret_it;
  ret_it.p_node_ = pos.p_node_;
  if constexpr (sizeof...(args) > 0) {
    if (check_iterator_membership_to_list(pos)) {
      iterator pos_it;
      pos_it.p_node_ = pos.p_node_;
      bool flag_beg = true;
      for (const auto &arg : {std::forward<Args>(args)...}) {
        insert(pos_it, arg);
        if (flag_beg == true) {
          ret_it.p_node_ = pos_it.p_node_;
          ret_it--;
          flag_beg = false;
        }
      }
    }
  }
  return ret_it;
}

template <class T>
template <class... Args>
void List<T>::insert_many_back(Args &&...args) {
  if constexpr (sizeof...(args) > 0) {
    for (const auto &arg : {std::forward<Args>(args)...}) {
      push_back(arg);
    }
  }
}

template <class T>
template <class... Args>
void List<T>::insert_many_front(Args &&...args) {
  if constexpr (sizeof...(args) > 0) {
    for (const auto &arg : {std::forward<Args>(args)...}) {
      push_front(arg);
    }
  }
}

} // namespace s21

#endif // S21LIST_H