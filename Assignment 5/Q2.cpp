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

    // Insert at end (for easy input)
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

    // Count and delete all occurrences of key
    int removeKey(int key) {
        int count = 0;

        // Handle leading nodes with key
        while (head != nullptr && head->data == key) {
            Node* toDelete = head;
            head = head->next;
            delete toDelete;
            count++;
        }

        // Delete remaining occurrences
        Node* temp = head;
        while (temp != nullptr && temp->next != nullptr) {
            if (temp->next->data == key) {
                Node* toDelete = temp->next;
                temp->next = temp->next->next;
                delete toDelete;
                count++;
            }
            else {
                temp = temp->next;
            }
        }

        return count;
    }

    void display() {
        if (head == nullptr) {
            cout << "List is empty.";
            return;
        }

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
    int n, val, key;

    cout << "Enter number of nodes: ";
    cin >> n;

    cout << "Enter elements:\n";
    for (int i = 0; i < n; i++) {
        cin >> val;
        list.insert(val);
    }

    cout << "Enter key to delete: ";
    cin >> key;

    cout << "\nOriginal List: ";
    list.display();

    int count = list.removeKey(key);

    cout << "Count of " << key << ": " << count << endl;
    cout << "Updated List: ";
    list.display();

    return 0;
}
