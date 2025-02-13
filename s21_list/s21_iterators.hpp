#ifndef S21_ITERATORS_HPP
#define S21_ITERATORS_HPP

namespace s21 {

// template <class T>
// template <class U>
// class List<T>::ListConstIterator {
//   using const_iterator = ListConstIterator<value_type>;

// public:
//   node<T> *p_node_ = nullptr;
//   ListConstIterator() = default;
//   ~ListConstIterator() { p_node_ = nullptr; }

//   value_type &operator*() const { return p_node_->data_; }

//   const_iterator &operator++() {
//     p_node_ = p_node_->next_;
//     return *this;
//   }
//   const_iterator operator++(int) {
//     const_iterator temp = *this;
//     ++(*this);
//     return temp;
//   }

//   const_iterator &operator--() {
//     p_node_ = p_node_->prev_;
//     return *this;
//   }
//   const_iterator operator--(int) {
//     const_iterator temp = *this;
//     --(*this);
//     return temp;
//   }

//   bool equal(const_iterator &other) const {
//     return other.p_node_ == (*this).p_node_;
//   };

//   bool operator==(const_iterator other) const { return (*this).equal(other);
//   }

//   bool operator!=(const_iterator other) const { return !(*this).equal(other);
//   }
// }

} // namespace s21

#endif // S21_ITERATORS_HPP