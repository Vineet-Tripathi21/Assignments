#include <iostream>
#include <stack>
#include <string>
using namespace std;

string reverseString(string s) {
    stack<char> st;

    // Push all characters onto the stack
    for (char c : s) {
        st.push(c);
    }

    // Pop characters to build reversed string
    string reversed = "";
    while (!st.empty()) {
        reversed += st.top();
        st.pop();
    }

    return reversed;
}

int main() {
    string str = "DataStructure";
    cout << "Original string: " << str << endl;
    cout << "Reversed string: " << reverseString(str) << endl;
    return 0;
}
