#include <bits/stdc++.h>
using namespace std;

class MinStack {
    stack<long long> st;
    long long mn;
public:
    void push(int x) {
        if (st.empty()) {
            st.push(x);
            mn = x;
        }
        else if (x >= mn) {
            st.push(x);
        }
        else {
            st.push(2LL * x - mn);
            mn = x;
        }
    }
    void pop() {
        if (st.empty()) return;
        long long t = st.top(); st.pop();
        if (t < mn) mn = 2 * mn - t;
    }
    int top() {
        long long t = st.top();
        if (t < mn) return mn;
        return t;
    }
    int getMin() {
        return mn;
    }
};

int main() {
    MinStack s;
    s.push(3); s.push(5); cout << s.getMin() << endl;
    s.push(2); s.push(1); cout << s.getMin() << endl;
    s.pop(); cout << s.getMin() << endl;
}