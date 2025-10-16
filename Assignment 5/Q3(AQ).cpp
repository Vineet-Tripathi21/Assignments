#include <iostream>
using namespace std;


class Node {
public:
    int data;
    Node* next;

    Node(int val) {
        data = val;
        next = NULL;
    }
};


void insertAtTail(Node*& head, int val) {
    Node* newNode = new Node(val);
    if (head == NULL) {
        head = newNode;
        return;
    }
    Node* temp = head;
    while (temp->next != NULL)
        temp = temp->next;
    temp->next = newNode;
}


void printList(Node* head) {
    Node* temp = head;
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}


void removeLoop(Node* head) {
    if (head == NULL || head->next == NULL)
        return;

    Node* slow = head;
    Node* fast = head;
    bool loopFound = false;

   
    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast) { 
            loopFound = true;
            break;
        }
    }

   
    if (loopFound) {
        slow = head;
        
        if (slow == fast) {
            while (fast->next != slow)
                fast = fast->next;
        }
        else {
            while (slow->next != fast->next) {
                slow = slow->next;
                fast = fast->next;
            }
        }
        fast->next = NULL;
    }
}


void createLoop(Node* head, int pos) {
    if (pos == 0) return;
    Node* temp = head;
    Node* loopNode = NULL;
    int count = 1;

    while (temp->next != NULL) {
        if (count == pos)
            loopNode = temp;
        temp = temp->next;
        count++;
    }
    if (loopNode)
        temp->next = lo
