#ifndef S21_ITERATORS_HPP
#define S21_ITERATORS_HPP

namespace s21 {

template <class T> class List<T>::ListConstIterator {
public: ////
  using const_iterator = ListConstIterator;
  node *p_node_ = nullptr; /////

  ListConstIterator() = default;
  ~ListConstIterator();

  const value_type &operator*() const;
  const_iterator &operator++();
  const_iterator operator++(int);
  const_iterator &operator--();
  const_iterator operator--(int);

  bool equal(const_iterator &other) const;
  bool operator==(const const_iterator other) const;
  bool operator!=(const const_iterator other) const;
};

template <class T>
class List<T>::ListIterator : public List<T>::ListConstIterator {
  using iterator = ListIterator;

public:
  value_type &operator*();
  iterator &operator=(const_iterator &it);
  iterator operator-(int dist);
  bool check_advance_with_change(int dist);
  bool check_advance(int dist);
  bool advance(int dist);
};

template <class T> List<T>::ListConstIterator::~ListConstIterator() {
  p_node_ = nullptr;
}

template <class T> T const &List<T>::ListConstIterator::operator*() const {
  return p_node_->data_;
}

template <class T>
typename List<T>::ListConstIterator &List<T>::ListConstIterator::operator++() {
  p_node_ = p_node_->next_;
  return *this;
}

template <class T>
typename List<T>::ListConstIterator
List<T>::ListConstIterator::operator++(int) {
  const_iterator temp = *this;
  ++(*this);
  return temp;
}

template <class T>
typename List<T>::ListConstIterator &List<T>::ListConstIterator::operator--() {
  p_node_ = p_node_->prev_;
  return *this;
}

template <class T>
typename List<T>::ListConstIterator
List<T>::ListConstIterator::operator--(int) {
  const_iterator temp = *this;
  --(*this);
  return temp;
}

template <class T>
bool List<T>::ListConstIterator::equal(const_iterator &other) const {
  return other.p_node_ == (*this).p_node_;
}

template <class T>
bool List<T>::ListConstIterator::operator==(const_iterator other) const {
  return (*this).equal(other);
}

template <class T>
bool List<T>::ListConstIterator::operator!=(const_iterator other) const {
  return !(*this).equal(other);
}

template <class T> T &List<T>::ListIterator::operator*() {
  return this->p_node_->data_;
}

template <class T>
typename List<T>::ListIterator &
List<T>::ListIterator::operator=(const_iterator &it) {
  (*this).p_node_ = it.p_node_;
  return *this;
}

template <class T>
typename List<T>::ListIterator List<T>::ListIterator::operator-(int dist) {
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
bool List<T>::ListIterator::check_advance_with_change(int dist) {
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

template <class T> bool List<T>::ListIterator::check_advance(int dist) {
  node *temp_node = (*this).p_node_;
  bool flag = (*this).check_advance_with_change(dist);
  (*this).p_node_ = temp_node;
  return flag;
}

template <class T> bool List<T>::ListIterator::advance(int dist) {
  node *temp_node = (*this).p_node_;
  bool flag = (*this).check_advance_with_change(dist);
  if (flag == 0) {
    (*this).p_node_ = temp_node;
  }
  return flag;
}

} // namespace s21

#endif // S21_ITERATORS_HPP
