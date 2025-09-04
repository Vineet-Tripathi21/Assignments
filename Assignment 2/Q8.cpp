#include <iostream>
using namespace std;


// 8) Write a program to count the total number of distinct elements in an array of length n // 

int arr[10] = { 1, 7, 2, 2, 3, 3, 4,  5, 5, 7};
int n = 10;

int main()
{

    int count = 0;

    for (int i = 0; i < n; i++)
    {
        bool dup_found = false;
        for (int j = i - 1; j > -1; j--)
        {
            if (arr[j] == arr[i])
            {
                dup_found = true;
                break;
            }
        }

        if (dup_found == false)
        {
            count++;
        }

    }

    cout << "There are "<< count << " unique elements in the array."<< endl;
    return 0;
}
