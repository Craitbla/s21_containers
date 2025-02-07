// #ifndef TESTLISTCONTEINERS_H
// #define TESTLISTCONTEINERS_H
#include <gtest/gtest.h>

#include "testListConteiners.h"

#include <list>

TEST(List, Constructor_Default) {
  s21::List<int> s21_lst;
  std::list<int> std_lst;
  EXPECT_EQ(s21_lst.empty(), std_lst.empty());
  EXPECT_EQ(s21_lst.size(), std_lst.size());
}

TEST(List, Constructor_Size) {
  s21::List<int> s21_lst(8);
  std::list<int> std_lst(8);
  EXPECT_EQ(s21_lst.size(), std_lst.size());
}

TEST(List, Constructor_Zeroes) {
  s21::List<int> s21_lst(2);
  std::list<int> std_lst(2);
  EXPECT_EQ(s21_lst.front(), std_lst.front());
}

TEST(List, Constructor_List) {
  s21::List<int> s21_lst = {1, 2, 3};
  std::list<int> std_lst = {1, 2, 3};
  EXPECT_EQ(s21_lst.front(), std_lst.front());
  EXPECT_EQ(s21_lst.back(), std_lst.back());
  EXPECT_EQ(s21_lst.size(), std_lst.size());
}

TEST(List, Constructor_Copy) {
  s21::List<int> s21_lst = {1, 2, 3};
  std::list<int> std_lst = {1, 2, 3};
  s21::List<int> s21_copy_lst(s21_lst);
  std::list<int> std_copy_lst(std_lst);
  EXPECT_EQ(s21_copy_lst.front(), std_copy_lst.front());
  EXPECT_EQ(s21_copy_lst.back(), std_copy_lst.back());
  EXPECT_EQ(s21_copy_lst.size(), std_copy_lst.size());
}

TEST(List, Operator_Copy) {
  s21::List<int> s21_lst = {1, 2, 3};
  std::list<int> std_lst = {1, 2, 3};
  s21::List<int> s21_copy_lst;
  s21_copy_lst = s21_lst;
  std::list<int> std_copy_lst;
  std_copy_lst = std_lst;
  EXPECT_EQ(s21_copy_lst.front(), std_copy_lst.front());
  EXPECT_EQ(s21_copy_lst.back(), std_copy_lst.back());
  EXPECT_EQ(s21_copy_lst.size(), std_copy_lst.size());
}

TEST(List, Constructor_Move) {
  s21::List<int> s21_lst = {1, 2, 3};
  std::list<int> std_lst = {1, 2, 3};
  s21::List<int> s21_copy_lst(std::move(s21_lst));
  std::list<int> std_copy_lst(std::move(std_lst));
  EXPECT_EQ(s21_copy_lst.front(), std_copy_lst.front());
  EXPECT_EQ(s21_copy_lst.back(), std_copy_lst.back());
  EXPECT_EQ(s21_lst.empty(), std_lst.empty());
  EXPECT_EQ(s21_lst.size(), std_lst.size());
  EXPECT_EQ(s21_copy_lst.size(), std_copy_lst.size());
}

TEST(List, Operator_Move) {
  s21::List<int> s21_lst = {1, 2, 3};
  std::list<int> std_lst = {1, 2, 3};
  s21::List<int> s21_copy_lst;
  s21_copy_lst = std::move(s21_lst);
  std::list<int> std_copy_lst;
  std_copy_lst = std::move(std_lst);
  EXPECT_EQ(s21_copy_lst.front(), std_copy_lst.front());
  EXPECT_EQ(s21_copy_lst.back(), std_copy_lst.back());
  EXPECT_EQ(s21_lst.empty(), std_lst.empty());
  EXPECT_EQ(s21_lst.size(), std_lst.size());
  EXPECT_EQ(s21_copy_lst.size(), std_copy_lst.size());
}

TEST(List, Size) {
  s21::List<int> s21_lst = {1, 2, 3};
  std::list<int> std_lst = {1, 2, 3};
  EXPECT_EQ(s21_lst.size(), std_lst.size());
}

TEST(List, Push_Front) {
  s21::List<int> s21_lst;
  std::list<int> std_lst;
  s21_lst.push_front(1);
  std_lst.push_front(1);
  EXPECT_EQ(s21_lst.front(), std_lst.front());
  EXPECT_EQ(s21_lst.back(), std_lst.back());
  s21_lst.push_front(2);
  std_lst.push_front(2);
  EXPECT_EQ(s21_lst.front(), std_lst.front());
  EXPECT_EQ(s21_lst.back(), std_lst.back());
  s21_lst.push_front(3);
  std_lst.push_front(3);
  EXPECT_EQ(s21_lst.front(), std_lst.front());
  EXPECT_EQ(s21_lst.back(), std_lst.back());
  EXPECT_EQ(s21_lst.size(), std_lst.size());
}

TEST(List, Push_Back) {
  s21::List<int> s21_lst;
  std::list<int> std_lst;
  s21_lst.push_back(1);
  std_lst.push_back(1);
  EXPECT_EQ(s21_lst.front(), std_lst.front());
  EXPECT_EQ(s21_lst.back(), std_lst.back());
  s21_lst.push_back(2);
  std_lst.push_back(2);
  EXPECT_EQ(s21_lst.front(), std_lst.front());
  EXPECT_EQ(s21_lst.back(), std_lst.back());
  s21_lst.push_back(3);
  std_lst.push_back(3);
  EXPECT_EQ(s21_lst.front(), std_lst.front());
  EXPECT_EQ(s21_lst.back(), std_lst.back());
  EXPECT_EQ(s21_lst.size(), std_lst.size());
}

TEST(List, Pop_Front) {
  s21::List<int> s21_lst = {1, 2, 3};
  std::list<int> std_lst = {1, 2, 3};
  s21_lst.pop_front();
  std_lst.pop_front();
  EXPECT_EQ(s21_lst.front(), std_lst.front());
  EXPECT_EQ(s21_lst.back(), std_lst.back());
  EXPECT_EQ(s21_lst.size(), std_lst.size());
  s21_lst.pop_front();
  std_lst.pop_front();
  EXPECT_EQ(s21_lst.front(), std_lst.front());
  EXPECT_EQ(s21_lst.back(), std_lst.back());
  EXPECT_EQ(s21_lst.size(), std_lst.size());
  s21_lst.pop_front();
  std_lst.pop_front();
  EXPECT_EQ(s21_lst.front(), std_lst.front());
  EXPECT_EQ(s21_lst.back(), std_lst.back());
  EXPECT_EQ(s21_lst.size(), std_lst.size());
}

TEST(List, Pop_Back) {
  s21::List<int> s21_lst = {1, 2, 3};
  std::list<int> std_lst = {1, 2, 3};
  s21_lst.pop_back();
  std_lst.pop_back();
  EXPECT_EQ(s21_lst.front(), std_lst.front());
  EXPECT_EQ(s21_lst.back(), std_lst.back());
  EXPECT_EQ(s21_lst.size(), std_lst.size());
  s21_lst.pop_back();
  std_lst.pop_back();
  EXPECT_EQ(s21_lst.front(), std_lst.front());
  EXPECT_EQ(s21_lst.back(), std_lst.back());
  EXPECT_EQ(s21_lst.size(), std_lst.size());
  s21_lst.pop_back();
  std_lst.pop_back();
  EXPECT_EQ(s21_lst.front(), std_lst.front());
  EXPECT_EQ(s21_lst.back(), std_lst.back());
  EXPECT_EQ(s21_lst.size(), std_lst.size());
}

TEST(List, Iterator_Begin) {
  s21::List<int> s21_lst = {1, 2, 3};
  std::list<int> std_lst = {1, 2, 3};
  s21::List<int>::iterator s21_it;
  s21_it = s21_lst.begin();
  std::list<int>::iterator std_it;
  std_it = std_lst.begin();
  EXPECT_EQ(*s21_it, *std_it);
}

