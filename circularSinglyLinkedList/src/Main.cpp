#include <iostream>
#include "../include/CircularLinkedList.h"

int main(){
    CircularLinkedList<int> myList;

    int choice,data,position,target,deletedData;
    
    while (true)
    {
        std::cout << "===============================================" << std::endl;
        std::cout << "1. Insert At Start" << std::endl;
        std::cout << "2. Insert At End" << std::endl;
        std::cout << "3. Insert At Position" << std::endl;
        std::cout << "4. Delete From Start" << std::endl;
        std::cout << "5. Delete From End" << std::endl;
        std::cout << "6. Delete From Position" << std::endl;
        std::cout << "7. Display List" << std::endl;
        std::cout << "8. Is Element Present" << std::endl;
        std::cout << "9. Exit" << std::endl;
        std::cout << "===============================================" << std::endl;
        std::cout << "Enter you option: ";
        std::cin >> choice;
        switch (choice)
        {
        case 1:
            std::cout << "Data: ";
            std::cin >> data;
            myList.insertAtHead(data);
            break;
        
        case 2:
            std::cout << "Data: ";
            std::cin >> data;
            myList.insertAtEnd(data);
            break;
        
        case 3:
            std::cout << "Data: ";
            std::cin >> data;
            std::cout << "Position: ";
            std::cin >> position;
            myList.insertAtPosition(data,position);
            break;

        case 4:
            deletedData = myList.deleteFromHead();
            std::cout << "Deleted Data: " << deletedData << std::endl;
            break;
        
        case 5:
            deletedData = myList.deleteFromEnd();
            std::cout << "Deleted Data: " << deletedData << std::endl;
            break;
        
        case 6:
            std::cout << "Position: ";
            std::cin >> position;
            deletedData = myList.deleteFromPosition(position);
            std::cout << "Deleted Data: " << deletedData << std::endl;
            break;
        
        case 7:
            myList.displayList();
            break;
        
        case 8:
            std::cout << "Target: ";
            std::cin >> target;
            if (myList.isPresent(target))
            {
                std::cout << "true" << std::endl;
            }else{
                std::cout << "false" << std::endl;
            }
            break;
        
        case 9:
            std::cout << "Exiting program ..." << std::endl;
            exit(0);
            break;
        
        default:
            std::cout << "❌❌ Invalid Option ❌❌" << std::endl;
            std::cout << "🔄️🔄️Please try again🔄️🔄️" << std::endl;
        }
    }
}