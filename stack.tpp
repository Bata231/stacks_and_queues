//
// Created by Booboos on 4/29/2025.
//
#include <stdio.h>
#include "stack.h"

template <typename ItemType>
Stack<ItemType>::Stack() {
  head = nullptr;
}

template <typename ItemType>
Stack<ItemType>::~Stack() {
  this->clear();
}

template <typename ItemType>
ItemType Stack<ItemType>::peek() {
     Node* current = head;
      while (current != nullptr) {
        current = current->next;
      }
      return current->data;
}

template <typename ItemType>
ItemType Stack<ItemType>::pop() {
  int nodeCount = 0;
  for (Node* current = head; current->next != nullptr; current = current->next) {
    nodeCount++;
  }
  Node* current = head;
  for (int i = 0; i != nodeCount - 1; i++) {
    current = current->next;
  }
  const Node* removeNode = current->next;
  const Node* poppedNode = removeNode;
  Node* reconnectNode = current->next->next;
  current->next = reconnectNode;
  delete removeNode;
  return poppedNode->data;
}

template <typename ItemType>
void Stack<ItemType>::push(ItemType item) {
  Node *newNode = new Node(item);
  if (head == nullptr) {
    head = newNode;
  } else {
    Node* current = head;

    for (current = head; current->next != nullptr; current = current->next) {}
    current->next = newNode;
  }
}

template <typename ItemType>
void Stack<ItemType>::operator +=(ItemType item) {
  Node *newNode = new Node(item);
  if (head == nullptr) {
    head = newNode;
  } else {
    Node* current = head;

    for (current = head; current->next != nullptr; current = current->next) {}
    current->next = newNode;
  }
}

template <typename ItemType>
void Stack<ItemType>::operator -=(ItemType item) {
  if (head == nullptr) {
    throw std::invalid_argument("list is empty");
  }
  Node *current = head;
  int nodeCount = 0;

  while (current->next != nullptr && current->data != item) {
    current = current->next;
    nodeCount++;
  }

  if (current == nullptr) {
    throw std::invalid_argument("Item not found");
  } else if (current == head) {
      head = head->next;
      delete current;
  } else {
      current = head;
      for (int i = 0; i != nodeCount - 1; i++) {
        current = current->next;
      }
    const Node* removeNode = current->next;
    Node* reconnectNode = current->next->next;
    current->next = reconnectNode;
    delete removeNode;
  }
}

template <typename ItemType>
int Stack<ItemType>::size() const  {
  int size = 0;
  for (Node* current = head; current != nullptr; current = current->next) {
    size++;
  }
  return size;
}

template <typename ItemType>
void Stack<ItemType>::clear() {
  while (head != nullptr) {
    *this -= head->data;
  }
}

template <typename ItemType>
bool Stack<ItemType>::isEmpty() const {
  return head == nullptr;
}

template <typename ItemType>
Stack<ItemType>::Node::Node(ItemType item) {
  this->data = item;
  this->next = nullptr;
}

template <typename ItemType>
Stack<ItemType>::Node::~Node() = default;