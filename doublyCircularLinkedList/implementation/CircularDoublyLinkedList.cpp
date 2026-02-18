# include <iostream>
# include <exception>
# include "../include/CircularDoublyLinkedList.h"

template <class T>
CircularDoublyLinkedList<T>::CircularDoublyLinkedList(){
    this->tail = nullptr;
}

template <class T>
void CircularDoublyLinkedList<T>::insertAtHead(T data){
    Node *newNode = new Node(data);
    if (tail == nullptr)
    {
        newNode->next = newNode;
        newNode->prev = newNode;
        tail = newNode;
    }
    else
    {
        newNode->next = tail->next;
        newNode->prev = tail;
        tail->next->prev = newNode;
        tail->next = newNode;
    }
    
}

template <class T>
void CircularDoublyLinkedList<T>::insertAtEnd(T data){
    if (tail == nullptr)
    {
        insertAtHead(data);
        return;
    }
    
    Node *newNode = new Node(data);
    newNode->next = tail->next;
    newNode->prev = tail;
    tail->next->prev = newNode;
    tail->next = newNode;
    tail = newNode;
}

template <class T>
void CircularDoublyLinkedList<T>::insertAtPosition(T data,int pos){
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
    for (int i = 1; i < pos - 1 && temp != tail; i++)
    {
        temp = temp->next;
    }
    
    if (temp == tail)
    {
        throw std::runtime_error("Invalid Position");   
    }

    Node *newNode = new Node(data);
    newNode->next = temp->next;
    newNode->prev = temp;
    temp->next->prev = newNode;
    temp->next = newNode;    
}

template <class T>
T CircularDoublyLinkedList<T>::deleteFromStart(){
    if (tail == nullptr)
    {
        throw std::runtime_error("Empty List");
    }
    if (tail->next == tail)
    {
        T data = tail->data;
        tail = nullptr;
        delete tail;
        return data;
    }

    Node *head = tail->next;
    Node *temp = head;
    head = head->next;
    head->prev = tail;
    tail->next = head;
    T data = temp->data;
    delete temp;
    return data;       
}

template <class T>
T CircularDoublyLinkedList<T>::deleteFromEnd(){
    if (tail == nullptr)
    {
        throw std::runtime_error("Empty List");
    }

    if (tail->next == tail)
    {
        T data = deleteFromStart();
        return data;
    }
    
    Node *head = tail->next;
    Node *temp = tail;
    T data = temp->data;
    tail = tail->prev;
    tail->next = head;
    head->prev = tail;
    delete temp;
    return data;
}

template <class T>
T CircularDoublyLinkedList<T>::deleteFromPosition(int pos){
    if (pos <= 0)
    {
        throw std::runtime_error("Invalid Position");
    }
    if (pos == 1)
    {
        T data = deleteFromStart();
        return data;
    }

    Node *temp = tail->next;
    for (int i = 1; i < pos - 1 && temp != tail; i++)
    {
        temp = temp->next;
    }
    
    if (temp == tail)
    {
        throw std::runtime_error("Invalid Position");
    }  
    Node *nodeToDelete = temp->next;
    if (nodeToDelete == tail)
    {
        T data = deleteFromEnd();
        return data;
    }
    
    T data = nodeToDelete->data;
    temp->next = nodeToDelete->next;
    nodeToDelete->next->prev = temp;
    delete nodeToDelete;
    return data;
}

template <class T>
void CircularDoublyLinkedList<T>::displayList(){
    if (tail == nullptr)
    {
        return;
    }

    Node *temp = tail->next;
    do
    {
        std::cout << temp->data << " --> ";
        temp = temp->next;
    } while (temp != tail->next);
    std::cout << "TAIL" << std::endl;
}

template <class T>
bool CircularDoublyLinkedList<T>::isPresent(T data){
    if (tail == nullptr)
    {
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
    } while (temp != tail->next);
    return false;
}

template <class T>
CircularDoublyLinkedList<T>::~CircularDoublyLinkedList(){
    Node *head = tail->next;
    head->prev = nullptr;
    tail->next = nullptr;
    while (head != nullptr)
    {
        Node *temp = head;
        head = head->next;
        delete temp;
    }
    std::cout << "All list deleted" << std::endl;
}