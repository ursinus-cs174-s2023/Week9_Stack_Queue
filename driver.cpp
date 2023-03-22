#include <iostream>
#include "linkedlist.h"

using namespace std;

int main() {
    Queue queue;
    queue.enqueue(new PrintableInt(4));
    queue.enqueue(new PrintableInt(7));
    queue.enqueue(new PrintableInt(1));
    
    while (queue.size() > 0) {
        Printable* obj = queue.dequeue();
        obj->print();
        delete obj;
    }
    cout << "\n";

    return 0;
}