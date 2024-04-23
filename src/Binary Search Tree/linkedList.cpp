
#include <__config>
#include <iostream>
#include <ostream>
using namespace std;

class Node {
   public:
    int data;
    Node *next;

    // Default Constructor
    Node() : data(0), next(nullptr) {
        cout << "Default constructor called." << endl;
    }

    // Parameterized Constructor
    Node(int data) : data(data), next(nullptr) {
        cout << "Parameterized constructor called with data = " << data << endl;
    }

    // Copy Constructor
    Node(const Node &other) : data(other.data), next(other.next) {
        cout << "Copy constructor called." << endl;
    }

    ~Node() {
        cout << "Destructor called for node with data = " << data << endl;
    }
};

int main() {
    // Node b; // Stack Allocation [default cons]
    // Difference b/w Node a = *new Node(4);  and  Node* head = new Node(4);
    // Node a = *new Node(4); // >> Parameterised Con >> Copy Cons >> Destructur
    // Cons
    Node *head = new Node(4);  // Case 2

    //   delete head; // Clean up

    return 0;
}