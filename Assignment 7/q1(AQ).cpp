#include <iostream>
#include <vector>
using namespace std;

void countingSort(int arr[], int n) {
    // Step 1: Find the maximum element
    int maxVal = arr[0];
    for (int i = 1; i < n; i++)
        if (arr[i] > maxVal)
            maxVal = arr[i];

    // Step 2: Create count array
    vector<int> count(maxVal + 1, 0);

    // Step 3: Store frequency of each element
    for (int i = 0; i < n; i++)
        count[arr[i]]++;

    // Step 4: Modify count array to store positions
    for (int i = 1; i <= maxVal; i++)
        count[i] += count[i - 1];

    // Step 5: Build output array (to maintain stability)
    vector<int> output(n);
    for (int i = n - 1; i >= 0; i--) {
        output[count[arr[i]] - 1] = arr[i];
        count[arr[i]]--;
    }

    // Step 6: Copy sorted elements back to original array
    for (int i = 0; i < n; i++)
        arr[i] = output[i];
}

void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}

int main() {
    int arr[] = { 4, 2, 2, 8, 3, 3, 1 };
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Original array: ";
    printArray(arr, n);

    countingSort(arr, n);

    cout << "Sorted array: ";
    printArray(arr, n);

    return 0;
}
