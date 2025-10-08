#include <iostream>
#include <queue>
using namespace std;

// Function to find index of minimum element within unsorted part of queue
int findMinIndex(queue<int>& q, int sortedTill) {
    int minIndex = -1;
    int minVal = INT_MAX;
    int size = q.size();

    for (int i = 0; i < size; i++) {
        int curr = q.front();
        q.pop();

        if (i <= sortedTill && curr < minVal) {
            minVal = curr;
            minIndex = i;
        }

        q.push(curr);
    }
    return minIndex;
}

// Function to move the minimum element found to the rear
void moveMinToRear(queue<int>& q, int minIndex) {
    int size = q.size();
    int minVal = 0;

    for (int i = 0; i < size; i++) {
        int curr = q.front();
        q.pop();

        if (i == minIndex)
            minVal = curr;
        else
            q.push(curr);
    }

    q.push(minVal);
}

// Function to sort the queue using only queue operations
void sortQueue(queue<int>& q) {
    for (int i = 1; i <= q.size(); i++) {
        int minIndex = findMinIndex(q, q.size() - i);
        moveMinToRear(q, minIndex);
    }
}

int main() {
    queue<int> q;
    int n, val;

    cout << "Enter number of elements: ";
    cin >> n;

    cout << "Enter elements:\n";
    for (int i = 0; i < n; i++) {
        cin >> val;
        q.push(val);
    }

    cout << "\nOriginal Queue: ";
    queue<int> temp = q;
    while (!temp.empty()) {
        cout << temp.front() << " ";
        temp.pop();
    }
    cout << endl;

    sortQueue(q);

    cout << "Sorted Queue: ";
    while (!q.empty()) {
        cout << q.front() << " ";
        q.pop();
    }
    cout << endl;

    return 0;
}
