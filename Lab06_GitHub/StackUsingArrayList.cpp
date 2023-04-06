/*
Operations performed with a Stack:
• Push() - To insert data into the stack
• Pop() - To remove/delete data from the stack
• isEmpty() - To check whethet a stack is empty or not
• isFull() - To check whethet a stack is full or not
• StackTop() - To find what is at the top of the stack
• Display() – To print elements in the stack
*/
#include <iostream>
#include <chrono>

using namespace std;
using namespace std::chrono;


const int MAX_SIZE = 8; // Initializing maximum size of the stack
int top = -1; // initialize top index to -1
int arr[MAX_SIZE]; // create an array to store stack elements

void Push(int element) {
  if (top >= MAX_SIZE - 1) {
    cout << "Stack Overflow\n";
  } else {
    top++;    //Incrementing top by 1
    arr[top] = element;
  }
}

bool isEmpty() {
  return top == -1; //Return true or false
}


void Pop() {
  if (isEmpty()){
    cout << "Stack Underflow\n";
  } else {
    int element = arr[top];
    top--;  //Decrementing top by 1
    cout << "Popped element : " << element << endl;
  }
}


bool isFull() {
  return top == MAX_SIZE - 1;   //Return true or false
  //isFull = true if top(last element) is in the last index
}

int StackTop() {
  if (isEmpty()) {
    cout << "Stack is empty\n";
    return -1;
  } else {
    return arr[top];
  }
}

void Display() {
  if (isEmpty()) {
    cout << "Stack is empty\n";
  } else {
    cout << "Stack: ";
    for (int i = top; i >= 0; i--) {
      cout << arr[i] << " ";
    }
    cout << endl;
  }
}

int main() {
    auto start = high_resolution_clock::now();
    Push(8);
    Push(10);
    Push(5);
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
