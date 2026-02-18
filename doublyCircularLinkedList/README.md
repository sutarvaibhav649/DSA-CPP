# Generic Circuler Doubly Linked List (C++ Templates)

A high-performance, template-based **Circuler Doubly Linked List** implementation. This project serves as a foundational component for a Data Structures and Algorithms (DSA) portfolio, demonstrating advanced C++ memory management and generic programming.



## Features

- **Generic Programming:** Implemented using C++ Templates to support any data type (`int`, `std::string`, etc.).
- **Dynamic Memory Management:** Custom destructor ensures zero memory leaks by cleaning up the Heap on object destruction.
- **Robust Error Handling:** Uses `std::runtime_error` to handle invalid positions and empty list operations.
- **Comprehensive API:**
  - `insertAtHead(T data)` / `insertAtEnd(T data)` / `insertAtPosition(T data, int pos)`
  - `deleteFromStart()` / `deleteFromEnd()` / `deleteFromPosition(int pos)`
  - `isPresent(T data)`: Search functionality.
  - `displayList()`: Formatted console output.

## Project Architecture

The project uses a modular "Tail-Only" style required for C++ Templates to ensure the compiler can instantiate types at runtime.

```text
.
├── include
│   └── CircularDoublyLinkedList.h         # Class & Node declarations
├── implementation
│   └── CircularDoublyLinkedList.cpp      # Template logic (Included in .h)
├── src
│   └── Main.cpp                  # Driver code / Testing
└── CMakeLists.txt                # Build configuration