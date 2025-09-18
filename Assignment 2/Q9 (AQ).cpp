#include <iostream>
#include <vector>
#include <cmath>  // for abs()

using namespace std;

int countPairsWithDifference(const vector<int>& arr, int k) {
    int n = arr.size();
    int count = 0;

    // Check all pairs
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {  // ensure i < j
            if (abs(arr[i] - arr[j]) == k) {
                count++;
                cout << "Pair found: (" << arr[i] << ", " << arr[j] << ")\n";
            }
        }
    }

    return count;
}

int main() {
    vector<int> arr = { 1, 5, 3, 4, 2 };
    int k = 2;

    int result = countPairsWithDifference(arr, k);
    cout << "Total pairs: " << result << endl;

    return 0;
}