TEST(List, Iterator_BeginPlusAndMinus) {
  s21::List<int> s21_lst = {1, 2, 3};
  std::list<int> std_lst = {1, 2, 3};
  s21::List<int>::iterator s21_it;
  s21_it = s21_lst.begin();
  ++s21_it;
  std::list<int>::iterator std_it;
  std_it = std_lst.begin();
  ++std_it;
  EXPECT_EQ(*s21_it, *std_it);
  --s21_it;
  --std_it;
  EXPECT_EQ(*s21_it, *std_it);
}

TEST(List, Iterator_End_Last) {
  s21::List<int> s21_lst = {1, 2, 3};
  std::list<int> std_lst = {1, 2, 3};
  s21::List<int>::iterator s21_it;
  s21_it = s21_lst.end();
  --s21_it;
  std::list<int>::iterator std_it;
  std_it = std_lst.end();
  --std_it;
  EXPECT_EQ(*s21_it, *std_it);
}

TEST(List, Iterators_Equality) {
  s21::List<int> s21_lst = {1, 2, 3};
  s21::List<int>::iterator s21_it1 = s21_lst.begin();
  s21::List<int>::iterator s21_it2 = s21_lst.end();
  s21_it1++;
  s21_it1++;
  s21_it2--;
  EXPECT_EQ(s21_it1 == s21_it2, 1);
}

TEST(List, Iterators_Not_Equality) {
  s21::List<int> s21_lst = {1, 2, 3};
  s21::List<int>::iterator s21_it1 = s21_lst.begin();
  s21::List<int>::iterator s21_it2 = s21_lst.end();
  s21_it2--;
  EXPECT_EQ(s21_it1 != s21_it2, 1);
}

TEST(List, Сlear) {
  s21::List<int> s21_lst = {1, 2, 3};
  std::list<int> std_lst = {1, 2, 3};
  s21_lst.clear();
  std_lst.clear();
  EXPECT_EQ(s21_lst.empty(), std_lst.empty());
  EXPECT_EQ(s21_lst.size(), std_lst.size());
}

TEST(List, Insert_To_Empty) {
  s21::List<int> s21_lst;
  std::list<int> std_lst;
  s21::List<int>::iterator s21_it;
  s21_it = s21_lst.end();
  std::list<int>::iterator std_it;
  std_it = std_lst.end();
  s21_lst.insert(s21_it, 5);
  std_lst.insert(std_it, 5);
  EXPECT_EQ(s21_lst.front(), std_lst.front());
  EXPECT_EQ(s21_lst.back(), std_lst.back());
}

TEST(List, Insert_To_Front) {
  s21::List<int> s21_lst;
  std::list<int> std_lst;
  s21::List<int>::iterator s21_it;
  s21_it = s21_lst.begin();
  std::list<int>::iterator std_it;
  std_it = std_lst.begin();
  s21::List<int>::iterator s21_new_it = s21_lst.insert(s21_it, 5);
  std::list<int>::iterator std_new_it = std_lst.insert(std_it, 5);
  EXPECT_EQ(s21_lst.front(), std_lst.front());
  EXPECT_EQ(s21_lst.back(), std_lst.back());
  EXPECT_EQ(*s21_new_it, *std_new_it);
  s21_it = s21_lst.begin();
  std_it = std_lst.begin();
  s21_new_it = s21_lst.insert(s21_it, 7);
  std_new_it = std_lst.insert(std_it, 7);
  EXPECT_EQ(s21_lst.front(), std_lst.front());
  EXPECT_EQ(s21_lst.back(), std_lst.back());
  EXPECT_EQ(*s21_new_it, *std_new_it);
  EXPECT_EQ(*s21_it, *std_it);
  EXPECT_EQ(s21_lst.size(), std_lst.size());
}

TEST(List, Insert_To_Back) {
  s21::List<int> s21_lst;
  std::list<int> std_lst;
  s21::List<int>::iterator s21_it;
  s21_it = s21_lst.end();
  std::list<int>::iterator std_it;
  std_it = std_lst.end();
  s21::List<int>::iterator s21_new_it = s21_lst.insert(s21_it, 5);
  std::list<int>::iterator std_new_it = std_lst.insert(std_it, 5);
  EXPECT_EQ(s21_lst.front(), std_lst.front());
  EXPECT_EQ(s21_lst.back(), std_lst.back());
  EXPECT_EQ(*s21_new_it, *std_new_it);
  s21_new_it = s21_lst.insert(s21_it, 7);
  std_new_it = std_lst.insert(std_it, 7);
  EXPECT_EQ(s21_lst.front(), std_lst.front());
  EXPECT_EQ(s21_lst.back(), std_lst.back());
  EXPECT_EQ(*s21_new_it, *std_new_it);
  EXPECT_EQ(s21_lst.size(), std_lst.size());
}

TEST(List, Insert_To_Middle) {
  s21::List<int> s21_lst{1, 2};
  std::list<int> std_lst{1, 2};
  s21::List<int>::iterator s21_it;
  s21_it = s21_lst.begin();
  s21_it++;
  std::list<int>::iterator std_it;
  std_it = std_lst.begin();
  std_it++;
  s21::List<int>::iterator s21_new_it = s21_lst.insert(s21_it, 5);
  std::list<int>::iterator std_new_it = std_lst.insert(std_it, 5);
  EXPECT_EQ(s21_lst.front(), std_lst.front());
  EXPECT_EQ(s21_lst.back(), std_lst.back());
  EXPECT_EQ(*s21_new_it, *std_new_it);
  EXPECT_EQ(*s21_it, *std_it);
  EXPECT_EQ(*(++std_lst.begin()), 5);
  EXPECT_EQ(*(++std_lst.begin()), *(++s21_lst.begin()));
  EXPECT_EQ(s21_lst.size(), std_lst.size());
}

TEST(List, Insert_With_Iterator_Not_Of_This_List) {
  s21::List<int> s21_lst1{1, 2};
  s21::List<int> s21_lst2{3};
  s21::List<int>::iterator s21_it2 = s21_lst2.begin();
  s21_lst1.insert(s21_it2, 10);
  s21::List<int>::iterator s21_it_check = s21_lst1.begin();
  EXPECT_EQ(*s21_it_check, 1);
  s21_it_check++;
  EXPECT_EQ(*s21_it_check, 2);
  s21_it_check++;
  EXPECT_EQ(*s21_it_check, DATA_IN_END_NODE);
  EXPECT_EQ(s21_lst1.size(), 2);
}

TEST(List, Erase_Front_Element) {
  s21::List<int> s21_lst = {1, 2, 3};
  std::list<int> std_lst = {1, 2, 3};
  s21_lst.erase(s21_lst.begin());
  std_lst.erase(std_lst.begin());
  EXPECT_EQ(s21_lst.front(), std_lst.front());
  EXPECT_EQ(s21_lst.back(), std_lst.back());
  EXPECT_EQ(s21_lst.size(), std_lst.size());
}

TEST(List, Erase_Back_Element) {
  s21::List<int> s21_lst = {1, 2, 3};
  std::list<int> std_lst = {1, 2, 3};
  s21::List<int>::iterator s21_it = s21_lst.end();
  --s21_it;
  std::list<int>::iterator std_it = std_lst.end();
  --std_it;
  s21_lst.erase(s21_it);
  std_lst.erase(std_it);
  EXPECT_EQ(s21_lst.front(), std_lst.front());
  EXPECT_EQ(s21_lst.back(), std_lst.back());
  EXPECT_EQ(s21_lst.size(), std_lst.size());
}

TEST(List, Erase_Middle_Element) {
  s21::List<int> s21_lst = {1, 2, 3};
  std::list<int> std_lst = {1, 2, 3};
  s21::List<int>::iterator s21_it = s21_lst.begin();
  ++s21_it;
  std::list<int>::iterator std_it = std_lst.begin();
  ++std_it;
  s21_lst.erase(s21_it);
  std_lst.erase(std_it);
  EXPECT_EQ(s21_lst.front(), std_lst.front());
  EXPECT_EQ(s21_lst.back(), std_lst.back());
  EXPECT_EQ(s21_lst.size(), std_lst.size());
}

