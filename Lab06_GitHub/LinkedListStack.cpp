#include <iostream>
#include <chrono>

using namespace std;
using namespace std::chrono;

// Node structure for the stack
struct Node {
    int data;
    Node* next;
};

Node* top = NULL;  // pointer to the top node of the stack
int Size = 0;   // current size of the stack
int capacity; // maximum capacity of the stack

// Push function to add an element to the stack
void Push(int data) {
    if (Size >= capacity) {
        cout << "Stack Overflow\n";
        return;
    }
    Node* newNode = new Node();
    newNode->data = data;
    newNode->next = top;
    top = newNode;
    Size++;
}

// Pop function to remove the top element from the stack
void Pop() {
    if (top == NULL) {
        cout << "Stack Underflow\n";
        return;
    }
    Node* temp = top;
    cout << "Popped element : " << top -> data << endl;

    top = top->next;
    delete temp;
    Size--;
}

// StackTop function to get the top element of the stack
int StackTop() {
    if (top == NULL) {
        cout << "Stack is empty\n";
        return -1;
    }
    return top->data;
}

bool isEmpty() {
  return top == NULL; //Return true or false
}

// Display function to print the elements of the stack
void Display() {
    if (top == NULL) {
        cout << "Stack is empty\n";
        return;
    }
    Node* temp = top;
    cout << "Stack: ";
    while (temp != NULL) {
        
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

// isFull function to check if the stack is full
bool isFull() {
    return (Size == capacity);
}

// main function to test the implementation
int main() {
    capacity = 50;

    auto start = high_resolution_clock::now();
    Push(8);
    Push(10);
    Push(5);

    Pop();
    Pop();
    Pop();
    Pop();
    Pop();

    Push(11);
    Push(15);
    Push(23);
    cout << "Stack top: " << StackTop() << std::endl; // Stack top: 23

    Push(6);
    Push(18);   //8 10 5 11 15 23 6 18
    Push(20);   //Stack Overflow
    Push(17);   //Stack Overflow
    Display();  //Stack: 18 6 23 15 11 5 10 8

    //Popping 5 times
    Pop();
    Pop();
    Pop();
    Pop();
    Pop();
    Display();  //Stack: 5 10 8

    Pop();
    Pop();
    Pop();
    Pop();
    Pop();
    
    Push(4);
    Push(30);
    cout << "Stack top: " << StackTop() << std::endl; // Stack top: 30
    Push(3);
    Push(1);
    Display();  //Stack: 1 3 30 4 5 10 8

    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);

    cout << "Time taken by function: " << duration.count() << " microseconds" << endl;
    return 0;
}
