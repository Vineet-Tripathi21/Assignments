#include <iostream>
using namespace std;

struct DNode { int data; DNode* next; DNode* prev; };
struct CNode { int data; CNode* next; };

int sizeDLL(DNode* head) {
    int c = 0;
    while (head) { c++; head = head->next; }
    return c;
}

int sizeCLL(CNode* tail) {
    if (!tail) return 0;
    int c = 0;
    CNode* t = tail->next;
    do { c++; t = t->next; } while (t != tail->next);
    return c;
}

int main() {

    DNode* a = new DNode{ 1,NULL,NULL };
    a->next = new DNode{ 2,a,NULL };
    a->next->next = new DNode{ 3,a->next,NULL };
    cout << "Size of DLL: " << sizeDLL(a) << endl;

    // CLL
    CNode* t = new CNode{ 10,NULL };
    CNode* b = new CNode{ 20,NULL };
    CNode* c = new CNode{ 30,NULL };
    t->next = b; b->next = c; c->next = t;
    cout << "Size of CLL: " << sizeCLL(c) << endl;
}