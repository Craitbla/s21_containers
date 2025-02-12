#ifndef S21_AUXILIARY_METHODS_HPP
#define S21_AUXILIARY_METHODS_HPP

namespace s21 {

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

} // namespace s21

#endif // S21_AUXILIARY_METHODS_HPP