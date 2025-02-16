#include "../s21_queue/s21_queue.h"
#include "../s21_stack/s21_stack.h"
#include "s21_list.h"

#include <iostream>

#include <list>
#include <queue>
#include <stack>

// TEST(List, Insert_Check_Iterators_After_Func) {
//   s21::List<int> s21_lst{1, 2, 3};
//   std::list<int> std_lst{1, 2, 3};

//   s21::List<int>::iterator s21_it1 = s21_lst.begin();
//   s21::List<int>::iterator s21_it2 = s21_lst.begin();
//   s21_it2++;
//   s21::List<int>::iterator s21_it3 = s21_lst.begin();
//   s21_it3++;
//   s21_it3++;

//   std::list<int>::iterator std_it1 = std_lst.begin();
//   std::list<int>::iterator std_it2 = std_lst.begin();
//   std_it2++;
//   std::list<int>::iterator std_it3 = std_lst.begin();
//   std_it3++;
//   std_it3++;

//   s21::List<int>::iterator s21_new_it = s21_lst.insert(s21_it2, 5);
//   std::list<int>::iterator std_new_it = std_lst.insert(std_it2, 5);

//   EXPECT_EQ(*s21_new_it, *std_new_it);
//   EXPECT_EQ(*s21_it1, *std_it1);
//   EXPECT_EQ(*s21_it2, *std_it2);
//   EXPECT_EQ(*s21_it3, *std_it3);
// }
// using namespace s21;

// потом инкапсуляция

// переделать ком в тестах

// std::cout << "\n" << *(++std_lst.begin()) << *(++s21_lst.begin()) << "\n";
int main() {
  s21::List<int> s21_lst_first = {1, 2};
  s21::List<int> s21_lst_second = {4, 5, 6};
  // s21::List<int>::iterator s21_it = s21_lst_first.begin();
  s21::List<int>::iterator s21_it = s21_lst_first.end();
  // s21_it++;
  s21_lst_first.splice(s21_it, s21_lst_second);

  // s21::List<int>::iterator rez_it_check = rez_lst.begin();
  // for (auto s21_it_check = s21_lst1.begin(); s21_it_check !=
  //   s21_lst1.end();
  //      s21_it_check++) {
  //   std::cout << *rez_it_check << "\t" << *s21_it_check << "\n";
  //   rez_it_check++;
  // }

  //   std::list<int> std_lst = {1, 2, 3};
  //   auto it1 = s21_lst.begin();
  //   // it1++;
  //   auto it2 = std_lst.begin();
  //   // it2++;

  //   s21_lst.pop_front();
  //   std_lst.pop_front();

  //   // s21_lst.erase(it1);
  //   // std_lst.erase(it2);

  //   std::cout << *it1 << "\n" << *it2;

  // s21::Queue<int> s21_queue;
  // std::queue<int> std_queue;
  // bool a = s21_queue.empty();
  // bool b = std_queue.empty();
  // std::cout << a << "\t" << b << "\n";
  // ///////
  // s21::List<int> s21_lst1{1, 2};
  // s21::List<int> s21_lst2{10};
  // s21::List<int>::iterator s21_it2 = s21_lst2.begin();
  // s21::List<int>::iterator s21_new_it = s21_lst1.insert_many(s21_it2);
  // s21::List<int> rez_lst = {1, 2};

  // s21::List<int>::iterator rez_it_check = rez_lst.begin();
  // for (auto s21_it_check = s21_lst1.begin(); s21_it_check !=
  //   s21_lst1.end();
  //      s21_it_check++) {
  //   std::cout << *rez_it_check << "\t" << *s21_it_check << "\n";
  //   rez_it_check++;
  // }
  // std::cout << " \n\n\n" << *s21_new_it;
  // std::cout << " \n\n\n" <<
  // s21_lst1.check_iterator_membership_to_list(s21_it2);
  ///
  // std::cout << " \n\n\n" << *s21_it2 << " \n\n\n";
  // std::cout << *s21_new_it << " \n\n\n";
  // s21::List<int> s21_lst_first = {3, 8, 10};
  // s21::List<int> s21_lst_second = {-10, 1, 2, 6, 100};
  // std::list<int> std_lst_first = {3, 8, 10};
  // std::list<int> std_lst_second = {-10, 1, 2, 6, 100};
  // s21_lst_first.merge(s21_lst_second);
  // std_lst_first.merge(std_lst_second);

  // std::list<int>::iterator std_it_check = std_lst_first.begin();
  // for (auto s21_it_check = s21_lst_first.begin();
  //      s21_it_check != s21_lst_first.end(); s21_it_check++) {
  //   std::cout << *std_it_check << " \t" << *s21_it_check << " \t";

  //   std_it_check++;
  // }

  ////////
  // for (auto it = s21_lst1.begin(); it != s21_lst1.end(); it++) {
  //   std::cout << *it << " \t";
  // }
  // std::cout << "fffff \n\n\nsssss";
  // for (auto it = s21_lst2.begin(); it != s21_lst2.end(); it++) {
  //   std::cout << *it << " \t";
  // }

  // ДЛЯ ОБЫЧНОЙ ПРОВЕРКИ s21 и std
  //  s21::List<int> s21_lst = {1, 2, 3};
  //  std::list<int> std_lst = {1, 2, 3};
  //  s21::List<int>::iterator s21_it = s21_lst.end();
  //  --s21_it;
  //  std::list<int>::iterator std_it = std_lst.end();
  //  --std_it;
  //  s21_lst.erase(s21_it);
  //  std_lst.erase(std_it);
  //  for (auto it = s21_lst.begin(); it != s21_lst.end(); it++) {
  //    std::cout << *it << " \t";
  //  }
  //  for (auto it = std_lst.begin(); it != std_lst.end(); it++) {
  //    std::cout << *it << " \t";
  //  }
  //  это и начало и конец и один и тот же нулевой узел
  //  s21::List<int> s21_lst;

  // ДЛЯ splice
  //  try {
  //    s21::List<int> s21_lst_first = {1};
  //    s21::List<int> s21_lst_second = {2, 3, 4, 5};
  //    std::list<int> std_lst_first = {1};
  //    std::list<int> std_lst_second = {2, 3, 4, 5};
  //    s21::List<int>::iterator s21_it = s21_lst_first.begin();
  //    std::list<int>::iterator std_it = std_lst_first.begin();
  //    s21_lst_first.splice(s21_it, s21_lst_second);
  //    std_lst_first.splice(std_it, std_lst_second);
  //    for (auto it = s21_lst_first.begin(); it != s21_lst_first.end();
  //    it++)
  //    {
  //      std::cout << *it << " \t";
  //    }
  //    std::cout << "s21_lst_first\n";
  //    for (auto it = s21_lst_second.begin(); it != s21_lst_second.end();
  //    it++)
  //    {
  //      std::cout << *it << " \t";
  //    }
  //    std::cout << "s21_lst_second\n";

  //   for (auto it = std_lst_first.begin(); it != std_lst_first.end();
  //   it++)
  //   {
  //     std::cout << *it << " \t";
  //   }
  //   std::cout << "std_lst_first\n";
  //   for (auto it = std_lst_second.begin(); it != std_lst_second.end();
  //   it++)
  //   {
  //     std::cout << *it << " \t";
  //   }
  //   std::cout << "std_lst_second\n";
  // } catch (const char *error_message) {
  //   std::cout << error_message << std::endl;
  // }
  // std::cout << "The End..." << std::endl;

  // std::cout << "\n";
  // for (auto it = std_lst.begin(); it != std_lst.end(); it++) {
  //   std::cout << *it << "\t";
  // }

  return 0;
}
