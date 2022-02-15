﻿// P4_reverse_linked_list.cpp : 此檔案包含 'main' 函式。程式會於該處開始執行及結束執行。
//

#include <iostream>
#include <vector>
#include <algorithm>

template<typename T>
class Node
{
public:
   T data;
   Node* next;
   Node* prev;

   Node(T d) {
      data = d;
      next = NULL;
      prev = NULL;
   }
};

template<typename T>
class NodeList
{
private:
   Node<T>* head;
   Node<T>* current;
public:
   NodeList() {
      head = NULL;
      current = head;
   }
   Node<T>* begin() {
      return head;
   }
   void push(T d) {
      if (head == NULL) {
         head = new Node<T>(d);
         current = head;
         return;
      }
      current->next = new Node<T>(d);
      current = current->next;
   }
   void reverse_list() {
      Node<T>* prev_node = head;
      head = head->next;
      Node<T>* next_node;

      prev_node->next = NULL;
      while (head) {
         next_node = head->next;
         head->next = prev_node;
         prev_node = head;
         head = next_node;
      }
      head = prev_node;
   }
};


template<typename T>
class DoublelyLinkedNodeList:public NodeList<T>
{
private:
   Node<T>* head;
   Node<T>* current;
public:
   DoublelyLinkedNodeList() {
      head = NULL;
      current = head;
   }
   Node<T>* begin() {
      return head;
   }
   void push(T d) {
      if (head == NULL) {
         head = new Node<T>(d);
         current = head;
         return;
      }
      current->next = new Node<T>(d);
      current->next->prev = current;
      current = current->next;
   }
   void reverse_list() {
      Node<T>* prev_node = head;
      head = head->next;
      Node<T>* next_node;

      prev_node->next = NULL;
      while (head) {
         next_node = head->next;
         head->next = prev_node;
         head->prev = next_node;
         prev_node = head;
         head = next_node;
      }
      head = prev_node;
   }
};
int main()
{
   NodeList<int> A;
   size_t vector_length = 20;
   for (size_t i = 0; i < vector_length; i++) {
      A.push(rand() % 20);
   }

   std::cout << std::endl << "Linked List A:" << std::endl;
   auto current = A.begin();
   for (size_t i = 0; i < vector_length; i++) {
      std::cout << current->data << ' ';
      current = current->next;
   }
   std::cout << std::endl << "Reverse linked list:" << std::endl;
   A.reverse_list();

   current = A.begin();
   for (size_t i = 0; i < vector_length; i++) {
      std::cout << current->data << ' ';
      current = current->next;
   }

   std::cout << std::endl;

   DoublelyLinkedNodeList<int> B;
   for (size_t i = 0; i < vector_length; i++) {
      B.push(rand() % 20);
   }

   std::cout << std::endl << "Doubly Linked List B:" << std::endl;
   current = B.begin();
   for (size_t i = 0; i < vector_length; i++) {
      std::cout << current->data << ' ';
      current = current->next;
   }
   std::cout << std::endl << "Reverse linked list:" << std::endl;
   B.reverse_list();

   current = B.begin();
   for (size_t i = 0; i < vector_length; i++) {
      std::cout << current->data << ' ';
      current = current->next;
   }

}

// 執行程式: Ctrl + F5 或 [偵錯] > [啟動但不偵錯] 功能表
// 偵錯程式: F5 或 [偵錯] > [啟動偵錯] 功能表

// 開始使用的提示: 
//   1. 使用 [方案總管] 視窗，新增/管理檔案
//   2. 使用 [Team Explorer] 視窗，連線到原始檔控制
//   3. 使用 [輸出] 視窗，參閱組建輸出與其他訊息
//   4. 使用 [錯誤清單] 視窗，檢視錯誤
//   5. 前往 [專案] > [新增項目]，建立新的程式碼檔案，或是前往 [專案] > [新增現有項目]，將現有程式碼檔案新增至專案
//   6. 之後要再次開啟此專案時，請前往 [檔案] > [開啟] > [專案]，然後選取 .sln 檔案
