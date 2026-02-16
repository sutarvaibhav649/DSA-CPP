#include <iostream>
#include <exception>
#include "../include/CircularLinkedList.h"

template <class T>
CircularLinkedList<T>::CircularLinkedList(){
    this->tail = nullptr;
}

template <class T>
void CircularLinkedList<T>::insertAtHead(T data){
    Node *newNode = new Node(data);
    if (tail == nullptr) {
        newNode->next = newNode;
        tail = newNode;
    } else {
        newNode->next = tail->next; 
        tail->next = newNode;      
    }
}

template <class T>
void CircularLinkedList<T>::insertAtEnd(T data){
    if (tail->next == nullptr)
    {
        insertAtHead(data);
        return;
    }

    Node *newNode = new Node(data);
    newNode->next = tail->next; 
    tail->next = newNode;       
    tail = newNode;  
}

template <class T>
void CircularLinkedList<T>::insertAtPosition(T data,int pos){
    if (pos <= 0)
    {
        throw std::runtime_error("Invalid Position");
    }

    if (pos == 1)
    {
        insertAtHead(data);
        return;
    }
    
    Node *temp = tail->next;
    for (int i = 1; i < pos-1 && temp != tail; i++)
    {
        temp = temp->next;
    }

    if (temp == tail)
    {
        insertAtEnd(data);
        return;
    }

    Node *newNode = new Node(data);
    newNode->next = temp->next;
    temp->next = newNode;           
}

template <class T>
T CircularLinkedList<T>::deleteFromHead(){
    if (tail == nullptr)
    {
        throw std::runtime_error("Empty List");
    }
    
    Node *head = tail->next;
    Node *temp = head;
    T data = head->data;
    head = head->next;
    tail->next = head;
    temp->next = nullptr;
    delete temp;
    return data;
}

template <class T>
T CircularLinkedList<T>::deleteFromEnd(){
    if (tail== nullptr)
    {
        throw std::runtime_error("Empty List");
    }

    if (tail->next == tail)
    {
        T data = tail->data;
        delete tail;
        return data;
    }
    
    Node *temp = tail->next;
    while (temp->next != tail)
    {
        temp = temp->next;
    }
    
    T data = tail->data;
    temp->next = tail->next;
    delete tail;
    tail = temp;
    return data;
}

template <class T>
T CircularLinkedList<T>::deleteFromPosition(int pos){
    if (pos <= 0)
    {
        throw std::runtime_error("Empty List");
    }

    if (pos == 1)
    {
        T data = deleteFromHead();
        return data;
    }
    

    Node *temp = tail->next;
    Node *prev = nullptr;
    for (int i = 1; i <= pos && temp != tail; i++)
    {
        prev = temp;
        temp = temp->next;
    }
    
    if (temp == tail)
    {
        T data = deleteFromEnd();
        return data;
    }
    
    T data = temp->data;
    prev->next = temp->next;
    temp->next = nullptr;
    delete temp;
    return data;
}

template <class T>
void CircularLinkedList<T>::displayList(){
    if (tail == nullptr)
    {
        std::cout << "List is empty" << std::endl;
        return;
    }

    Node *temp = tail->next;
    do
    {
        std::cout << temp->data << "-->";
        temp = temp->next;
    } while (temp != tail->next);
    std::cout << "TAIL" << std::endl;
}

template <class T>
bool CircularLinkedList<T>::isPresent(T data){
    if (tail == nullptr)
    {
        std::cout << "List is empty" << std::endl;
        return false;
    }

    Node *temp = tail->next;
    do
    {
        if (temp->data == data)
        {
            return true;
        }
        temp = temp->next;
    } while (temp != tail);
    return false;
}

template <class T>
CircularLinkedList<T>::~CircularLinkedList(){
    if (tail == nullptr) return;
    Node *current = tail->next;
    tail->next = nullptr;
    while (current != nullptr) {
        Node *temp = current;
        current = current->next;
        delete temp;
    }
}