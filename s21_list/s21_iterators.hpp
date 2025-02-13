#ifndef S21_ITERATORS_HPP
#define S21_ITERATORS_HPP

namespace s21 {

template <class T>
template <class value_type>
class List<T>::ListConstIterator {
public:
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

  bool operator!=(const_iterator other) const { return !(*this).equal(other); }
};

template <class T>
template <class value_type>
class List<T>::ListIterator : public List<T>::ListConstIterator<value_type> {
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
      for (int i = 0; (i < dist) && ((*this).p_node_->next_ != nullptr); i++) {
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

} // namespace s21

#endif // S21_ITERATORS_HPP
