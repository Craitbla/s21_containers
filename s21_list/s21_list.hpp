#ifndef S21_LIST_HPP
#define S21_LIST_HPP

namespace s21 {

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

template <typename T> List<T> &List<T>::operator=(const List &l) {
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

template <typename T> List<T> &List<T>::operator=(List &&l) noexcept {
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

template <class T> const T &List<T>::front() { return this->begin_->data_; }

template <class T> const T &List<T>::back() {
  if (size_ != 0) {
    return this->end_->prev_->data_;
  } else {
    return this->begin_->data_;
  }
}

template <class T> void List<T>::clear_del() {
  (*this).clear();
  if (end_ != nullptr) {
    delete end_;
    end_ = nullptr;
    begin_ = nullptr;
  }
}

template <class T> void List<T>::clear() {
  while (!(*this).empty()) {
    this->pop_front();
  }
}

template <class T> typename List<T>::const_iterator List<T>::cbegin() {
  const_iterator it;
  it.p_node_ = this->begin_;
  return it;
}

template <class T> typename List<T>::const_iterator List<T>::cend() {
  const_iterator it;
  it.p_node_ = this->end_;
  return it;
}

template <class T> typename List<T>::iterator List<T>::begin() {
  iterator it;
  it.p_node_ = this->begin_;
  return it;
}

template <class T> typename List<T>::iterator List<T>::end() {
  iterator it;
  it.p_node_ = this->end_;
  return it;
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

template <class T> void List<T>::erase(iterator pos) {
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
      end_->prev_ = nullptr;
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

#endif // S21_LIST_HPP