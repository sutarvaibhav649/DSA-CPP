#include <iostream>
#include <stdexcept>
#include "../include/SinglyLinkedList.h"

template <class T>
SinglyLinkedList<T>::SinglyLinkedList(){
    this->head = nullptr;
}

template <class T>
void SinglyLinkedList<T>::insertAtHead(T data){
    Node *newNode = new Node(data);
    newNode->next = head;
    head = newNode;
}

template <class T>
void SinglyLinkedList<T>::insertAtEnd(T data){
    if (head == nullptr)
    {
        insertAtHead(data);
        return;
    }
    
    Node *newNode = new Node(data);
    Node *temp = head;

    while (temp->next != nullptr)
    {
        temp = temp->next;
    }

    temp->next = newNode;    
}

template <class T>
void SinglyLinkedList<T>::insertAtPosition(T data,int pos){
    if (pos <= 0)
    {
        throw std::runtime_error("Invalid Position");
    }

    if (pos == 1)
    {
        insertAtHead(data);
        return;
    }

    Node *newNode = new Node(data);
    Node *temp = head;
    for (int i = 1; i < pos - 1 && temp != nullptr; i++)
    {
        temp = temp->next;
    }


    if (temp == nullptr)
    {
        throw std::runtime_error("Invalid Position");
    }
    

    if (temp->next == nullptr)
    {
        insertAtEnd(data);
        return;
    }
            
    newNode->next = temp->next;
    temp->next = newNode;
    return;
}

template <class T>
T SinglyLinkedList<T>::deleteFromHead(){
    if (head == nullptr)
    {
        throw std::runtime_error("List is Empty");
    }
    
    Node *temp = head;
    head = head->next;
    temp->next = nullptr;
    T data = temp->data;
    delete temp;
    return data;
}


template <class T>
T SinglyLinkedList<T>::deleteFromEnd(){
    if (head == nullptr)
    {
        throw std::runtime_error("List is Empty");
    }
    
    if (head->next == nullptr)
    {
        T data = deleteFromHead();
        return data;
    }
    
    Node *temp = head;
    Node *prev = nullptr;
    while (temp->next != nullptr)
    {
        prev = temp;
        temp = temp->next;
    }

    T data = temp->data;
    prev->next = nullptr;
    delete temp; 
    return data;      
}

template <class T>
T SinglyLinkedList<T>::deleteFromPosition(int pos){
    if (pos <= 0)
    {
        throw std::runtime_error("Invalid position");
    }
    
    if (pos == 1)
    {
        T data = deleteFromHead();
        return data;
    }
    
    Node *temp = head;
    Node *prev = nullptr;
    for (int i = 1; i < pos && temp != nullptr; i++)
    {
        prev = temp;
        temp = temp->next;
    }

    if (temp == nullptr) throw std::runtime_error("Position out of bounds");

    T data = temp->data;
    prev->next = temp->next;
    temp->next = nullptr;
    delete temp;
    return data;
}

template <class T>
void SinglyLinkedList<T>::displayList(){
    if (head == nullptr)
    {
        std::cout << "List is Empty" << std::endl;
        return;
    }

    Node *temp = head;
    while (temp != nullptr)
    {
        std::cout << temp->data << "-->";
        temp = temp->next;
    }
    std::cout << "NULL" << std::endl;
}

template <class T>
bool SinglyLinkedList<T>::isPresent(T data){
    Node *temp = head; 
    while (temp != nullptr)
    {
        if (temp->data == data) return true;
        temp = temp->next;
    }
    return false; 
}

template <class T>
SinglyLinkedList<T>::~SinglyLinkedList() {
    while (head != nullptr) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }
}