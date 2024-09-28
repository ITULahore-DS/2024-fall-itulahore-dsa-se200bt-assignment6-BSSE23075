#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <iostream>

using namespace std;

class Node {
    int data;
    Node *next;

public:
    // constructor
    Node();

    // methods
    void setNext(Node *val);

    Node *getNext() const;

    void setData(int newData);

    int getData() const;

};

class Stack {
    Node *top;
    int count;
public:
    Stack();

    ~Stack();

    bool isEmpty();

    void push(int newData);

    int pop();

    int peek();

    int size();

    void clear();

    void printStack();

    void print(Node* t);

};

class Queue{
    Node* iback;
    Node* ifront;
    int count;
public:
    Queue();

    ~Queue();

    bool isEmpty();

    void enqueue(int newData);

    int dequeue();

    int size();

    void printQueue();

};

#endif


