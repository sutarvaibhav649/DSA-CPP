#ifndef CIRCULAR_LINKED_LIST_H
#define CIRCULAR_LINKED_LIST_H

#include <iostream>
template <class T>
class CircularLinkedList
{
    private:
            class Node{
                public:
                    T data;
                    Node *next;
                    Node(T data) : data(data),next(nullptr){}
            };

            Node *tail;
    public:
        CircularLinkedList();
        CircularLinkedList(const CircularLinkedList&) = delete;
        CircularLinkedList& operator=(const CircularLinkedList&) = delete;
        void insertAtHead(T data);
        void insertAtEnd(T data);
        void insertAtPosition(T Data,int position);

        T deleteFromHead();
        T deleteFromEnd();
        T deleteFromPosition(int position);

        void displayList();
        bool isPresent(T data);
        ~CircularLinkedList();
};

#include "../implementation/CircularLinkedList.cpp"
#endif