TEST(List, Erase_Empty) {
  s21::List<int> s21_lst;
  try {
    s21_lst.erase(s21_lst.begin());
  } catch (const char *error_message) {
    EXPECT_EQ(error_message,
              "It is impossible to remove an element from an empty list");
  }
}

TEST(List, Erase_With_Iterator_Not_Of_This_List) {
  s21::List<int> s21_lst1{1, 2};
  s21::List<int> s21_lst2{3};
  s21::List<int>::iterator s21_it2 = s21_lst2.begin();
  s21_lst1.erase(s21_it2);
  s21::List<int>::iterator s21_it_check = s21_lst1.begin();
  EXPECT_EQ(*s21_it_check, 1);
  s21_it_check++;
  EXPECT_EQ(*s21_it_check, 2);
  s21_it_check++;
  EXPECT_EQ(*s21_it_check, DATA_IN_END_NODE);
  EXPECT_EQ(s21_lst1.size(), 2);
}

TEST(List, Splice_One_Element_To_Front) {
  s21::List<int> s21_lst_first = {1, 2};
  s21::List<int> s21_lst_second = {10};
  std::list<int> std_lst_first = {1, 2};
  std::list<int> std_lst_second = {10};
  s21::List<int>::iterator s21_it = s21_lst_first.begin();
  std::list<int>::iterator std_it = std_lst_first.begin();
  s21_lst_first.splice(s21_it, s21_lst_second);
  std_lst_first.splice(std_it, std_lst_second);

  std::list<int>::iterator std_it_check = std_lst_first.begin();
  for (auto s21_it_check = s21_lst_first.begin();
       s21_it_check != s21_lst_first.end(); s21_it_check++) {
    EXPECT_EQ(*std_it_check, *s21_it_check);
    std_it_check++;
  }
  EXPECT_EQ(s21_lst_second.empty(), std_lst_second.empty());
  EXPECT_EQ(s21_lst_first.size(), std_lst_first.size());
  EXPECT_EQ(s21_lst_second.size(), std_lst_second.size());
}

TEST(List, Splice_One_Element_To_Back) {
  s21::List<int> s21_lst_first = {1, 2};
  s21::List<int> s21_lst_second = {10};
  std::list<int> std_lst_first = {1, 2};
  std::list<int> std_lst_second = {10};
  s21::List<int>::iterator s21_it = s21_lst_first.end();
  std::list<int>::iterator std_it = std_lst_first.end();
  s21_lst_first.splice(s21_it, s21_lst_second);
  std_lst_first.splice(std_it, std_lst_second);

  std::list<int>::iterator std_it_check = std_lst_first.begin();
  for (auto s21_it_check = s21_lst_first.begin();
       s21_it_check != s21_lst_first.end(); s21_it_check++) {
    EXPECT_EQ(*std_it_check, *s21_it_check);
    std_it_check++;
  }
  EXPECT_EQ(s21_lst_second.empty(), std_lst_second.empty());
  EXPECT_EQ(s21_lst_first.size(), std_lst_first.size());
  EXPECT_EQ(s21_lst_second.size(), std_lst_second.size());
}

TEST(List, Splice_One_Element_To_Middle) {
  s21::List<int> s21_lst_first = {1, 2};
  s21::List<int> s21_lst_second = {10};
  std::list<int> std_lst_first = {1, 2};
  std::list<int> std_lst_second = {10};
  s21::List<int>::iterator s21_it = s21_lst_first.begin();
  std::list<int>::iterator std_it = std_lst_first.begin();
  s21_it++;
  std_it++;
  s21_lst_first.splice(s21_it, s21_lst_second);
  std_lst_first.splice(std_it, std_lst_second);

  std::list<int>::iterator std_it_check = std_lst_first.begin();
  for (auto s21_it_check = s21_lst_first.begin();
       s21_it_check != s21_lst_first.end(); s21_it_check++) {
    EXPECT_EQ(*std_it_check, *s21_it_check);
    std_it_check++;
  }
  EXPECT_EQ(s21_lst_second.empty(), std_lst_second.empty());
  EXPECT_EQ(s21_lst_first.size(), std_lst_first.size());
  EXPECT_EQ(s21_lst_second.size(), std_lst_second.size());
}

TEST(List, Splice_Set_Of_Elements_To_Front) {
  s21::List<int> s21_lst_first = {1, 2};
  s21::List<int> s21_lst_second = {4, 5, 6};
  std::list<int> std_lst_first = {1, 2};
  std::list<int> std_lst_second = {4, 5, 6};
  s21::List<int>::iterator s21_it = s21_lst_first.begin();
  std::list<int>::iterator std_it = std_lst_first.begin();

  s21_lst_first.splice(s21_it, s21_lst_second);
  std_lst_first.splice(std_it, std_lst_second);

  std::list<int>::iterator std_it_check = std_lst_first.begin();
  for (auto s21_it_check = s21_lst_first.begin();
       s21_it_check != s21_lst_first.end(); s21_it_check++) {
    EXPECT_EQ(*std_it_check, *s21_it_check);
    std_it_check++;
  }
  EXPECT_EQ(s21_lst_second.empty(), std_lst_second.empty());
  EXPECT_EQ(s21_lst_first.size(), std_lst_first.size());
  EXPECT_EQ(s21_lst_second.size(), std_lst_second.size());
}

TEST(List, Splice_Set_Of_Elements_To_Back) {
  s21::List<int> s21_lst_first = {1, 2};
  s21::List<int> s21_lst_second = {4, 5, 6};
  std::list<int> std_lst_first = {1, 2};
  std::list<int> std_lst_second = {4, 5, 6};
  s21::List<int>::iterator s21_it = s21_lst_first.end();
  std::list<int>::iterator std_it = std_lst_first.end();

  s21_lst_first.splice(s21_it, s21_lst_second);
  std_lst_first.splice(std_it, std_lst_second);

  std::list<int>::iterator std_it_check = std_lst_first.begin();
  for (auto s21_it_check = s21_lst_first.begin();
       s21_it_check != s21_lst_first.end(); s21_it_check++) {
    EXPECT_EQ(*std_it_check, *s21_it_check);
    std_it_check++;
  }
  EXPECT_EQ(s21_lst_second.empty(), std_lst_second.empty());
  EXPECT_EQ(s21_lst_first.size(), std_lst_first.size());
  EXPECT_EQ(s21_lst_second.size(), std_lst_second.size());
}

TEST(List, Splice_Set_Of_Elements_To_Middle) {
  s21::List<int> s21_lst_first = {1, 2};
  s21::List<int> s21_lst_second = {4, 5, 6};
  std::list<int> std_lst_first = {1, 2};
  std::list<int> std_lst_second = {4, 5, 6};
  s21::List<int>::iterator s21_it = s21_lst_first.begin();
  std::list<int>::iterator std_it = std_lst_first.begin();
  s21_it++;
  std_it++;

  s21_lst_first.splice(s21_it, s21_lst_second);
  std_lst_first.splice(std_it, std_lst_second);

  std::list<int>::iterator std_it_check = std_lst_first.begin();
  for (auto s21_it_check = s21_lst_first.begin();
       s21_it_check != s21_lst_first.end(); s21_it_check++) {
    EXPECT_EQ(*std_it_check, *s21_it_check);
    std_it_check++;
  }
  EXPECT_EQ(s21_lst_second.empty(), std_lst_second.empty());
  EXPECT_EQ(s21_lst_first.size(), std_lst_first.size());
  EXPECT_EQ(s21_lst_second.size(), std_lst_second.size());
}

