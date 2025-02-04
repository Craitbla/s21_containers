
#include "s21_list.h"
#include "../s21_queue/s21_queue.h"
#include "../s21_stack/s21_stack.h"

#include <iostream>

#include <list>
#include <stack>
// using namespace s21;

// вначале тесты (база 52)

// потом инкапсуляция

// переделать ком в тестах

int main() {
  //это и начало и конец и один и тот же нулевой узел
  std::list<int> std_lst;
  auto it1 = std_lst.begin();
  auto it2 = std_lst.end();
  // it2++;
  if (it1 == it2) {

    std::cout << "ddddd\n";
  }
  // std::cout << "ddddd\n";
  // it++;
  // std::cout << *it;
  // std::cout << "ddddd\n";
  // it++;
  // std::cout << *it;

  // std::list<int> std_lst;
  // auto it = std_lst.begin();
  // std::cout << *it;

  // std::cout << "\n";
  // for (auto it = std_lst.begin(); it != std_lst.end(); it++) {
  //   std::cout << *it << "\t";
  // }
  // s21::List<int> s21_lst_first = {3, 6};
  // s21::List<int> s21_lst_second = {1, 5};
  // // std::list<int> std_lst_first = {3, 6};
  // // std::list<int> std_lst_second = {1, 5};
  // s21_lst_first.merge(s21_lst_second);
  // // std_lst_first.merge(std_lst_second);
  // // std::cout << "\n\n";
  // // ничегошеньки в секонд и все в ферст
  // for (auto it = s21_lst_first.begin(); it != s21_lst_first.end(); it++) {
  //   std::cout << *it << "\t";
  // }
  // std::cout << "\n";
  // for (auto it = s21_lst_second.begin(); it != s21_lst_second.end(); it++) {
  //   std::cout << *it << "\t";
  // }
  // for (auto it = std_lst_second.begin(); it != std_lst_second.end(); it++) {
  //   std::cout << *it << "\t";
  // }

  // std::list<int> std_lst_first = {1};
  // std::list<int> std_lst_second = {2, 3};
  // s21::List<int>::iterator s21_it = s21_lst_first.begin();
  // std::list<int>::iterator std_it = std_lst_first.begin();
  // s21_lst_first.splice(s21_it, s21_lst_second);
  // std_lst_first.splice(std_it, std_lst_second);

  // std::cout << "\n\n";

  // std::cout << copy_lst.front() << "\t" << std_copy.front() << "\n";
  // std::cout << copy_lst.back() << "\t" << std_copy.back() << "\n";
  // std::cout << s21_lst.empty() << "\t" << std_lst.empty() << "\n";

  // s21::List<int> copy_lst;
  // copy_lst = std::move(s21_lst);
  // std::list<int> std_copy;
  // std_copy = std::move(std_lst);

  // // s21::List<int> our_list = {1, 2, 3};
  // // auto it1 = our_list.begin();
  // // std::cout << *(it1);
  // // auto it2 = it1;
  // // std::cout << *(it1);
  // // std::cout << *(it2);
  // //

  // //
  // s21::List<int> our_list = {1};
  // std::list<int> std_list = {1};
  // s21::List<int>::iterator our_it;
  // our_it = our_list.begin();
  // our_it++;
  // std::list<int>::iterator std_it;
  // std_it = std_list.begin();
  // std_it++;
  // our_list.insert(our_it, 5);
  // std_list.insert(std_it, 5);
  // // for (auto it = our_list.begin(); it != our_list.end(); it++) {
  // //   std::cout << *it << "\t";
  // // }
  // // std::cout << "\n";
  // // for (auto it = std_list.begin(); it != std_list.end(); it++) {
  // //   std::cout << *it << "\t";
  // // }
  // std::cout << "\n\n";
  // std::cout << our_list.front() << "\t" << std_list.front() << "\n";
  // std::cout << our_list.back() << "\t" << std_list.back() << "\n";
  // // EXPECT_EQ(our_list.front(), std_list.front());
  // // EXPECT_EQ(our_list.back(), std_list.back());
  // our_list.insert(our_it, 7);
  // std_list.insert(std_it, 7);
  // our_list.insert(our_it, 9);
  // std_list.insert(std_it, 9);
  // std::cout << "\n\n";
  // // for (auto it = our_list.begin(); it != our_list.end(); it++) {
  // //   std::cout << *it << "\t";
  // // }
  // // std::cout << "\n";
  // // for (auto it = std_list.begin(); it != std_list.end(); it++) {
  // //   std::cout << *it << "\t";
  // // }
  // std::cout << "\n\n";
  //
  //
  //
  // std::cout << our_list.front() << "\t" << std_list.front() << "\n";
  // std::cout << our_list.back() << "\t" << std_list.back() << "\n";
  // EXPECT_EQ(our_list.front(), std_list.front());
  // EXPECT_EQ(our_list.back(), std_list.back());

  //
  //
  //
  // s21::List<int> our_list = {1, 2, 3};
  // std::list<int> std_list = {1, 2, 3};
  // s21::List<int> our_copy(std::move(our_list));
  // std::list<int> std_copy(std::move(std_list));
  // for (auto it = our_list.begin(); it != our_list.end(); it++) {
  //   std::cout << *it << "\t";
  // }

  // for (auto it = std_list.begin(); it != std_list.end(); it++) {
  //   std::cout << *it << "\t";
  // }

  // for (auto it = our_copy.begin(); it != our_copy.end(); it++) {
  //   std::cout << *it << "\t";
  // }

  // for (auto it = std_copy.begin(); it != std_copy.end(); it++) {
  //   std::cout << *it << "\t";
  // }

  // std::cout << our_copy.front() << "\t" << std_copy.front() << "\n";
  // std::cout << our_copy.back() << "\t" << std_copy.back() << "\n";
  // std::cout << our_list.empty() << "\t" << std_list.empty() << "\n";

  // // инсерт мени
  // List<int> lst1{1, 2};
  // lst1.print();
  // List<int>::const_iterator it1 = lst1.cbegin();

  // lst1.insert_many_front(100, 200);
  // lst1.print();
  // std::cout << "\n" << *it2 << "\n";

  // Stack<int> q1{1, 2, 3};
  // auto a = q1.top();

  // std::cout << a;
  // auto b = q1.back();

  // std::cout << "\n" << b;
  //
  //
  //
  // List<int> lst1{1, 5, 100}; // мердж
  // List<int> lst2{-3, 3, 50};

  // lst1.print();
  // lst2.print();

  // auto it = lst2.end();
  // it--;
  // std::cout << "\n" << *it << "\n";

  // lst1.merge(lst2);

  // lst1.print();
  // lst2.print();

  // std::cout << "\n" << *it << "\n";

  //
  //
  // List<int> lst1{8, 3, 5, 1, 6}; /// сорт

  // lst1.print();

  // auto it = lst1.end();
  // it--;
  // std::cout << "\n" << *it << "\n";

  // lst1.sort();

  // lst1.print();

  // std::cout << "\n" << *it << "\n";
  //
  //
  //
  // List<int> lst1{8, 3, 5, 1, 6}; // сплайс
  // List<int> lst2{100, 200};

  // lst1.print();

  // auto it = lst1.begin();

  // // auto it = lst1.end();
  // // it--;
  // std::cout << "\n" << *it << "\n";

  // lst1.splice(it, lst2);

  // lst1.print();

  // std::cout << "\n" << *it << "\n";
  //
  //
  //
  // List<int> lst1{1};

  // // List<int> lst1{1, 2, 3, 4, 5};

  // List<int> lst2{100, 200, 300};

  // std::cout << "ДО" << "\n";
  // lst1.print();

  // auto it = lst1.begin();
  // // it++;

  // lst1.push_front(100);

  // std::cout << "\n" << *it;

  // // lst1.splice(it, lst2);

  // std::cout << "\n" << "ПОСЛЕ" << "\n";
  // lst1.print();

  ////
  //
  ///

  // err = it.check_advance(-2);
  // std::cout << "\nэлемент итератора: " << *it << "\nerr: " << err;

  // std::cout << *(it1);

  ///////////////////////////

  // List<int> lst1;
  // lst1.push_back(1); // АВТО значения
  // lst1.push_back(2);
  // lst1.push_back(3);

  // std::cout << "size " << lst1.size() << endl;
  // std::cout << "lst1 " << endl;
  // lst1.print();

  // List<int> lst2;
  // lst2.push_back(5); // АВТО значения
  // lst2.push_back(4);
  // lst2.push_back(2);

  // std::cout << "size " << lst2.size() << endl;
  // std::cout << "lst2 " << endl;
  // lst2.print();

  // lst1.swap(lst2);

  // std::cout << "size после " << lst1.size() << endl;
  // std::cout << "lst1 после" << endl;
  // lst1.print();

  // std::cout << "size после " << lst2.size() << endl;
  // std::cout << "lst2 после" << endl;
  // lst2.print();

  return 0;
}
