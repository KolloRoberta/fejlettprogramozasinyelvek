//
// Created by Kollo Szende-Roberta on 10/7/2024.
//

#ifndef LAB3_STACK_H
#define LAB3_STACK_H

#include <iostream>
#include <stdio.h>
class Stack {
public:
    Stack();

    ~Stack();
    ///returns true if the stack is empty
    bool isEmpty() const;
    ///returns the size of the stack
    int size() const;
    ///pushes an element onto the stack
    void push(int e);
    ////pops the top element from the stack
    int pop();
    ///visszaadja a legfelso elemet, anelkul, hogy eltavolitana
    int top()const;
    ////prints the contents of  the stack
    void print()const;

    Stack (const Stack&) =  delete;
    Stack& operator = (const Stack&) =  delete;

private:
    int nodeCounter1{0};
    struct Node1{
        int value1;
        Node1* next1;
        Node1(int v, Node1* n ):value1(v), next1(n){

        }
    };
    Node1  *topNode1;

};


#endif //LAB3_STACK_H
