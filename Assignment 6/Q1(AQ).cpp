#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

void splitList(Node* tail, Node*& head1, Node*& head2) {
    if (!tail) return;

    Node* slow = tail->next;
    Node* fast = tail->next;

    while (fast->next != tail->next && fast->next->next != tail->next) {
        fast = fast->next->next;
        slow = slow->next;
    }

    head1 = tail->next;
    head2 = slow->next;

    slow->next = head1;

    Node* temp = head2;
    while (temp->next != tail->next)
        temp = temp->next;
    temp->next = head2;
}

void display(Node* head) {
    if (!head) return;
    Node* t = head;
    do {
        cout << t->data << " ";
        t = t->next;
    } while (t != head);
    cout << endl;
}

int main() {
    int arr[] = { 10, 4, 9, 7, 12 };
    Node* tail = NULL;

    for (int x : arr) {
        Node* n = new Node{ x, NULL };
        if (!tail) { tail = n; tail->next = tail; }
        else { n->next = tail->next; tail->next = n; tail = n; }
    }

    Node* head1 = NULL, * head2 = NULL;
    splitList(tail, head1, head2);

    cout << "First Half: ";
    display(head1);
    cout << "Second Half: ";
    display(head2);
}