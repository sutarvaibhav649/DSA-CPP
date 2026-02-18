#ifndef CIRCULAR_DOUBLY_LINKED_LIST_H
#define CIRCULAR_DOUBLY_LINKED_LIST_H

template <class T>
class CircularDoublyLinkedList
{
    private:
        class Node{
            public:
                T data;
                Node *next;
                Node *prev;
                Node(T data): data(data),next(nullptr),prev(nullptr){}
        };
        Node *tail;
    public:
        CircularDoublyLinkedList(/* args */);
        CircularDoublyLinkedList(const CircularDoublyLinkedList&) = delete;
        CircularDoublyLinkedList& operator=(const CircularDoublyLinkedList&) = delete;
        void insertAtHead(T data);
        void insertAtEnd(T data);
        void insertAtPosition(T data,int position);
        T deleteFromStart();
        T deleteFromEnd();
        T deleteFromPosition(int position);
        void displayList();
        bool isPresent(T data);
        ~CircularDoublyLinkedList();
};

#include "../implementation/CircularDoublyLinkedList.cpp"
#endif