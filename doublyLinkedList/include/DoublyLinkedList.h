#ifndef DOUBLY_LINKED_LIST_H
#define DOUBLY_LINKED_LIST_H

#include <iostream>

template <class T>
    class DoublyLinkedList
    {
        private:
            class Node {
                public:
                    T data;
                    Node *next;
                    Node *prev;
                    Node(T data) : data(data),next(nullptr),prev(nullptr) {}
            };
            Node *head;
        public:
            
            DoublyLinkedList();
            DoublyLinkedList(T data);
            DoublyLinkedList(const DoublyLinkedList&) = delete;
            DoublyLinkedList& operator=(const DoublyLinkedList&) = delete;
            void insertAtHead(T data);
            void insertAtPosition(T data,int position);
            void insertAtEnd(T data);
            T deleteFromHead();
            T deleteFromPosition(int data);
            T deleteFromEnd();
            void displayList();
            bool isPresent(T data);
            ~DoublyLinkedList();
    };

#include "../implementatin/DoublyLinkedList.cpp"
#endif