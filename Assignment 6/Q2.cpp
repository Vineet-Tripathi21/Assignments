#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

void printCLL(Node* tail) {
    if (!tail) return;
    Node* head = tail->next;
    Node* t = head;
    do {
        cout << t->data << " ";
        t = t->next;
    } while (t != head);
    cout << head->data << endl;
}

int main() {
    int arr[] = { 20, 100, 40, 80, 60 };
    Node* tail = NULL;
    for (int x : arr) {
        Node* n = new Node{ x, NULL };
        if (!tail) { tail = n; tail->next = tail; }
        else { n->next = tail->next; tail->next = n; tail = n; }
    }
    printCLL(tail);
}