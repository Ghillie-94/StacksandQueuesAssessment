// William Kavanagh, CMP201.2022
// AX1.2 Partial Implementation

#include <iostream>
#include "StackAndQueue.h"

// Default constructor, init array
ArrayStack::ArrayStack()
{
    arr = new int[capacity];
}

// Remove first element, return value.
int ArrayStack::Pop()
{
    // TODO: ASSESSED [1]
    if (stackTop == 0)
    {
        return 0;
    }
    int value = arr[stackTop];
    stackTop--;
    return value;
}

// Check first element, return value.
int ArrayStack::Peek()
{
    int value = arr[stackTop];
    // TODO: ASSESSED [0.5]
    return value;
}

// Add element to top of stack, 
// calls DoubleArray() where appropriate
void ArrayStack::Push(int n)
{
    // TODO: ASSESSED [1]
    // [0.5] if correct without resizing.
    if (stackTop == capacity - 1)
    {
        DoubleArray();
    }
    stackTop++;
    arr[stackTop] = n;
    
}

// Print elements in Stack neatly
// DO NOT CHANGE: used for testing and assessment
void ArrayStack::Display()
{
    std::cout << arr[0] << "\t<- head" << std::endl;
    for (int i = 1; i < stackTop + 1; i++)
    {
        std::cout << arr[i] << std::endl;
    }
}

// Updates array pointer to new array of double the size
// elements are copied in from old array with position preserved.
void ArrayStack::DoubleArray()
{
    capacity *= 2;
    int* new_arr = new int[capacity];
    for (int i = 0; i < stackTop + 1; i++)
    {
        new_arr[i] = arr[i];
    }
    arr = new_arr;
}

// Node constructor
Node::Node(int n)
{
    next = nullptr;
    data = n;
}

// QL constructor
QueueList::QueueList()
{
    // TODO: ASSESSED [0.5]
    front = nullptr;
    back = nullptr;
}

// Add item to back of queue
void QueueList::Enqueue(int n)
{
    // TODO: ASSESSED [1]
    Node* temp = new Node(n);
    if (!front)
    {
        front = temp;
        back = temp;
    }
    else
    {
        back->next = temp;
        back = temp;
    }

}

// Remove item from front of queue
int QueueList::Dequeue()
{
    // TODO: ASSESSED [1]
    if (!front)
    {
        return 0;
    }
    Node* temp = front;
    int value = front->data;
    front = front->next;
    if (!front)
    {
        front = nullptr;
        back = nullptr;
    }
    return value;
}

// Print elements in Stack neatly
// DO NOT CHANGE: used for testing and assessment
void QueueList::Display()
{
    if (!front)
    {
        std::cout << "[]";
        return;
    }
    Node* n = front;
    std::cout << "f: ";
    while (n != back)
    {
        std::cout << n->data << ",\t";
        n = n->next;
    }
    std::cout << "b: " << n->data << std::endl;
}

