#include <bits/stdc++.h>
using namespace std;

bool canBeSorted(vector<int>& A) {
    vector<int> B;
    stack<int> S;
    int i = 0, expected = 1, n = A.size();
    while (i < n || !S.empty()) {
        if (i < n && A[i] == expected) {
            B.push_back(A[i]); i++; expected++;
        }
        else if (!S.empty() && S.top() == expected) {
            B.push_back(S.top()); S.pop(); expected++;
        }
        else if (i < n) {
            S.push(A[i]); i++;
        }
        else return false;
    }
    return true;
}

int main() {
    vector<int> A1 = { 4,1,2,3 };
    vector<int> A2 = { 1,2,3,4 };
    cout << (canBeSorted(A1) ? "YES" : "NO") << endl;
    cout << (canBeSorted(A2) ? "YES" : "NO") << endl;
}