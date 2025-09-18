#include <iostream>
#include <stack>
#include <string>
using namespace std;


int applyOp(int a, int b, char op) {
    switch (op) {
    case '+': return a + b;
    case '-': return a - b;
    case '*': return a * b;
    case '/': return a / b; 
    }
    return 0;
}


int evaluatePostfix(string postfix) {
    stack<int> st;

    for (char c : postfix) {
        if (isdigit(c)) {
            
            st.push(c - '0');
        }
        else {
            
            int val2 = st.top(); st.pop();
            int val1 = st.top(); st.pop();
            int result = applyOp(val1, val2, c);
            st.push(result);
        }
    }

    return st.top();
}

int main() {
    string postfix;
    cout << "Enter a postfix expression (single-digit operands): ";
    cin >> postfix;

    cout << "Evaluated result: " << evaluatePostfix(postfix) << endl;
    return 0;
}
