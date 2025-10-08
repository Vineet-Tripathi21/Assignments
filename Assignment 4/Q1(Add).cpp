#include <iostream>
#include <queue>
using namespace std;

// Function to generate and print binary numbers from 1 to n
void generateBinary(int n) {
    if (n <= 0) {
        cout << "Please enter a positive number.\n";
        return;
    }

    queue<string> q;
    q.push("1");

    cout << "Binary numbers from 1 to " << n << ":\n";

    for (int i = 1; i <= n; i++) {
        string current = q.front();
        q.pop();

        cout << current << endl;

        // Enqueue next two binaries
        q.push(current + "0");
        q.push(current + "1");
    }
}

int main() {
    int n;
    cout << "Enter value of n: ";
    cin >> n;

    generateBinary(n);

    return 0;
}
