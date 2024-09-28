//
// Created by DELL on 9/28/2024.
//
#include "functions.h"

// Node class

// constructor
Node::Node() : data(0), next(nullptr) {}

// getters and setters
int Node::getData() const {
    return data;
}

Node *Node::getNext() const {
    return next;
}

void Node::setData(int newData) {
    data = newData;
}

void Node::setNext(Node *val) {
    next = val;
}

// Stack Class

// constructor

Stack::Stack() : top(nullptr), count(0) {}

// destructor
Stack::~Stack() {
    while (top != nullptr) {
        Node *node = top->getNext();
        delete top;
        top = node;
    }
}

bool Stack::isEmpty() {
    if (top == nullptr) {
        return true;
    }
    return false;
}

// push function
void Stack::push(int newData) {
    Node *node = new Node();
    node->setData(newData);

    node->setNext(top);
    top = node;

    count += 1;
}

// pop function
int Stack::pop() {
    if (isEmpty()) {                  // if no elements
        cout << "Stack is Empty.." << endl;
        return -1;
    }
    int data = top->getData();
    Node *node = top;
    top = top->getNext();
    delete node;
    count -= 1;
    return data;
}

// peek function
int Stack::peek() {
    if (isEmpty()) {
        cout << "Stack is empty.." << endl;
        return -1;
    }
    return top->getData();
}

// getter
int Stack::size() {
    return count;
}

void Stack::clear() {

    while (top != nullptr) {
        Node *n = top->getNext();
        delete top;
        top = n;
    }
    count = 0;
}

void Stack::print(Node *t) {
    if (t == nullptr) {
        return;
    }
    print(t->getNext());   //printing through recursion so that order is corrected
    cout << t->getData() << ' ';
}

void Stack::printStack() {
    if (isEmpty()) {
        cout << "Stack is Empty.." << endl;
        return;
    }
//    Node *node = top;
//    int *arr = new int[count];
//    for (int i = count-1 ; i >= 0 && node != nullptr; i -= 1) {
//        arr[i] = node->getData();
//        node = node->getNext();
//    }
//    for (int i = 0; i < count; i += 1)
//        cout << arr[i] << ' ';
//    delete[] arr;
    print(top);
    cout << "\n";
}

// Queue class

// constructor
Queue::Queue() {
    iback = nullptr;
    ifront = nullptr;
    count = 0;
}

// destructor
Queue::~Queue() {
    while (ifront != nullptr) {
        Node *node = ifront->getNext();
        delete ifront;
        ifront = node;
    }
}

bool Queue::isEmpty() {
    if (ifront == nullptr) {
        return true;
    }
    return false;
}

// queue function
void Queue::enqueue(int newData) {
    Node *node = new Node();
    node->setData(newData);
    node->setNext(nullptr);
    if (isEmpty()) {
        iback = node;
        ifront = node;
    } else {
        iback->setNext(node);
        iback = node;
    }
    count += 1;
}


// dequeue function
int Queue::dequeue() {
    if (isEmpty()) {
        cout << "Queue is empty.." << endl;
        return -1;
    }
    int data = ifront->getData();
    Node *node = ifront;
    ifront = ifront->getNext();
    delete node;
    count -= 1;
    return data;
}

int Queue::size() {
    return count;
}

void Queue::printQueue() {
    for (Node *n = ifront; n; n = n->getNext())
        cout << n->getData() << ' ';
    
    cout << endl;
}