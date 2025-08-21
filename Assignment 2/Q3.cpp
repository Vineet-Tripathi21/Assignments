#include <iostream>

// Given an array of n-1 distinct integers in the range of 1 to n, find the missing number
// in it in a Sorted Array
// (a) Linear time
// (b) Using binary search

using namespace std;


int arr[5] = { 1, 2, 4, 5, 6 };
int n = 6;

int main()
{

    // (a) Linear Time

    for (int i = 0; i < n - 1; i++)
    {
        if (arr[i] != i + 1)
        {
            // Missing no. found
            cout << (i + 1) << " is the missing number" << endl;
            break;
        }
    }

    // (b) Using binary search

    int a = 0;
    int b = n - 1;
    int i = 0;

    int m = (a + b) / 2;

    while (a <= b)
    {

        if (arr[i] == (i + 1))
        {
            a = m + 1;
        }
        else
        {
            b = m - 1;

        }

        m = (a + b) / 2;
        i++;
    }

    return 0;
}