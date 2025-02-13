#ifndef S21_ITERATORS_HPP
#define S21_ITERATORS_HPP

namespace s21 {

template <class T>
template <class value_type>
class List<T>::ListConstIterator {
public:
  using const_iterator = ListConstIterator<value_type>;
  node<T> *p_node_ = nullptr;

  ListConstIterator() = default;
  ~ListConstIterator();

  value_type &operator*() const;
  const_iterator &operator++();
  const_iterator operator++(int);
  const_iterator &operator--();
  const_iterator operator--(int);

  bool equal(const_iterator &other) const;
  bool operator==(const_iterator other) const;
  bool operator!=(const_iterator other) const;
};

template <class T>
template <class value_type>
class List<T>::ListIterator : public List<T>::ListConstIterator<value_type> {
  using iterator = ListIterator<value_type>;

public:
  iterator &operator=(const_iterator &it);
  iterator operator-(int dist);
  bool check_advance_with_change(int dist);
  bool check_advance(int dist);
  bool advance(int dist);
};

template <class T>
template <class value_type>
List<T>::ListConstIterator<value_type>::~ListConstIterator() {
  p_node_ = nullptr;
}

template <class T>
template <class value_type>
value_type &List<T>::ListConstIterator<value_type>::operator*() const {
  return p_node_->data_;
}

template <class T>
template <class value_type>
typename List<T>::template ListConstIterator<value_type> &
List<T>::ListConstIterator<value_type>::operator++() {
  p_node_ = p_node_->next_;
  return *this;
}

template <class T>
template <class value_type>
typename List<T>::template ListConstIterator<value_type>
List<T>::ListConstIterator<value_type>::operator++(int) {
  const_iterator temp = *this;
  ++(*this);
  return temp;
}

template <class T>
template <class value_type>
typename List<T>::template ListConstIterator<value_type> &
List<T>::ListConstIterator<value_type>::operator--() {
  p_node_ = p_node_->prev_;
  return *this;
}

template <class T>
template <class value_type>
typename List<T>::template ListConstIterator<value_type>
List<T>::ListConstIterator<value_type>::operator--(int) {
  const_iterator temp = *this;
  --(*this);
  return temp;
}

template <class T>
template <class value_type>
bool List<T>::ListConstIterator<value_type>::equal(
    const_iterator &other) const {
  return other.p_node_ == (*this).p_node_;
}

template <class T>
template <class value_type>
bool List<T>::ListConstIterator<value_type>::operator==(
    const_iterator other) const {
  return (*this).equal(other);
}

template <class T>
template <class value_type>
bool List<T>::ListConstIterator<value_type>::operator!=(
    const_iterator other) const {
  return !(*this).equal(other);
}

template <class T>
template <class value_type>
typename List<T>::template ListIterator<value_type> &
List<T>::ListIterator<value_type>::operator=(const_iterator &it) {
  (*this).p_node_ = it.p_node_;
  return *this;
}

template <class T>
template <class value_type>
typename List<T>::template ListIterator<value_type>
List<T>::ListIterator<value_type>::operator-(int dist) {
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

template <class T>
template <class value_type>
bool List<T>::ListIterator<value_type>::check_advance_with_change(int dist) {
  bool flag = 1;
  if (dist > 0) {
    for (int i = 0; (i < dist) && ((*this).p_node_->next_ != nullptr); i++) {
      ++(*this);
      if ((*this).p_node_->next_ == nullptr) {
        flag = 0;
      }
    }
  } else {
    for (int i = 0; (i < -dist) &&
                    !(((*this).p_node_->prev_ == nullptr) && (i <= -dist - 1));
         i++) {
      --(*this);
      if (((*this).p_node_->prev_ == nullptr) && (i < -dist - 1)) {
        flag = 0;
      }
    }
  }
  return flag;
}

template <class T>
template <class value_type>
bool List<T>::ListIterator<value_type>::check_advance(int dist) {
  node<T> *temp_node = (*this).p_node_;
  bool flag = (*this).check_advance_with_change(dist);
  (*this).p_node_ = temp_node;
  return flag;
}

template <class T>
template <class value_type>
bool List<T>::ListIterator<value_type>::advance(int dist) {
  node<T> *temp_node = (*this).p_node_;
  bool flag = (*this).check_advance_with_change(dist);
  if (flag == 0) {
    (*this).p_node_ = temp_node;
  }
  return flag;
}

} // namespace s21

#endif // S21_ITERATORS_HPP
