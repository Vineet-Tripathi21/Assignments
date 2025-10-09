#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int val) {
        data = val;
        next = nullptr;
    }
};

class LinkedList {
private:
    Node* head;

public:
    LinkedList() {
        head = nullptr;
    }

    // Insert node at end
    void insert(int val) {
        Node* newNode = new Node(val);
        if (head == nullptr) {
            head = newNode;
            return;
        }
        Node* temp = head;
        while (temp->next != nullptr)
            temp = temp->next;
        temp->next = newNode;
    }

    // Find and print the middle node
    void findMiddle() {
        if (head == nullptr) {
            cout << "List is empty.\n";
            return;
        }

        Node* slow = head;
        Node* fast = head;

        // Move fast by 2 and slow by 1
        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
        }

        cout << "Middle element: " << slow->data << endl;
    }

    void display() {
        Node* temp = head;
        while (temp != nullptr) {
            cout << temp->data;
            if (temp->next != nullptr)
                cout << " -> ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main() {
    LinkedList list;
    int n, val;

    cout << "Enter number of nodes: ";
    cin >> n;

    cout << "Enter elements:\n";
    for (int i = 0; i < n; i++) {
        cin >> val;
        list.insert(val);
    }

    cout << "\nLinked List: ";
    list.display();

    list.findMiddle();

    return 0;
}
