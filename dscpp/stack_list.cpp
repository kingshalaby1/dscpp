//
//  stack_list.cpp
//  dscpp
//
//  Created by ahmed shalaby on 7/5/20.
//  Copyright © 2020 ahmed shalaby. All rights reserved.
//
#include <iostream>
#include "stack_list.hpp"


using namespace std;

// A stack node
struct node {
    int data;
    node* next;
};

// Initialize a global pointer for head
node* head;

// This function adds a node at the begin of the stack
void push_list(int new_data) {
    // allocate new node and put it's data
    node* new_node = new node();
    new_node->data = new_data;
    // check if the stack is empty
    if (head == NULL) {
        head = new_node;
    }
    // otherwise insert the new node in the begin of the stack
    else {
        // set next of the new node to be the head
        new_node->next = head;
        // set the new node as a head
        head = new_node;
    }
}

// This function deletes the first node in the stack
void pop_list() {
    // check if the stack is empty
    if (head == NULL)
        return;
    // get the node which it will be deleted
    node* temp_node = head;
    // check if the stack has only one node
    if (head->next == NULL) {
        // delete the temp node
        delete(temp_node);
        head = NULL;
    }
    // otherwise the stack has nodes more than one
    else {
        // shift the head to be the next node
        head = head->next;
        // delete the temp node
        delete(temp_node);
    }
}

// This function returns the value of the first node in the stack
int top_list() {
    // check if the stack is empty
    // to return the biggest integer value as an invalid value
    if (head == NULL)
        return INT_MAX;
    // otherwise return the real value
    else
        return head->data;
}

int test_stack_list() {

    // Functionality Testing
    
    cout << "Stack top: " << top_list() << '\n';
    cout << "----------------------------------------------------\n";

    /* Expected Output:
    Stack top: 2147483647
    ----------------------------------------------------
    */

    push_list(10);
    cout << "Stack top: " << top_list() << '\n';
    cout << "----------------------------------------------------\n";

    /* Expected Output:
    Stack top: 10
    ----------------------------------------------------
    */

    push_list(20);
    cout << "Stack top: " << top_list() << '\n';
    cout << "----------------------------------------------------\n";

    /* Expected Output:
    Stack top: 20
    ----------------------------------------------------
    */

    push_list(30);
    cout << "Stack top: " << top_list() << '\n';
    cout << "----------------------------------------------------\n";

    /* Expected Output:
    Stack top: 30
    ----------------------------------------------------
    */

    push_list(40);
    cout << "Stack top: " << top_list() << '\n';
    cout << "----------------------------------------------------\n";

    /* Expected Output:
    Stack top: 40
    ----------------------------------------------------
    */

    push_list(50);
    cout << "Stack top: " << top_list() << '\n';
    cout << "----------------------------------------------------\n";

    /* Expected Output:
    Stack top: 50
    ----------------------------------------------------
    */

    while (head != NULL) {
        cout << "Stack top: " << top_list() << '\n';
        pop_list();
        cout << "Stack top has been deleted\n";
        cout << "----------------------------------------------------\n";
    }
    cout << "Stack is empty now\n";

    /* Expected Output:
    Stack top: 50
    Stack top has been deleted
    ----------------------------------------------------
    Stack top: 40
    Stack top has been deleted
    ----------------------------------------------------
    Stack top: 30
    Stack top has been deleted
    ----------------------------------------------------
    Stack top: 20
    Stack top has been deleted
    ----------------------------------------------------
    Stack top: 10
    Stack top has been deleted
    ----------------------------------------------------
    Stack is empty now
    */
    
    return 0;

}

