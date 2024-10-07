//
// Created by Kollo Szende-Roberta on 10/7/2024.
//

#include "Stack.h"
using namespace std;

Stack::Stack() : topNode1(nullptr), nodeCounter1(0) {
}

Stack::~Stack() {
    if(isEmpty())
    {
        cout<<"The stack is empty";
    }
    while(!isEmpty())
    {
        pop();
    }

}

bool Stack::isEmpty() const {
    return nodeCounter1 == 0;
}

int Stack::pop() {
    if(isEmpty())
    {
        cout<<"The stack is empty";
    }
    int value = topNode1->value1;
    Node1 *oldTop = topNode1;
    topNode1 =   topNode1->next1;
    delete oldTop;
    nodeCounter1--;
    return value;
}

void Stack::print() const {
    Node1 *current = topNode1;
    while(current!= nullptr)
    {
        cout<< current->value1<<" ";
        current =  current->next1;
    }
    cout<<endl;

}

void Stack::push(int e) {
   topNode1 =new Node1(e, topNode1);
   nodeCounter1++;
}

int Stack::size() const {
    return nodeCounter1;
}

int Stack::top() const {
    if(isEmpty())
    {
        cout<<"The stack is empty";
    }

    return topNode1->value1;
}
