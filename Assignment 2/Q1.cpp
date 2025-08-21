#include <iostream>
using namespace std;

// BINARY SEARCH ALGORITHM //

int arr[4] = { 1, 2, 3, 4 }; // sorted array
int arr_size = 4;

int main() {

    int target;
    cout << "Enter the number you want to search :";
    cin >> target;
    cout << endl;

    int a = 0;
    int b = arr_size - 1;

    int m = (a + b) / 2;


    while (a <= b)
    {

        if (target > arr[arr_size - 1] || target < arr[0])
        {
            cout << "Target not present in array" << endl;
            break;
        }


        if (target > arr[m])
        {
            a = m + 1;
        }
        else if (target < arr[m])
        {
            b = m - 1;
        }
        else if (target == arr[m])
        {
            cout << "Target found at index: " << m << endl;
            break;
        }

        m = (a + b) / 2;
    }



    return 0;
}