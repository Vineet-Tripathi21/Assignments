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

    // (a) Insertion at beginning
    void insertAtStart(int val) {
        Node* newNode = new Node(val);
        newNode->next = head;
        head = newNode;
        cout << "Inserted " << val << " at beginning.\n";
    }

    // (b) Insertion at end
    void insertAtEnd(int val) {
        Node* newNode = new Node(val);
        if (head == nullptr) {
            head = newNode;
        }
        else {
            Node* temp = head;
            while (temp->next != nullptr)
                temp = temp->next;
            temp->next = newNode;
        }
        cout << "Inserted " << val << " at end.\n";
    }

    // (c) Insertion before or after a given value
    void insertRelative(int target, int val, bool insertAfter) {
        if (head == nullptr) {
            cout << "List is empty.\n";
            return;
        }

        Node* temp = head;
        Node* prev = nullptr;

        while (temp != nullptr && temp->data != target) {
            prev = temp;
            temp = temp->next;
        }

        if (temp == nullptr) {
            cout << "Node with value " << target << " not found.\n";
            return;
        }

        Node* newNode = new Node(val);

        if (insertAfter) {
            newNode->next = temp->next;
            temp->next = newNode;
            cout << "Inserted " << val << " after " << target << ".\n";
        }
        else {
            if (temp == head) {
                newNode->next = head;
                head = newNode;
            }
            else {
                prev->next = newNode;
                newNode->next = temp;
            }
            cout << "Inserted " << val << " before " << target << ".\n";
        }
    }

    // (d) Delete from beginning
    void deleteStart() {
        if (head == nullptr) {
            cout << "List is empty.\n";
            return;
        }
        Node* temp = head;
        head = head->next;
        cout << "Deleted node " << temp->data << " from beginning.\n";
        delete temp;
    }

    // (e) Delete from end
    void deleteEnd() {
        if (head == nullptr) {
            cout << "List is empty.\n";
            return;
        }

        if (head->next == nullptr) {
            cout << "Deleted node " << head->data << " from end.\n";
            delete head;
            head = nullptr;
            return;
        }

        Node* temp = head;
        while (temp->next->next != nullptr)
            temp = temp->next;

        cout << "Deleted node " << temp->next->data << " from end.\n";
        delete temp->next;
        temp->next = nullptr;
    }

    // (f) Delete a specific node
    void deleteValue(int val) {
        if (head == nullptr) {
            cout << "List is empty.\n";
            return;
        }

        if (head->data == val) {
            Node* temp = head;
            head = head->next;
            delete temp;
            cout << "Deleted node " << val << ".\n";
            return;
        }

        Node* temp = head;
        while (temp->next != nullptr && temp->next->data != val)
            temp = temp->next;

        if (temp->next == nullptr) {
            cout << "Node " << val << " not found.\n";
            return;
        }

        Node* delNode = temp->next;
        temp->next = temp->next->next;
        delete delNode;
        cout << "Deleted node " << val << ".\n";
    }

    // (g) Search for a node
    void searchNode(int val) {
        Node* temp = head;
        int pos = 1;
        while (temp != nullptr) {
            if (temp->data == val) {
                cout << "Node " << val << " found at position " << pos << ".\n";
                return;
            }
            temp = temp->next;
            pos++;
        }
        cout << "Node " << val << " not found.\n";
    }

    // (h) Display all nodes
    void display() {
        if (head == nullptr) {
            cout << "List is empty.\n";
            return;
        }

        Node* temp = head;
        cout << "Linked List: ";
        while (temp != nullptr) {
            cout << temp->data;
            if (temp->next != nullptr) cout << " -> ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main() {
    LinkedList list;
    int choice, val, target;
    bool after;

    do {
        cout << "\n--- Singly Linked List Menu ---\n";
        cout << "1. Insert at Beginning\n";
        cout << "2. Insert at End\n";
        cout << "3. Insert Before/After a Node\n";
        cout << "4. Delete from Beginning\n";
        cout << "5. Delete from End\n";
        cout << "6. Delete Specific Node\n";
        cout << "7. Search for a Node\n";
        cout << "8. Display List\n";
        cout << "9. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter value: ";
            cin >> val;
            list.insertAtStart(val);
            break;

        case 2:
            cout << "Enter value: ";
            cin >> val;
            list.insertAtEnd(val);
            break;

        case 3:
            cout << "Enter target node value: ";
            cin >> target;
            cout << "Enter new node value: ";
            cin >> val;
            cout << "Insert (1) After or (0) Before target? ";
            cin >> after;
            list.insertRelative(target, val, after);
            break;

        case 4:
            list.deleteStart();
            break;

        case 5:
            list.deleteEnd();
            break;

        case 6:
            cout << "Enter value to delete: ";
            cin >> val;
            list.deleteValue(val);
            break;

        case 7:
            cout << "Enter value to search: ";
            cin >> val;
            list.searchNode(val);
            break;

        case 8:
            list.display();
            break;

        case 9:
            cout << "Exiting...\n";
            break;

        default:
            cout << "Invalid choice. Try again.\n";
        }
    } while (choice != 9);

    return 0;
}
