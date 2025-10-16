#include <iostream>
using namespace std;


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


Node* reverseKGroup(Node* head, int k) {
    if (head == NULL || k == 1)
        return head;

    Node* curr = head;
    Node* prev = NULL;
    Node* next = NULL;
    int count = 0;

    
    Node* temp = head;
    for (int i = 0; i < k; i++) {
        if (temp == NULL)
            return head; 
        temp = temp->next;
    }

  
    while (curr != NULL && count < k) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
        count++;
    }

   
    if (next != NULL)
        head->next = reverseKGroup(next, k);

   
    return prev;
}


int main() {
    Node* head = NULL;

   
    for (int i = 1; i <= 10; i++)
        insertAtTail(head, i);

    cout << "Original List: ";
    printList(head);

    int k = 3;
    head = reverseKGroup(head, k);

    cout << "Reversed in groups of " << k << ": ";
    printList(head);

    return 0;
}
