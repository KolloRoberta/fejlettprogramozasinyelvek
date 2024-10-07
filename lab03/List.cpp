//
// Created by Kollo Szende-Roberta on 10/7/2024.
//

#include "List.h"
#include <stdio.h>
#include <iostream>

using namespace std;

List::List() : first(nullptr), nodeCounter(0) {}

List::~List() {
    while (first != nullptr) {
        Node *temp = first;
        first = first->next;
        delete temp;
    }
}

bool List::exists(int d) const {
    Node *current = first;
    while (current != nullptr) {
        if (current->value == d) {
            return true;
        }
        current = current->next;
    }
    return false;
}

int List::size() const {
    return nodeCounter;
}

bool List::empty() const {
    return nodeCounter == 0;
}

void List::insertFirst(int d) {
    /* Node *newelement = new Node(d, first);
     first = newelement;
     ++nodeCounter;*/

    first = new Node(d, first);
    ++nodeCounter;

}

int List::removeFirst() {
    if (empty()) {
        cout << "Uress";
    }
    int value = first->value;
    Node *temp = first;
    first = first->next;

    delete temp;
    nodeCounter--;
    return value;
}

void List::print() const {
    Node *current = first;
    while (current != nullptr) {
        cout << current->value << " ";
        current = current->next;
    }
    cout << endl;
}

void List::remove(int d, List::DeleteFlag df) {
    if (empty()) {
        cout << "Uress";
    }
    Node *current = first;
    Node *previous = nullptr;

    while (current != nullptr) {
        bool match = false;
        switch (df) {
            case DeleteFlag::LESS:
                match = (current->value < d);
                break;
            case DeleteFlag::EQUAL:
                match = (current->value == d);
                break;
            case DeleteFlag::GREATER:
                match = (current->value > d);
                break;
        }
        if (match) {
            if (previous == nullptr) {
                first = current->next;
            } else {
                previous->next = current->next;
            }
            delete current;
            nodeCounter--;
            return;
        }
        previous = current;
        current = current->next;
    }
}
