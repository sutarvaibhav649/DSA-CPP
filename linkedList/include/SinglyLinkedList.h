#ifndef SINGLY_LINKED_LIST_H
#define SINGLY_LINKED_LIST_H

#include <iostream>

template <class T>
    class SinglyLinkedList
    {
        private:
            class Node {
                public:
                    T data;
                    Node *next;
                    Node(T data) : data(data),next(nullptr) {}
            };
            Node *head;
        public:
            
            SinglyLinkedList();
            SinglyLinkedList(T data);
            SinglyLinkedList(const SinglyLinkedList&) = delete;
            SinglyLinkedList& operator=(const SinglyLinkedList&) = delete;
            void insertAtHead(T data);
            void insertAtPosition(T data,int position);
            void insertAtEnd(T data);
            T deleteFromHead();
            T deleteFromPosition(int data);
            T deleteFromEnd();
            void displayList();
            bool isPresent(T data);
            ~SinglyLinkedList();
    };

#include "../implementation/SinglyLinkedList.cpp"
#endif