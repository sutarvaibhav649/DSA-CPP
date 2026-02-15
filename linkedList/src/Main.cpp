#include<iostream>
#include "../include/SinglyLinkedList.h"


int main(){
    SinglyLinkedList<int> myList;

    myList.insertAtHead(30);
    myList.insertAtHead(20);
    myList.insertAtHead(10);
    std::cout << "Insert At Head: ";
    myList.displayList();
    myList.insertAtEnd(100);
    myList.insertAtEnd(200);
    myList.insertAtEnd(300);
    std::cout << "Insert At End: ";
    myList.displayList();
    myList.insertAtPosition(0,2);
    std::cout << "Insert At Position 2: ";
    myList.displayList();
    myList.insertAtPosition(1,7);
    std::cout << "Insert At Position 7: ";
    myList.displayList();
    myList.deleteFromHead();
    std::cout << "Delete from Head: ";
    myList.displayList();
    myList.deleteFromEnd();
    std::cout << "Delete from End: ";
    myList.displayList();
    myList.deleteFromPosition(5);
    std::cout << "Delete from Position 5: ";
    myList.displayList();

    bool isPresent = myList.isPresent(30);
    if (isPresent)
    {
        std::cout << "true" << std::endl;
    }else{
        std::cout << "false" << std::endl;
    }
    
}