TEST(List, Splice_Receiving_List_Is_Empty) {
  s21::List<int> s21_lst_first = {1, 2};
  s21::List<int> s21_lst_second;
  std::list<int> std_lst_first = {1, 2};
  std::list<int> std_lst_second;
  s21::List<int>::iterator s21_it = s21_lst_first.begin();
  std::list<int>::iterator std_it = std_lst_first.begin();

  s21_lst_first.splice(s21_it, s21_lst_second);
  std_lst_first.splice(std_it, std_lst_second);

  std::list<int>::iterator std_it_check = std_lst_first.begin();
  for (auto s21_it_check = s21_lst_first.begin();
       s21_it_check != s21_lst_first.end(); s21_it_check++) {
    EXPECT_EQ(*std_it_check, *s21_it_check);
    std_it_check++;
  }
  EXPECT_EQ(s21_lst_second.empty(), std_lst_second.empty());
  EXPECT_EQ(s21_lst_first.size(), std_lst_first.size());
  EXPECT_EQ(s21_lst_second.size(), std_lst_second.size());
}

TEST(List, Splice_Accepted_List_Is_Empty) {
  s21::List<int> s21_lst_first;
  s21::List<int> s21_lst_second = {4, 5, 6};
  std::list<int> std_lst_first;
  std::list<int> std_lst_second = {4, 5, 6};
  s21::List<int>::iterator s21_it = s21_lst_first.begin();
  std::list<int>::iterator std_it = std_lst_first.begin();

  s21_lst_first.splice(s21_it, s21_lst_second);
  std_lst_first.splice(std_it, std_lst_second);

  std::list<int>::iterator std_it_check = std_lst_first.begin();
  for (auto s21_it_check = s21_lst_first.begin();
       s21_it_check != s21_lst_first.end(); s21_it_check++) {
    EXPECT_EQ(*std_it_check, *s21_it_check);
    std_it_check++;
  }
  EXPECT_EQ(s21_lst_second.empty(), std_lst_second.empty());
  EXPECT_EQ(s21_lst_first.size(), std_lst_first.size());
  EXPECT_EQ(s21_lst_second.size(), std_lst_second.size());
}

TEST(List, Splice_Both_Lists_Are_Empty) {
  s21::List<int> s21_lst_first;
  s21::List<int> s21_lst_second;
  std::list<int> std_lst_first;
  std::list<int> std_lst_second;
  s21::List<int>::iterator s21_it = s21_lst_first.begin();
  std::list<int>::iterator std_it = std_lst_first.begin();

  s21_lst_first.splice(s21_it, s21_lst_second);
  std_lst_first.splice(std_it, std_lst_second);

  EXPECT_EQ(s21_lst_first.empty(), std_lst_first.empty());
  EXPECT_EQ(s21_lst_second.empty(), std_lst_second.empty());
  EXPECT_EQ(s21_lst_first.size(), std_lst_first.size());
  EXPECT_EQ(s21_lst_second.size(), std_lst_second.size());
}

TEST(List, Splice_With_Iterator_Not_Of_This_List) {
  s21::List<int> s21_lst1{1, 2};
  s21::List<int> s21_lst2{3};
  s21::List<int>::iterator s21_it2 = s21_lst2.begin();
  s21_lst1.splice(s21_it2, s21_lst2);

  s21::List<int>::iterator s21_it_check = s21_lst1.begin();
  EXPECT_EQ(*s21_it_check, 1);
  s21_it_check++;
  EXPECT_EQ(*s21_it_check, 2);
  s21_it_check++;
  EXPECT_EQ(*s21_it_check, DATA_IN_END_NODE);
  EXPECT_EQ(s21_lst1.size(), 2);
  EXPECT_EQ(s21_lst2.size(), 1);
}

TEST(List, Merge_Receiving_List_Have_One_Element) {
  s21::List<int> s21_lst_first = {2};
  s21::List<int> s21_lst_second = {1, 3, 4};
  std::list<int> std_lst_first = {2};
  std::list<int> std_lst_second = {1, 3, 4};
  s21_lst_first.merge(s21_lst_second);
  std_lst_first.merge(std_lst_second);

  std::list<int>::iterator std_it_check = std_lst_first.begin();
  for (auto s21_it_check = s21_lst_first.begin();
       s21_it_check != s21_lst_first.end(); s21_it_check++) {
    EXPECT_EQ(*std_it_check, *s21_it_check);
    std_it_check++;
  }
  EXPECT_EQ(s21_lst_second.empty(), std_lst_second.empty());
  EXPECT_EQ(s21_lst_first.size(), std_lst_first.size());
  EXPECT_EQ(s21_lst_second.size(), std_lst_second.size());
}

TEST(List, Merge_Accepted_List_Have_One_Element) {
  s21::List<int> s21_lst_first = {1, 3, 4};
  s21::List<int> s21_lst_second = {2};
  std::list<int> std_lst_first = {1, 3, 4};
  std::list<int> std_lst_second = {2};
  s21_lst_first.merge(s21_lst_second);
  std_lst_first.merge(std_lst_second);

  std::list<int>::iterator std_it_check = std_lst_first.begin();
  for (auto s21_it_check = s21_lst_first.begin();
       s21_it_check != s21_lst_first.end(); s21_it_check++) {
    EXPECT_EQ(*std_it_check, *s21_it_check);
    std_it_check++;
  }
  EXPECT_EQ(s21_lst_second.empty(), std_lst_second.empty());
  EXPECT_EQ(s21_lst_first.size(), std_lst_first.size());
  EXPECT_EQ(s21_lst_second.size(), std_lst_second.size());
}

TEST(List, Merge_Both_Have_One_Element) {
  s21::List<int> s21_lst_first = {3};
  s21::List<int> s21_lst_second = {1};
  std::list<int> std_lst_first = {3};
  std::list<int> std_lst_second = {1};
  s21_lst_first.merge(s21_lst_second);
  std_lst_first.merge(std_lst_second);

  std::list<int>::iterator std_it_check = std_lst_first.begin();
  for (auto s21_it_check = s21_lst_first.begin();
       s21_it_check != s21_lst_first.end(); s21_it_check++) {
    EXPECT_EQ(*std_it_check, *s21_it_check);
    std_it_check++;
  }
  EXPECT_EQ(s21_lst_second.empty(), std_lst_second.empty());
  EXPECT_EQ(s21_lst_first.size(), std_lst_first.size());
  EXPECT_EQ(s21_lst_second.size(), std_lst_second.size());
}

TEST(List, Merge_Sets_Of_Elements) {
  s21::List<int> s21_lst_first = {3, 8, 10};
  s21::List<int> s21_lst_second = {-10, 1, 2, 6, 100};
  std::list<int> std_lst_first = {3, 8, 10};
  std::list<int> std_lst_second = {-10, 1, 2, 6, 100};
  s21_lst_first.merge(s21_lst_second);
  std_lst_first.merge(std_lst_second);

  std::list<int>::iterator std_it_check = std_lst_first.begin();
  for (auto s21_it_check = s21_lst_first.begin();
       s21_it_check != s21_lst_first.end(); s21_it_check++) {
    EXPECT_EQ(*std_it_check, *s21_it_check);
    std_it_check++;
  }
  EXPECT_EQ(s21_lst_second.empty(), std_lst_second.empty());
  EXPECT_EQ(s21_lst_first.size(), std_lst_first.size());
  EXPECT_EQ(s21_lst_second.size(), std_lst_second.size());
}

TEST(List, Merge_Sets_Of_Elements_With_Repetitions) {
  s21::List<int> s21_lst_first = {3, 8, 10, 10};
  s21::List<int> s21_lst_second = {-10, 1, 2, 3, 6, 8, 10, 100};
  std::list<int> std_lst_first = {3, 8, 10, 10};
  std::list<int> std_lst_second = {-10, 1, 2, 3, 6, 8, 10, 100};
  s21_lst_first.merge(s21_lst_second);
  std_lst_first.merge(std_lst_second);

  std::list<int>::iterator std_it_check = std_lst_first.begin();
  for (auto s21_it_check = s21_lst_first.begin();
       s21_it_check != s21_lst_first.end(); s21_it_check++) {
    EXPECT_EQ(*std_it_check, *s21_it_check);
    std_it_check++;
  }
  EXPECT_EQ(s21_lst_second.empty(), std_lst_second.empty());
  EXPECT_EQ(s21_lst_first.size(), std_lst_first.size());
  EXPECT_EQ(s21_lst_second.size(), std_lst_second.size());
}

