#include <iostream>
#include <queue>
#include <stack>
using namespace std;

bool checkSorted(queue<int>& q) {
    stack<int> st;
    int expected = 1;
    int n = q.size();

    while (!q.empty()) {
        int front = q.front();
        q.pop();

        // If the front element is the expected one
        if (front == expected) {
            expected++;
        }
        else {
            // If stack top matches expected, pop it
            while (!st.empty() && st.top() == expected) {
                st.pop();
                expected++;
            }

            // If stack has smaller element on top, sorting not possible
            if (!st.empty() && st.top() < front)
                return false;

            // Otherwise push this element to stack
            st.push(front);
        }
    }

    // Empty remaining stack elements
    while (!st.empty() && st.top() == expected) {
        st.pop();
        expected++;
    }

    // If all numbers from 1 to n were arranged correct
