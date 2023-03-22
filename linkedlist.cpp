#include "linkedlist.h"
#include <stdio.h>

LinkedList::LinkedList() {
    head = NULL;
    N = 0;
}

LinkedList::~LinkedList() {
    LinkedNode* node = head;
    while (node != NULL) {
        LinkedNode* next = node->next;
        delete node;
        node = next;
    }
}

/**
 * @brief Add an object reference to the beginning of the 
 * linked list
 * 
 * @param obj Object reference to add
 */
void LinkedList::addFirst(Printable* obj) {
    // Make a new container
    LinkedNode* node = new LinkedNode(obj);
    node->next = head;
    this->head = node;
    N++;
}

void LinkedList::addLast(Printable* obj) {
    if (head == NULL) {
        // If list is empty, adding last is the same thing as adding first
        addFirst(obj);
    }
    else {
        // At least one element in the list
        LinkedNode* cursor = head;
        while (cursor->next != NULL) {
            cursor = cursor->next;
        }
        cursor->next = new LinkedNode(obj);
        N++;
    }
}

/**
 * @brief Remove the first occurrence of an object from 
 * the list
 * 
 * @param obj Object reference to remove
 */
void LinkedList::remove(Printable* obj) {
    if (head != NULL) {
        if (head->obj == obj) {
            removeFirst();
        }
        else {
            LinkedNode* cursor = head;
            while (cursor->next != NULL && cursor->next->obj != obj) {
                cursor = cursor->next;
            }
            if (cursor->next->obj == obj) {
                LinkedNode* toDelete = cursor->next;
                cursor->next = cursor->next->next; // Jump over this object
                delete toDelete;
                N--;
            }
        }
    }
}

/**
 * @brief Remove the first object from the list and return
 * what it was
 * 
 * @return Printable* 
 */
Printable* LinkedList::removeFirst() {
    Printable* ret;
    if (N > 0) {
        LinkedNode* oldHead = head;
        ret = head->obj;
        head = head->next;
        N--;
        delete oldHead;
    }
    return ret;
}

/**
 * @brief Loop through the linked list and return
 * the elements in an array
 * 
 * @param N Pointer to size of array
 * @return Printable** 
 */
Printable** LinkedList::toArray(int* NOut) {
    *NOut = N;
    Printable** arr = new Printable*[N];
    // Cursor points to a LinkedNode that we're
    // at as we loop through
    LinkedNode* cursor = this->head;
    for (int i = 0; i < N; i++) {
        // Take out the data and copy it into
        // arr
        arr[i] = cursor->obj;
        cursor = cursor->next;
    }
    return arr;
}


void Stack::push(Printable* obj) {
    list.addFirst(obj);
}

Printable* Stack::pop() {
    return list.removeFirst();
}

int Stack::size() {
    return list.size();
}

/** Adding something at the end of the line*/
void Queue::enqueue(Printable* obj) {
    list.addLast(obj);
}

/** Remove from front of line */
Printable* Queue::dequeue() {
    return list.removeFirst();
}

int Queue::size() {
    return list.size();
}