TEST(List, Merge_Receiving_List_Is_Empty) {
  s21::List<int> s21_lst_first;
  s21::List<int> s21_lst_second = {1, 3};
  std::list<int> std_lst_first;
  std::list<int> std_lst_second = {1, 3};
  s21_lst_first.merge(s21_lst_second);
  std_lst_first.merge(std_lst_second);

  std::list<int>::iterator std_it_check = std_lst_first.begin();
  for (auto s21_it_check = s21_lst_first.begin();
       s21_it_check != s21_lst_first.end(); s21_it_check++) {
    EXPECT_EQ(*std_it_check, *s21_it_check);
    std_it_check++;
  }
  EXPECT_EQ(s21_lst_second.empty(), std_lst_second.empty());
  EXPECT_EQ(s21_lst_first.size(), std_lst_first.size());
  EXPECT_EQ(s21_lst_second.size(), std_lst_second.size());
}

TEST(List, Merge_Accepted_List_Is_Empty) {
  s21::List<int> s21_lst_first = {2, 4};
  s21::List<int> s21_lst_second;
  std::list<int> std_lst_first = {2, 4};
  std::list<int> std_lst_second;
  s21_lst_first.merge(s21_lst_second);
  std_lst_first.merge(std_lst_second);

  std::list<int>::iterator std_it_check = std_lst_first.begin();
  for (auto s21_it_check = s21_lst_first.begin();
       s21_it_check != s21_lst_first.end(); s21_it_check++) {
    EXPECT_EQ(*std_it_check, *s21_it_check);
    std_it_check++;
  }
  EXPECT_EQ(s21_lst_second.empty(), std_lst_second.empty());
  EXPECT_EQ(s21_lst_first.size(), std_lst_first.size());
  EXPECT_EQ(s21_lst_second.size(), std_lst_second.size());
}

TEST(List, Merge_Both_Lists_Are_Empty) {
  s21::List<int> s21_lst_first;
  s21::List<int> s21_lst_second;
  std::list<int> std_lst_first;
  std::list<int> std_lst_second;
  s21_lst_first.merge(s21_lst_second);
  std_lst_first.merge(std_lst_second);

  EXPECT_EQ(s21_lst_first.empty(), std_lst_first.empty());
  EXPECT_EQ(s21_lst_second.empty(), std_lst_second.empty());
  EXPECT_EQ(s21_lst_first.size(), std_lst_first.size());
  EXPECT_EQ(s21_lst_second.size(), std_lst_second.size());
}

TEST(List, Reverse_One_Element) {
  s21::List<int> s21_lst = {1};
  std::list<int> std_lst = {1};
  s21_lst.reverse();
  std_lst.reverse();
  EXPECT_EQ(s21_lst.front(), std_lst.front());
  EXPECT_EQ(s21_lst.back(), std_lst.back());
  EXPECT_EQ(s21_lst.size(), std_lst.size());
}

TEST(List, Reverse_Two_Elements) {
  s21::List<int> s21_lst = {1, 2};
  std::list<int> std_lst = {1, 2};
  s21_lst.reverse();
  std_lst.reverse();
  EXPECT_EQ(s21_lst.front(), std_lst.front());
  EXPECT_EQ(s21_lst.back(), std_lst.back());
  EXPECT_EQ(s21_lst.size(), std_lst.size());
}

TEST(List, Reverse_Set_Of_Elements_Even_Number) {
  s21::List<int> s21_lst = {1, 2, 3, 4, 5, 6};
  std::list<int> std_lst = {1, 2, 3, 4, 5, 6};
  s21_lst.reverse();
  std_lst.reverse();

  std::list<int>::iterator std_it_check = std_lst.begin();
  for (auto s21_it_check = s21_lst.begin(); s21_it_check != s21_lst.end();
       s21_it_check++) {
    EXPECT_EQ(*std_it_check, *s21_it_check);
    std_it_check++;
  }
  EXPECT_EQ(s21_lst.size(), std_lst.size());
}

TEST(List, Reverse_Set_Of_Elements_Odd_Number) {
  s21::List<int> s21_lst = {1, 2, 3, 4, 5};
  std::list<int> std_lst = {1, 2, 3, 4, 5};
  s21_lst.reverse();
  std_lst.reverse();

  std::list<int>::iterator std_it_check = std_lst.begin();
  for (auto s21_it_check = s21_lst.begin(); s21_it_check != s21_lst.end();
       s21_it_check++) {
    EXPECT_EQ(*std_it_check, *s21_it_check);
    std_it_check++;
  }
  EXPECT_EQ(s21_lst.size(), std_lst.size());
}

TEST(List, Reverse_Empty_List) {
  s21::List<int> s21_lst;
  std::list<int> std_lst;
  s21_lst.reverse();
  std_lst.reverse();

  EXPECT_EQ(s21_lst.empty(), std_lst.empty());
  EXPECT_EQ(s21_lst.size(), std_lst.size());
}

TEST(List, Unique_One_Element) {
  s21::List<int> s21_lst = {1};
  std::list<int> std_lst = {1};
  s21_lst.unique();
  std_lst.unique();
  std::list<int>::iterator std_it_check = std_lst.begin();
  for (auto s21_it_check = s21_lst.begin(); s21_it_check != s21_lst.end();
       s21_it_check++) {
    EXPECT_EQ(*std_it_check, *s21_it_check);
    std_it_check++;
  }
  EXPECT_EQ(s21_lst.size(), std_lst.size());
}

TEST(List, Unique_Set_Of_Unique_Elements) {
  s21::List<int> s21_lst = {1, 2, 3};
  std::list<int> std_lst = {1, 2, 3};
  s21_lst.unique();
  std_lst.unique();
  std::list<int>::iterator std_it_check = std_lst.begin();
  for (auto s21_it_check = s21_lst.begin(); s21_it_check != s21_lst.end();
       s21_it_check++) {
    EXPECT_EQ(*std_it_check, *s21_it_check);
    std_it_check++;
  }
  EXPECT_EQ(s21_lst.size(), std_lst.size());
}

TEST(List, Unique_Set_Of_Duplicates_Elements_Nearby) {
  s21::List<int> s21_lst = {1, 1, 1, 2, 3, 3};
  std::list<int> std_lst = {1, 1, 1, 2, 3, 3};
  s21_lst.unique();
  std_lst.unique();
  std::list<int>::iterator std_it_check = std_lst.begin();
  for (auto s21_it_check = s21_lst.begin(); s21_it_check != s21_lst.end();
       s21_it_check++) {
    EXPECT_EQ(*std_it_check, *s21_it_check);
    std_it_check++;
  }
  EXPECT_EQ(s21_lst.size(), std_lst.size());
}

TEST(List, Unique_Set_Of_Duplicates_Elements_With_Distance) {
  s21::List<int> s21_lst = {1, 3, 1, 2, 3};
  std::list<int> std_lst = {1, 3, 1, 2, 3};
  s21_lst.unique();
  std_lst.unique();
  std::list<int>::iterator std_it_check = std_lst.begin();
  for (auto s21_it_check = s21_lst.begin(); s21_it_check != s21_lst.end();
       s21_it_check++) {
    EXPECT_EQ(*std_it_check, *s21_it_check);
    std_it_check++;
  }
  EXPECT_EQ(s21_lst.size(), std_lst.size());
}

TEST(List, Unique_Empty_List) {
  s21::List<int> s21_lst;
  std::list<int> std_lst;
  s21_lst.unique();
  std_lst.unique();
  EXPECT_EQ(s21_lst.empty(), std_lst.empty());
  EXPECT_EQ(s21_lst.size(), std_lst.size());
}

