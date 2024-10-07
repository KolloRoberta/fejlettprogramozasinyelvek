#include <iostream>
#include "List.h"
#include "Stack.h"

using namespace std;

int main() {
    /* List list;
     for (int i = 0; i < 10; ++i) {
         list.insertFirst(i);
         list.print();
     }
     cout<<"Torlesek utan "<<endl;
     list.remove(1, List::DeleteFlag::LESS);
     list.print();
     list.remove(1, List::DeleteFlag::GREATER);
     list.print();
     list.remove(6, List::DeleteFlag::EQUAL);
     list.print();*/


    ////stack///
    Stack stack;
    for (int i = 0; i < 10; ++i) {
        stack.push(i);
        stack.print();

    }
    cout << endl;
    ///a stack felet eltavolitani///
    int stackSize = stack.size();
    if (stackSize == 0) {
        cout << "The stack is empty ";
        return 0;
    }
    int halfSize = stackSize / 2;
    Stack temp;
    for (int i = 0; i < halfSize; ++i) {
        temp.push(stack.pop());
    }

    stack.print();

    cout<<endl;
    ///a stack kozep elemet eltavolitani///

    int stackSize1 =stack.size();
    if(stackSize1 == 0)
    {
        cout<<"The stack is is empty ";
    }
    int middleIndex = stackSize1 /2;
    Stack t;
    for (int i = 0; i < middleIndex; ++i) {
        t.push(stack.pop());
    }
    stack.pop();
    while (!t.isEmpty()) {
        stack.push(t.pop());
    }

    stack.print();

    return 0;
}
