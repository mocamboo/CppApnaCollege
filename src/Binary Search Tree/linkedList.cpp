
#include <__config>
#include <iostream>
#include <ostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    // Default Constructor
    Node() : data(0), next(nullptr) { cout << "Default constructor triggered... " << endl; }

    // Parameterized Constructor
    Node(int data) : data(data), next(nullptr) { cout << "Parameterized constructor triggered... with data = " << data << endl; }

    // Copy Constructor
    Node(const Node& other) : data(other.data), next(other.next) { cout << "Copy constructor triggered... " << endl; }

    ~Node() { cout << "Destructor triggered... for node with data = " << data << endl; }
};

int main() {
    /*** Stack Allocation ***/
    // Constructor Calls - Default constructor called >> Destructor called for node with data = -1944335688
    Node b;

    /*** Dynamic (Heap) Allocation ***/
    /**
     Case 1
     Constructor Calls - Parameterized constructor called with data = 4 >> Copy constructor called >> Destructor called for node with data = 4
     */
    Node a = *new Node(4);

    /**
     Case 2
     Constructor Calls -  Parameterized constructor called with data = 4
     */
    Node* head = new Node(9);

    return 0;
}