TEST(List, Sort_One_Element) {
  s21::List<int> s21_lst = {1};
  std::list<int> std_lst = {1};
  s21_lst.sort();
  std_lst.sort();
  std::list<int>::iterator std_it_check = std_lst.begin();
  for (auto s21_it_check = s21_lst.begin(); s21_it_check != s21_lst.end();
       s21_it_check++) {
    EXPECT_EQ(*std_it_check, *s21_it_check);
    std_it_check++;
  }
  EXPECT_EQ(s21_lst.size(), std_lst.size());
}

TEST(List, Sort_Two_Elements) {
  s21::List<int> s21_lst = {2, 1};
  std::list<int> std_lst = {2, 1};
  s21_lst.sort();
  std_lst.sort();
  std::list<int>::iterator std_it_check = std_lst.begin();
  for (auto s21_it_check = s21_lst.begin(); s21_it_check != s21_lst.end();
       s21_it_check++) {
    EXPECT_EQ(*std_it_check, *s21_it_check);
    std_it_check++;
  }
  EXPECT_EQ(s21_lst.size(), std_lst.size());
}

TEST(List, Sort_Initially_Sorted) {
  s21::List<int> s21_lst = {-100, 0, 100};
  std::list<int> std_lst = {-100, 0, 100};
  s21_lst.sort();
  std_lst.sort();
  std::list<int>::iterator std_it_check = std_lst.begin();
  for (auto s21_it_check = s21_lst.begin(); s21_it_check != s21_lst.end();
       s21_it_check++) {
    EXPECT_EQ(*std_it_check, *s21_it_check);
    std_it_check++;
  }
  EXPECT_EQ(s21_lst.size(), std_lst.size());
}

TEST(List, Sort_Set_Of_Elements) {
  s21::List<int> s21_lst = {8, 3, 2, 5, 1, 6};
  std::list<int> std_lst = {8, 3, 2, 5, 1, 6};
  s21_lst.sort();
  std_lst.sort();
  std::list<int>::iterator std_it_check = std_lst.begin();
  for (auto s21_it_check = s21_lst.begin(); s21_it_check != s21_lst.end();
       s21_it_check++) {
    EXPECT_EQ(*std_it_check, *s21_it_check);
    std_it_check++;
  }
  EXPECT_EQ(s21_lst.size(), std_lst.size());
}

TEST(List, Sort_Set_Of_Elements_With_Repetitions) {
  s21::List<int> s21_lst = {2, 3, 8, 3, 3, 3, 2, 5, 1, 8, 6};
  std::list<int> std_lst = {2, 3, 8, 3, 3, 3, 2, 5, 1, 8, 6};
  s21_lst.sort();
  std_lst.sort();
  std::list<int>::iterator std_it_check = std_lst.begin();
  for (auto s21_it_check = s21_lst.begin(); s21_it_check != s21_lst.end();
       s21_it_check++) {
    EXPECT_EQ(*std_it_check, *s21_it_check);
    std_it_check++;
  }
  EXPECT_EQ(s21_lst.size(), std_lst.size());
}

TEST(List, Sort_Large_Number_Of_Elements_With_Repetitions) {
  s21::List<int> s21_lst = {45, 78,  34, 34,  -12, 56,  -89, 0,   23,  -67, 91,
                            45, -34, 67, -78, 12,  -56, 89,  -23, 100, -1};
  std::list<int> std_lst = {45, 78,  34, 34,  -12, 56,  -89, 0,   23,  -67, 91,
                            45, -34, 67, -78, 12,  -56, 89,  -23, 100, -1};
  s21_lst.sort();
  std_lst.sort();
  std::list<int>::iterator std_it_check = std_lst.begin();
  for (auto s21_it_check = s21_lst.begin(); s21_it_check != s21_lst.end();
       s21_it_check++) {
    EXPECT_EQ(*std_it_check, *s21_it_check);
    std_it_check++;
  }
  EXPECT_EQ(s21_lst.size(), std_lst.size());
}

TEST(List, Sort_Empty_List) {
  s21::List<int> s21_lst;
  std::list<int> std_lst;
  s21_lst.sort();
  std_lst.sort();
  EXPECT_EQ(s21_lst.empty(), std_lst.empty());
  EXPECT_EQ(s21_lst.size(), std_lst.size());
}

// в начало 3
// в конец 3
// в середину 3
// 1
// 0
// если начальный лист пустой
// если итератор не из этого листа

TEST(List, Insert_Many_One_Element_To_Front) { //new it
  s21::List<int> s21_lst = {1, 2};
  s21::List<int>::iterator s21_it = s21_lst.begin();
  ++s21_it;
  s21::List<int>::iterator s21_new_it = s21_lst.insert_many(s21_it, 3, 4, 5); //
  s21::List<int> rez_lst = {1, 3, 4, 5, 2};

  s21::List<int>::iterator rez_it_check = rez_lst.begin();
  for (auto s21_it_check = s21_lst.begin(); s21_it_check != s21_lst.end();
       s21_it_check++) {
    EXPECT_EQ(*rez_it_check, *s21_it_check);
    rez_it_check++;
  }
  EXPECT_EQ(s21_lst.size(), rez_lst.size());
}

// TEST(List, Insert_Many_One_Element_To_Back) {

// TEST(List, Insert_Many_One_Element_To_Middle) {

// TEST(List, Insert_Many_Set_Of_Elements_To_Front) {

// TEST(List, Insert_Many_Set_Of_Elements_To_Back) {

TEST(List, Insert_Many_Set_Of_Elements_To_Middle) {
  s21::List<int> s21_lst = {1, 2};
  s21::List<int>::iterator s21_it = s21_lst.begin();
  ++s21_it;
  s21_lst.insert_many(s21_it, 3, 4, 5);
  s21::List<int> rez_lst = {1, 3, 4, 5, 2};

  s21::List<int>::iterator rez_it_check = rez_lst.begin();
  for (auto s21_it_check = s21_lst.begin(); s21_it_check != s21_lst.end();
       s21_it_check++) {
    EXPECT_EQ(*rez_it_check, *s21_it_check);
    rez_it_check++;
  }
  EXPECT_EQ(s21_lst.size(), rez_lst.size());
}

///

// TEST(List, Insert_Many_Empty_Iterator_Arg) {

// TEST(List, Insert_Many_Empty_Elements_Arg) {

// TEST(List, Insert_Many_Empty_All_Args) {

// TEST(List, Insert_Many_To_Empty_List) {

// TEST(List, Insert_Many_With_Iterator_Not_Of_This_List) {

// TEST(List, Insert_Many_Back) {
//   s21::List<int> s21_lst = {1, 2, 3, 4, 5};
//   s21::List<int>::iterator s21_it;
//   s21_lst.insert_many_back(7, 8, 9);
//   s21_it = s21_lst.end();
//   --s21_it;
//   EXPECT_EQ(*s21_it, 9);
//   --s21_it;
//   EXPECT_EQ(*s21_it, 8);
//   --s21_it;
//   EXPECT_EQ(*s21_it, 7);
//   --s21_it;
//   EXPECT_EQ(*s21_it, 5);
//   --s21_it;
//   EXPECT_EQ(*s21_it, 4);
// }

// TEST(List, Insert_Many_Back_One_Element) {

// TEST(List, Insert_Many_Back_Set_Of_Elements) {

// TEST(List, Insert_Many_Back_Empty_Elements_Arg) {

// TEST(List, Insert_Many_Back_To_Empty_List) {

// TEST(List, Insert_Many_Back_With_Iterator_Not_Of_This_List) {

