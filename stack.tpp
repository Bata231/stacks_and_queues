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
ItemType Stack<ItemType>::peek() {
     Node* current = head;
      while (current != nullptr) {
        current = current->next;
      }
      return current->data;
}

template <typename ItemType>
ItemType Stack<ItemType>::pop() {
  Node* current = head;
  for (int nodeCount = 0; nodeCount < Size() - 1; current = current->next) {
      current = current->next;
  }
  Node* removeNode = current->next;
  current->next = nullptr;
  return removeNode->data;
}

template <typename ItemType>
void Stack<ItemType>::push(ItemType item) {
  Node *newNode = new Node(item);
  if (head == nullptr) {
    head = newNode;
  } else {
    Node* current = head;

    for (current = head; current != nullptr; current = current->next) {}
    current->next = newNode;
  }
}

template <typename ItemType>
int Stack<ItemType>::size()  {
  int size = 0;
  for (Node* current = head; current != nullptr; current = current->next) {
    size++;
  }
  return size;
}

template <typename ItemType>
void Stack<ItemType>::clear() {
  Node *current = head;

  while (current != nullptr) {

    const Node *secPointer = current;

    current = current->getNextNode();
    delete secPointer;
  }
}

template <typename ItemType>
bool Stack<ItemType>::isEmpty() {
  return head == nullptr;
}

template <typename ItemType>
Stack<ItemType>::Node::Node(ItemType item) {
  this->data = item;
  this->next = nullptr;
}

template <typename ItemType>
Stack<ItemType>::Node::~Node(ItemType item) {

}