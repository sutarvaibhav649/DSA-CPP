#include <iostream>
#include <stdexcept>
#include "../include/DoublyLinkedList.h"

template <class T>
DoublyLinkedList<T>::DoublyLinkedList(){
    this->head = nullptr;
}

template <class T>
void DoublyLinkedList<T>::insertAtHead(T data){
    Node *newNode = new Node(data);
    if (head == nullptr)
    {
        head = newNode;
    }else{
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
    }
    
}

template <class T>
void DoublyLinkedList<T>::insertAtEnd(T data){
    if(head == nullptr){
        insertAtHead(data);
        return;
    }

    Node *temp = head;

    while (temp->next != nullptr)
    {
        temp = temp->next;
    }
    
    Node *newNode = new Node(data);
    newNode->prev = temp;
    temp->next = newNode;
}

template <class T>
void DoublyLinkedList<T>::insertAtPosition(T data,int pos){
    if (pos <= 0)
    {
        throw std::runtime_error("Invalid Position");
    }

    if (pos == 1)
    {
        insertAtHead(data);
        return;
    }
    
    Node *temp = head;
    for (int i = 1; i < pos-1 && temp != nullptr; i++)
    {
        temp = temp->next;
    }
    
    if (temp == nullptr)
    {
        throw std::runtime_error("Position out of Bound");
    }

    if(temp->next == nullptr){
        insertAtEnd(data);
        return;
    } 
    
    Node *newNode = new Node(data);
    newNode->next = temp->next;
    temp->next->prev = newNode;
    newNode->prev = temp;
    temp->next = newNode;
}

template <class T>
T DoublyLinkedList<T>::deleteFromHead(){
    if (head == nullptr)
    {
        throw std::runtime_error("Empty List");
    }

    if (head->next == nullptr)
    {
        T data = head->data;
        delete head;
        return data;
    }

    Node *temp = head;
    T data = head->data;
    head = head->next;
    head->prev = nullptr;
    delete temp;
    return data;
}

template <class T>
T DoublyLinkedList<T>::deleteFromEnd(){
    if (head == nullptr)
    {
        throw std::runtime_error("Empty List");
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
    temp->prev = nullptr;
    delete temp;
    return data;
}

template <class T>
T DoublyLinkedList<T>::deleteFromPosition(int pos){
    if (pos<=0)
    {
        throw std::runtime_error("Invalid Position");
    }

    if (pos == 1)
    {
        T data = deleteFromHead();
        return data;
    }

    Node *temp = head;
    Node *prev = nullptr;
    for (int i = 1; i <= pos && temp != nullptr; i++)
    {
        prev = temp;
        temp = temp->next;
    }

    if (temp == nullptr)
    {
        throw std::runtime_error("Position out of Bound");
    }

    if (temp->next == nullptr)
    {
        T data = deleteFromEnd();
        return data;
    }

    T data = temp->data;
    prev->next = temp->next;
    temp->next->prev = prev;
    delete temp;
    return data;     
}

template <class T>
void DoublyLinkedList<T>::displayList(){
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
bool DoublyLinkedList<T>::isPresent(T data){
    if (head == nullptr)
    {
        std::cout << "List is Empty" << std::endl;
        return false;
    }
    Node *temp = head;
    while (temp != nullptr)
    {
        if (temp->data == data)
        {
            return true;
        }
        
        temp = temp->next;
    }
    return false;
}

template <class T>
DoublyLinkedList<T>::~DoublyLinkedList(){
    while (head != nullptr)
    {
        Node *temp = head;
        head = head->next;
        delete temp;
    }
    std::cout << "All Nodes deleted Successfully" << std::endl;
}