// TEST(List, Insert_Many_Front) {
//   s21::List<int> s21_lst = {1, 2, 3, 4, 5};
//   s21::List<int>::iterator s21_it;
//   s21_lst.insert_many_front(7, 8, 9);
//   s21_it = s21_lst.begin();
//   EXPECT_EQ(*s21_it, 9);
//   ++s21_it;
//   EXPECT_EQ(*s21_it, 8);
//   ++s21_it;
//   EXPECT_EQ(*s21_it, 7);
//   ++s21_it;
//   EXPECT_EQ(*s21_it, 1);
//   ++s21_it;
//   EXPECT_EQ(*s21_it, 2);
// }

// TEST(List, Insert_Many_Front_One_Element) {

// TEST(List, Insert_Many_Front_Set_Of_Elements) {

// TEST(List, Insert_Many_Front_Empty_Elements_Arg) {

// TEST(List, Insert_Many_Front_To_Empty_List) {

// TEST(List, Insert_Many_Front_With_Iterator_Not_Of_This_List) {

// ///////////////////////////////////////////////

// TEST(Queue, Constructor_Default) {
//   s21::Queue<int> s21_queue;
//   std::queue<int> std_queue;
//   EXPECT_EQ(s21_queue.empty(), std_queue.empty());
// }

// TEST(Queue, Constructor_List) {
//   s21::Queue<int> s21_queue = {1, 2, 3};
//   std::queue<int> std_queue;
//   std_queue.push(1);
//   std_queue.push(2);
//   std_queue.push(3);
//   EXPECT_EQ(s21_queue.front(), std_queue.front());
//   EXPECT_EQ(s21_queue.back(), std_queue.back());
// }

// TEST(Queue, Constructor_Copy) {
//   s21::Queue<int> s21_queue = {1, 2, 3};
//   s21::Queue<int> s21_copy(s21_queue);
//   std::queue<int> std_queue;
//   std_queue.push(1);
//   std_queue.push(2);
//   std_queue.push(3);
//   std::queue<int> std_copy_lst(std_queue);
//   EXPECT_EQ(s21_copy.front(), std_copy_lst.front());
//   EXPECT_EQ(s21_copy.back(), std_copy_lst.back());
// }

// TEST(Queue, Operator_Copy) {
//   s21::Queue<int> s21_queue_int = {1, 2, 3};
//   std::queue<int> std_queue_int;
//   std_queue_int.push(1);
//   std_queue_int.push(2);
//   std_queue_int.push(3);
//   s21::Queue<int> s21_queue_empty;
//   std::queue<int> std_queue_empty;
//   s21_queue_empty = s21_queue_int;
//   std_queue_empty = std_queue_int;
//   EXPECT_EQ(s21_queue_empty.front(), std_queue_empty.front());
//   EXPECT_EQ(s21_queue_empty.back(), std_queue_empty.back());
//   EXPECT_EQ(s21_queue_int.empty(), std_queue_int.empty());
// }

// TEST(Queue, Constructor_Move) {
//   s21::Queue<int> s21_queue = {1, 2, 3};
//   s21::Queue<int> s21_move(std::move(s21_queue));
//   std::queue<int> std_queue;
//   std_queue.push(1);
//   std_queue.push(2);
//   std_queue.push(3);
//   std::queue<int> std_move(std::move(std_queue));
//   // EXPECT_EQ(s21_move.front(), std_move.front());
//   // EXPECT_EQ(s21_move.back(), std_move.back());
//   // EXPECT_EQ(s21_queue.empty(), std_queue.empty());
// }

// TEST(Queue, Operator_Move) {
//   s21::Queue<int> s21_queue_int = {1, 2, 3};
//   std::queue<int> std_queue_int;
//   std_queue_int.push(1);
//   std_queue_int.push(2);
//   std_queue_int.push(3);
//   s21::Queue<int> s21_queue_empty;
//   std::queue<int> std_queue_empty;
//   s21_queue_empty = std::move(s21_queue_int);
//   std_queue_empty = std::move(std_queue_int);
//   EXPECT_EQ(s21_queue_empty.front(), std_queue_empty.front());
//   EXPECT_EQ(s21_queue_empty.back(), std_queue_empty.back());
//   EXPECT_EQ(s21_queue_int.empty(), std_queue_int.empty());
// }

// TEST(Queue, FrontAndBack) {
//   s21::Queue<int> s21_queue_int = {1, 2, 3};
//   std::queue<int> std_queue_int;
//   std_queue_int.push(1);
//   std_queue_int.push(2);
//   std_queue_int.push(3);
//   s21::Queue<double> s21_queue_double = {1.1f, 2.1f, 3.1f};
//   std::queue<double> std_queue_double;
//   std_queue_double.push(1.1f);
//   std_queue_double.push(2.1f);
//   std_queue_double.push(3.1f);
//   s21::Queue<std::string> s21_queue_string = {"abc", "def", "ghf"};
//   std::queue<std::string> std_queue_string;
//   std_queue_string.push("abc");
//   std_queue_string.push("def");
//   std_queue_string.push("ghf");
//   EXPECT_EQ(s21_queue_int.front(), std_queue_int.front());
//   EXPECT_EQ(s21_queue_double.front(), std_queue_double.front());
//   EXPECT_EQ(s21_queue_string.front(), std_queue_string.front());
//   EXPECT_EQ(s21_queue_int.back(), std_queue_int.back());
//   EXPECT_EQ(s21_queue_double.back(), std_queue_double.back());
//   EXPECT_EQ(s21_queue_string.back(), std_queue_string.back());
// }

// TEST(Queue, Empty) {
//   s21::Queue<int> s21_queue_int = {1, 2, 3};
//   std::queue<int> std_queue_int;
//   std_queue_int.push(1);
//   std_queue_int.push(2);
//   std_queue_int.push(3);
//   EXPECT_EQ(s21_queue_int.empty(), std_queue_int.empty());
//   s21::Queue<int> s21_queue_empty;
//   std::queue<int> std_queue_empty;
//   EXPECT_EQ(s21_queue_empty.empty(), std_queue_empty.empty());
// }

// TEST(Queue, Size) {
//   s21::Queue<int> s21_queue_int = {1, 2, 3};
//   std::queue<int> std_queue_int;
//   std_queue_int.push(1);
//   std_queue_int.push(2);
//   std_queue_int.push(3);
//   EXPECT_EQ(s21_queue_int.size(), std_queue_int.size());
//   s21::Queue<int> s21_queue_empty;
//   std::queue<int> std_queue_empty;
//   EXPECT_EQ(s21_queue_empty.size(), std_queue_empty.size());
// }

// TEST(Queue, Push) {
//   s21::Queue<int> s21_queue_int;
//   s21_queue_int.push(1);
//   s21_queue_int.push(2);
//   s21_queue_int.push(3);
//   std::queue<int> std_queue_int;
//   std_queue_int.push(1);
//   std_queue_int.push(2);
//   std_queue_int.push(3);
//   EXPECT_EQ(s21_queue_int.front(), std_queue_int.front());
//   EXPECT_EQ(s21_queue_int.back(), std_queue_int.back());
// }

// TEST(Queue, Pop) {
//   s21::Queue<int> s21_queue_int;
//   s21_queue_int.push(1);
//   s21_queue_int.push(2);
//   s21_queue_int.push(3);
//   s21_queue_int.pop();
//   std::queue<int> std_queue_int;
//   std_queue_int.push(1);
//   std_queue_int.push(2);
//   std_queue_int.push(3);
//   std_queue_int.pop();
//   EXPECT_EQ(s21_queue_int.front(), std_queue_int.front());
//   EXPECT_EQ(s21_queue_int.back(), std_queue_int.back());
//   s21_queue_int.pop();
//   s21_queue_int.pop();
//   std_queue_int.pop();
//   std_queue_int.pop();
//   EXPECT_EQ(s21_queue_int.empty(), std_queue_int.empty());
// }

