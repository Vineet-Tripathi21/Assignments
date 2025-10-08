#include <iostream>
#include <queue>
#include <stack>
using namespace std;

int countStudentsUnableToEat(queue<int>& students, stack<int>& sandwiches) {
    int attempts = 0;  // To track consecutive unsuccessful tries

    while (!students.empty() && attempts < students.size()) {
        if (students.front() == sandwiches.top()) {
            // Student takes sandwich and leaves
            students.pop();
            sandwiches.pop();
            attempts = 0; // reset since successful match
        }
        else {
            // Student goes to the end of the queue
            int front = students.front();
            students.pop();
            students.push(front);
            attempts++;  // one unsuccessful rotation
        }
    }

    return students.size();  // stu
