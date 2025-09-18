#include <iostream>
#include <string>
using namespace std;

int main() {
    string s;
    cout << "Enter string: ";
    cin >> s;

    int n = s.size();
    bool found = false;

    // Try all ways to split into A, B, C
    for (int i = 1; i < n && !found; i++) {        // end of A
        for (int j = i + 1; j < n && !found; j++) { // end of B
            string A = s.substr(0, i);
            string B = s.substr(i, j - i);
            string C = s.substr(j);

            // Check if one part is in both others
            if ((B.find(A) != string::npos && C.find(A) != string::npos) ||
                (A.find(B) != string::npos && C.find(B) != string::npos) ||
                (A.find(C) != string::npos && B.find(C) != string::npos)) {
                cout << "YES\n";
                cout << "Split: " << A << " | " << B << " | " << C << endl;
                found = true;
            }
        }
    }

    if (!found) cout << "NO\n";

    return 0;
}