// TEST(Queue, Swap) {
//   s21::Queue<int> s21_queue_int = {1, 2, 3};
//   std::queue<int> std_queue_int;
//   std_queue_int.push(1);
//   std_queue_int.push(2);
//   std_queue_int.push(3);
//   s21::Queue<int> s21_queue_empty;
//   std::queue<int> std_queue_empty;
//   s21_queue_empty.swap(s21_queue_int);
//   std_queue_empty.swap(std_queue_int);
//   EXPECT_EQ(s21_queue_empty.front(), std_queue_empty.front());
//   EXPECT_EQ(s21_queue_empty.back(), std_queue_empty.back());
//   EXPECT_EQ(s21_queue_int.empty(), std_queue_int.empty());
// }

// TEST(Queue, InsertManyBack) {
//   s21::Queue<int> s21_queue_int;
//   s21_queue_int.insert_many_back(1, 2, 3);
//   EXPECT_EQ(s21_queue_int.front(), 1);
//   EXPECT_EQ(s21_queue_int.back(), 3);
// }

// ////////////////////////////////////////

// TEST(Stack, Constructor_Default) {
//   s21::Stack<int> s21_stack;
//   std::stack<int> std_stack;
//   EXPECT_EQ(s21_stack.empty(), std_stack.empty());
// }

// TEST(Stack, Constructor_List) {
//   s21::Stack<int> s21_stack = {1, 2, 3};
//   std::stack<int> std_stack;
//   std_stack.push(1);
//   std_stack.push(2);
//   std_stack.push(3);
//   EXPECT_EQ(s21_stack.top(), std_stack.top());
// }

// TEST(Stack, Constructor_Copy) {
//   s21::Stack<int> s21_stack = {1, 2, 3};
//   s21::Stack<int> s21_copy(s21_stack);
//   std::stack<int> std_stack;
//   std_stack.push(1);
//   std_stack.push(2);
//   std_stack.push(3);
//   std::stack<int> std_copy_lst(std_stack);
//   EXPECT_EQ(s21_copy.top(), std_copy_lst.top());
// }

// TEST(Stack, Operator_Copy) {
//   s21::Stack<int> s21_stack_int = {1, 2, 3};
//   std::stack<int> std_stack_int;
//   std_stack_int.push(1);
//   std_stack_int.push(2);
//   std_stack_int.push(3);
//   s21::Stack<int> s21_stack_empty;
//   std::stack<int> std_stack_empty;
//   s21_stack_empty = s21_stack_int;
//   std_stack_empty = std_stack_int;
//   EXPECT_EQ(s21_stack_empty.top(), std_stack_empty.top());
//   EXPECT_EQ(s21_stack_int.empty(), std_stack_int.empty());
// }

// TEST(Stack, Constructor_Move) {
//   s21::Stack<int> s21_stack = {1, 2, 3};
//   s21::Stack<int> s21_move(std::move(s21_stack));
//   std::stack<int> std_stack;
//   std_stack.push(1);
//   std_stack.push(2);
//   std_stack.push(3);
//   std::stack<int> std_move(std::move(std_stack));
//   EXPECT_EQ(s21_move.top(), std_move.top());
//   EXPECT_EQ(s21_stack.empty(), std_stack.empty());
// }

// TEST(Stack, Operator_Move) {
//   s21::Stack<int> s21_stack_int = {1, 2, 3};
//   std::stack<int> std_stack_int;
//   std_stack_int.push(1);
//   std_stack_int.push(2);
//   std_stack_int.push(3);
//   s21::Stack<int> s21_stack_empty;
//   std::stack<int> std_stack_empty;
//   s21_stack_empty = std::move(s21_stack_int);
//   std_stack_empty = std::move(std_stack_int);
//   EXPECT_EQ(s21_stack_empty.top(), std_stack_empty.top());
//   EXPECT_EQ(s21_stack_int.empty(), std_stack_int.empty());
// }

// TEST(Stack, Top) {
//   s21::Stack<int> s21_stack_int = {1, 2, 3};
//   std::stack<int> std_stack_int;
//   std_stack_int.push(1);
//   std_stack_int.push(2);
//   std_stack_int.push(3);
//   s21::Stack<double> s21_stack_double = {1.1f, 2.1f, 3.1f};
//   std::stack<double> std_stack_double;
//   std_stack_double.push(1.1f);
//   std_stack_double.push(2.1f);
//   std_stack_double.push(3.1f);
//   s21::Stack<std::string> s21_stack_string = {"abc", "def", "ghf"};
//   std::stack<std::string> std_stack_string;
//   std_stack_string.push("abc");
//   std_stack_string.push("def");
//   std_stack_string.push("ghf");
//   EXPECT_EQ(s21_stack_int.top(), std_stack_int.top());
//   EXPECT_EQ(s21_stack_double.top(), std_stack_double.top());
//   EXPECT_EQ(s21_stack_string.top(), std_stack_string.top());
// }

// TEST(Stack, Empty) {
//   s21::Stack<int> s21_stack_int = {1, 2, 3};
//   std::stack<int> std_stack_int;
//   std_stack_int.push(1);
//   std_stack_int.push(2);
//   std_stack_int.push(3);
//   EXPECT_EQ(s21_stack_int.empty(), std_stack_int.empty());
//   s21::Stack<int> s21_stack_empty;
//   std::stack<int> std_stack_empty;
//   EXPECT_EQ(s21_stack_empty.empty(), std_stack_empty.empty());
// }

// TEST(Stack, Size) {
//   s21::Stack<int> s21_stack_int = {1, 2, 3};
//   std::stack<int> std_stack_int;
//   std_stack_int.push(1);
//   std_stack_int.push(2);
//   std_stack_int.push(3);
//   EXPECT_EQ(s21_stack_int.size(), std_stack_int.size());
//   s21::Stack<int> s21_stack_empty;
//   std::stack<int> std_stack_empty;
//   EXPECT_EQ(s21_stack_empty.size(), std_stack_empty.size());
// }

// TEST(Stack, Push) {
//   s21::Stack<int> s21_stack_int;
//   s21_stack_int.push(1);
//   s21_stack_int.push(2);
//   s21_stack_int.push(3);
//   std::stack<int> std_stack_int;
//   std_stack_int.push(1);
//   std_stack_int.push(2);
//   std_stack_int.push(3);
//   EXPECT_EQ(s21_stack_int.top(), std_stack_int.top());
// }

// TEST(Stack, Pop) {
//   s21::Stack<int> s21_stack_int;
//   s21_stack_int.push(1);
//   s21_stack_int.push(2);
//   s21_stack_int.push(3);
//   s21_stack_int.pop();
//   std::stack<int> std_stack_int;
//   std_stack_int.push(1);
//   std_stack_int.push(2);
//   std_stack_int.push(3);
//   std_stack_int.pop();
//   EXPECT_EQ(s21_stack_int.top(), std_stack_int.top());
//   s21_stack_int.pop();
//   s21_stack_int.pop();
//   std_stack_int.pop();
//   std_stack_int.pop();
//   EXPECT_EQ(s21_stack_int.empty(), std_stack_int.empty());
// }

// TEST(Stack, Swap) {
//   s21::Stack<int> s21_stack_int = {1, 2, 3};
//   std::stack<int> std_stack_int;
//   std_stack_int.push(1);
//   std_stack_int.push(2);
//   std_stack_int.push(3);
//   s21::Stack<int> s21_stack_empty;
//   std::stack<int> std_stack_empty;
//   s21_stack_empty.swap(s21_stack_int);
//   std_stack_empty.swap(std_stack_int);
//   EXPECT_EQ(s21_stack_empty.top(), std_stack_empty.top());
//   EXPECT_EQ(s21_stack_int.empty(), std_stack_int.empty());
// }

// TEST(Stack, InsertManyFront) {
//   s21::Stack<int> s21_stack_int;
//   s21_stack_int.insert_many_back(1, 2, 3);
//   EXPECT_EQ(s21_stack_int.top(), 3);
// }

int main(int argc, char **argv) {
  try {
    ::testing::InitGoogleTest(&argc, argv);
  } catch (const char *error_message) {
    std::cout << error_message << std::endl;
  }
  return RUN_ALL_TESTS();
}

// #endif  // TESTLISTCONTEINERS_H