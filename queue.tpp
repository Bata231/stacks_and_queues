//
// Created by Booboos on 4/29/2025.
//

#include <stdio.h>
#include "queue.h"

template <typename ItemType>
Queue<ItemType>::Queue() {
    head = nullptr;
}

template <typename ItemType>
ItemType Queue<ItemType>::peek() {
    return head->item;
}
template <typename ItemType>
Queue<ItemType>::~Queue() {
    this->clear();
}
template <typename ItemType>
void Queue<ItemType>::enqueue(ItemType item) {
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
ItemType Queue<ItemType>::dequeue() {
    Node* current = head;
    head = current->next;
    delete current;
    return head->data;
}

template <typename ItemType>
void Queue<ItemType>::operator +=(ItemType item) {
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
void Queue<ItemType>::operator -=(ItemType item) {
    if (head == nullptr) {
        throw std::invalid_argument("list is empty");
    }
    Node *current = head;
    int nodeCount = 0;
    while (current != nullptr && current->data != item) {
        current = current->next;
        nodeCount++;
    }

    if (current == nullptr) {
        throw std::invalid_argument("Item not found");
    } else if (current == head) {
        head = head->next;
        delete current;
    } else if (current->next == nullptr) {
        Node* removeLastNode = head;
        for (int i = 0; i < this->size() - 1; current = current->next) {
            removeLastNode = removeLastNode->next;
            i++;
        }
        removeLastNode->next = nullptr;
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
void Queue<ItemType>::clear() {
    while (head != nullptr) {
        *this -= head->data;
    }
}

template <typename ItemType>
int Queue<ItemType>::size() const  {
    int size = 0;
    for (Node* current = head; current != nullptr; current = current->next) {
        size++;
    }
    return size;
}
template <typename ItemType>
bool Queue<ItemType>::isEmpty() const {
    return head == nullptr;
}

template <typename ItemType>
    Queue<ItemType>::Node::Node(ItemType item) {
    this->data = item;
    this->next = nullptr;
}

template <typename ItemType>
Queue<ItemType>::Node::~Node() = default;