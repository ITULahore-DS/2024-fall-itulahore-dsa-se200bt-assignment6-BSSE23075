#include "functions.h"

int main() {
    cout << "-----------------------(Welcome to Assignment 6)-----------------------" << endl;
//    Stack stack;
//    stack.push(1);
//    stack.push(2);
//    stack.push(3);
//    stack.push(4);
//    stack.printStack();
//    stack.clear();
//    stack.printStack();

    Queue queue;
    queue.enqueue(1);
    queue.enqueue(2);
    queue.enqueue(3);
    queue.enqueue(4);
    queue.printQueue();
    return 0;
}