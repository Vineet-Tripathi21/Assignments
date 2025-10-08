#include <iostream>
using namespace std;

#define SIZE 256   // ASCII characters

class Queue {
private:
    char arr[SIZE];
    int front, rear;

public:
    Queue() {
        front = -1;
        rear = -1;
    }

    bool isEmpty() {
        return (front == -1);
    }

    void enqueue(char c) {
        if (rear == SIZE - 1) return;  // overflow protection
        if (front == -1) front = 0;
        arr[++rear] = c;
    }

    void dequeue() {
        if (isEmpty()) return;
        if (front == rear) {
            front = rear = -1;
        }
        else {
            front++;
        }
    }

    char getFront() {
        if (!isEmpty()) return arr[front];
        return '\0';
    }
};

// Function to find first non-repeating characters
void firstNonRepeating(string str) {
    int freq[SIZE] = { 0 };   // frequency table
    Queue q;

    for (char c : str) {
        if (c == ' ') continue; // ignore spaces

        freq[(int)c]++;
        q.enqueue(c);

        // Remove all repeating chars from queue front
        while (!q.isEmpty() && freq[(int)q.getFront()] > 1) {
            q.dequeue();
        }

        if (q.isEmpty())
            cout << -1 << " ";
        else
            cout << q.getFront() << " ";
    }
    cout << endl;
}

int main() {
    string input;
    cout << "Enter string: ";
    cin >> input;

    cout << "Output: ";
    firstNonRepeating(input);

    return 0;
}