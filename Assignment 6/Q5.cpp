#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

bool isCircular(Node* head) {
    if (!head) return false;

    Node* slow = head;
    Node* fast = head;

    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast)
            return true;
    }
    return false;
}

int main() {

    Node* a = new Node{ 2, NULL };
    Node* b = new Node{ 4, NULL };
    Node* c = new Node{ 6, NULL };
    Node* d = new Node{ 8, NULL };
    a->next = b; b->next = c; c->next = d; d->next = a;

    cout << (isCircular(a) ? "True" : "False") << endl;

    Node* x = new Node{ 1, NULL };
    Node* y = new Node{ 2, NULL };
    Node* z = new Node{ 3, NULL };
    x->next = y; y->next = z; z->next = NULL;

    cout << (isCircular(x) ? "True" : "False") << endl;
}