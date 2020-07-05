//
//  queue_linked.cpp
//  dscpp
//
//  Created by ahmed shalaby on 7/5/20.
//  Copyright © 2020 ahmed shalaby. All rights reserved.
//

#include <iostream>
#include "queue_linked.hpp"

using namespace std;

// A queue node
struct node {
    int data;
    node* prev;
    node* next;
};

// Initialize a global pointers for queue_head and queue_tail
node* queue_head;
node* queue_tail;

// This function adds a node at the end of the queue
void enqueue(int new_data) {
    // allocate new node and put it's data
    node* new_node = new node();
    new_node->data = new_data;
    // check if the queue is empty
    if (queue_head == NULL) {
        queue_head = new_node;
        queue_tail = new_node;
    }
    // otherwise reach the end of the queue
    else {
        // set the next of the last node to be the new node and vice versa
        queue_tail->next = new_node;
        new_node->prev = queue_tail;
        // set the new node as a queue_tail
        queue_tail = new_node;
    }
}

// This function deletes the first node in the queue
void dequeue() {
    // check if the queue is empty
    if (queue_head == NULL)
        return;
    // get the node which it will be deleted
    node* temp_node = queue_head;
    // check if the queue has only one node
    if (queue_head == queue_tail) {
        // delete the temp node
        delete(temp_node);
        queue_head = NULL;
        queue_tail = NULL;
    }
    // otherwise the queue has nodes more than one
    else {
        // shift the queue_queue_head to be the next node
        queue_head = queue_head->next;
        queue_head->prev = NULL;
        // delete the temp node
        delete(temp_node);
    }
}

// This function returns the value of the first node in the queue
int front() {
    // check if the queue is empty
    // to return the biggest integer value as an invalid value
    if (queue_head == NULL)
        return INT_MAX;
    // otherwise return the real value
    else
        return queue_head->data;
}

// This function returns the value of the last node in the queue
int back() {
    // check if the queue is empty
    // to return the biggest integer value as an invalid value
    if (queue_tail == NULL)
        return INT_MAX;
    // otherwise return the real value
    else
        return queue_tail->data;
}

int test_queue_linked() {

    // Functionality Testing

    cout << "Queue front: " << front() << " and Queue back: " << back() << '\n';
    cout << "----------------------------------------------------\n";

    /* Expected Output:
    Queue front: 2147483647 and Queue back: 2147483647
    ----------------------------------------------------
    */

    enqueue(10);
    cout << "Queue front: " << front() << " and Queue back: " << back() << '\n';
    cout << "----------------------------------------------------\n";

    /* Expected Output:
    Queue front: 10 and Queue back: 10
    ----------------------------------------------------
    */

    enqueue(20);
    cout << "Queue front: " << front() << " and Queue back: " << back() << '\n';
    cout << "----------------------------------------------------\n";

    /* Expected Output:
    Queue front: 10 and Queue back: 20
    ----------------------------------------------------
    */

    enqueue(30);
    cout << "Queue front: " << front() << " and Queue back: " << back() << '\n';
    cout << "----------------------------------------------------\n";

    /* Expected Output:
    Queue front: 10 and Queue back: 30
    ----------------------------------------------------
    */

    enqueue(40);
    cout << "Queue front: " << front() << " and Queue back: " << back() << '\n';
    cout << "----------------------------------------------------\n";

    /* Expected Output:
    Queue front: 10 and Queue back: 40
    ----------------------------------------------------
    */

    enqueue(50);
    cout << "Queue front: " << front() << " and Queue back: " << back() << '\n';
    cout << "----------------------------------------------------\n";

    /* Expected Output:
    Queue front: 10 and Queue back: 50
    ----------------------------------------------------
    */

    while (queue_head != NULL) {
        cout << "Queue front: " << front() << " and Queue back: " << back() << '\n';
        dequeue();
        cout << "queue front has been deleted\n";
        cout << "----------------------------------------------------\n";
    }
    cout << "Queue is empty now\n";

    /* Expected Output:
    Queue front: 10 and Queue back: 50
    queue front has been deleted
    ----------------------------------------------------
    Queue front: 20 and Queue back: 50
    queue front has been deleted
    ----------------------------------------------------
    Queue front: 30 and Queue back: 50
    queue front has been deleted
    ----------------------------------------------------
    Queue front: 40 and Queue back: 50
    queue front has been deleted
    ----------------------------------------------------
    Queue front: 50 and Queue back: 50
    queue front has been deleted
    ----------------------------------------------------
    Queue is empty now
    */

    cout << "Queue front: " << front() << " and Queue back: " << back() << '\n';
    cout << "----------------------------------------------------\n";

    /* Expected Output:
    Queue front: 2147483647 and Queue back: 2147483647
    ----------------------------------------------------
    */

    enqueue(10);
    cout << "Queue front: " << front() << " and Queue back: " << back() << '\n';
    cout << "----------------------------------------------------\n";

    /* Expected Output:
    Queue front: 10 and Queue back: 10
    ----------------------------------------------------
    */

    enqueue(20);
    cout << "Queue front: " << front() << " and Queue back: " << back() << '\n';
    cout << "----------------------------------------------------\n";

    /* Expected Output:
    Queue front: 10 and Queue back: 20
    ----------------------------------------------------
    */

    enqueue(30);
    cout << "Queue front: " << front() << " and Queue back: " << back() << '\n';
    cout << "----------------------------------------------------\n";

    /* Expected Output:
    Queue front: 10 and Queue back: 30
    ----------------------------------------------------
    */

    while (queue_head != NULL) {
        cout << "Queue front: " << front() << " and Queue back: " << back() << '\n';
        dequeue();
        cout << "queue front has been deleted\n";
        cout << "----------------------------------------------------\n";
    }
    cout << "Queue is empty now\n";

    /* Expected Output:
    Queue front: 10 and Queue back: 30
    queue front has been deleted
    ----------------------------------------------------
    Queue front: 20 and Queue back: 30
    queue front has been deleted
    ----------------------------------------------------
    Queue front: 30 and Queue back: 30
    queue front has been deleted
    ----------------------------------------------------
    Queue is empty now
    */
    return 0;

}
