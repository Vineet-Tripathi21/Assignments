#include <iostream>
using namespace std;

struct DNode {
    int data;
    DNode* prev, * next;
};

void insertEnd(DNode*& head, int x) {
    DNode* n = new DNode{ x, NULL, NULL };
    if (!head) { head = n; return; }
    DNode* t = head;
    while (t->next) t = t->next;
    t->next = n;
    n->prev = t;
}

void deleteNode(DNode*& head, int x) {
    DNode* t = head;
    while (t && t->data != x) t = t->next;
    if (!t) return;
    if (t->prev) t->prev->next = t->next;
    else head = t->next;
    if (t->next) t->next->prev = t->prev;
    delete t;
}

bool search(DNode* head, int x) {
    while (head) {
        if (head->data == x) return true;
        head = head->next;
    }
    return false;
}

void display(DNode* head) {
    while (head) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    DNode* head = NULL;
    insertEnd(head, 10);
    insertEnd(head, 20);
    insertEnd(head, 30);
    cout << "DLL: "; display(head);
    cout << "Search 20 -> " << (search(head, 20) ? "Found" : "Not Found") << endl;
    deleteNode(head, 10);
    cout << "After deleting 10: "; display(head);
}