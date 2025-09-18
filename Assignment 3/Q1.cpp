#include <iostream>
using namespace std;

#define MAX 5   // maximum size of stack

class Stack {
    int arr[MAX];
    int top;

public:
    Stack() { top = -1; }

    // Push operation
    void push(int x) {
        if (isFull()) {
            cout << "Stack Overflow! Cannot push " << x << endl;
        }
        else {
            arr[++top] = x;
            cout << x << " pushed into stack.\n";
        }
    }

    // Pop operation
    void pop() {
        if (isEmpty()) {
            cout << "Stack Underflow! Nothing to pop.\n";
        }
        else {
            cout << arr[top--] << " popped from stack.\n";
        }
    }

    // Peek operation
    void peek() {
        if (isEmpty()) {
            cout << "Stack is empty!\n";
        }
        else {
            cout << "Top element is: " << arr[top] << endl;
        }
    }

    // Check if empty
    bool isEmpty() {
        return (top == -1);
    }

    // Check if full
    bool isFull() {
        return (top == MAX - 1);
    }

    // Display all elements
    void display() {
        if (isEmpty()) {
            cout << "Stack is empty!\n";
        }
        else {
            cout << "Stack elements (top to bottom): ";
            for (int i = top; i >= 0; i--) {
                cout << arr[i] << " ";
            }
            cout << endl;
        }
    }
};

int main() {
    Stack st;
    int choice, value;

    do {
        cout << "\n--- Stack Menu ---\n";
        cout << "1. Push\n";
        cout << "2. Pop\n";
        cout << "3. Peek\n";
        cout << "4. isEmpty\n";
        cout << "5. isFull\n";
        cout << "6. Display\n";
        cout << "0. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter value to push: ";
            cin >> value;
            st.push(value);
            break;

        case 2:
            st.pop();
            break;

        case 3:
            st.peek();
            break;

        case 4:
            cout << (st.isEmpty() ? "Stack is empty.\n" : "Stack is NOT empty.\n");
            break;

        case 5:
            cout << (st.isFull() ? "Stack is full.\n" : "Stack is NOT full.\n");
            break;

        case 6:
            st.display();
            break;

        case 0:
            cout << "Exiting program...\n";
            break;

        default:
            cout << "Invalid choice! Try again.\n";
        }

    } while (choice != 0);

    return 0;
}
