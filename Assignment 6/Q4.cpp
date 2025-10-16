#include <iostream>
using namespace std;

struct Node { char ch; Node* prev; Node* next; };

bool isPalindrome(Node* head) {
    if (!head) return true;
    Node* end = head;
    while (end->next) end = end->next;
    while (head != end && end->next != head) {
        if (head->ch != end->ch) return false;
        head = head->next;
        end = end->prev;
    }
    return true;
}

int main() {
    string s; cout << "Enter string: "; cin >> s;
    Node* head = NULL; Node* last = NULL;
    for (char c : s) {
        Node* n = new Node{ c, NULL, NULL };
        if (!head) head = last = n;
        else { last->next = n; n->prev = last; last = n; }
    }
    cout << (isPalindrome(head) ? "True" : "False");
}