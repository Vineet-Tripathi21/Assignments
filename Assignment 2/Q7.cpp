#include <iostream>
using namespace std;

// 7) Let A[1 …. n] be an array of n real numbers. A pair (A[i], A[j ]) is said to be an
// inversion if these numbers are out of order, i.e., i < j but A[i]>A[j ]. Write a program to
// count the number of inversions in an array.


int arr[10] = { 4, 2, 1, 5, 6, 9, 7, 3, 8, 10};
int arr_size = 10;

int main()
{
    int no_of_pairs = 0;


    for (int i = 0; i < arr_size; i++)
    {

        for (int j = i - 1; j > -1; j--)
        {
            if (arr[j] > arr[i])
            {
                no_of_pairs++;
            }
        }

    }

    cout << "There are " << no_of_pairs << " inversion pairs in the array."<< endl;

    return 0;
}
