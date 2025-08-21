#include <iostream>
using namespace std;

void displayArray();

// BUBBLE SORT //


int arr[7] = { 64, 34, 25, 12, 22, 11, 90 };
int arr_size = 7;
int no_of_it = 0;

int main()
{
    for (int i = 0; i < arr_size; i++)
    {
        bool swapped = false;
        for (int j = 0; j < arr_size - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                swapped = true;
            }
        }

        if (swapped == false)
        {
            break;
        }

        no_of_it++;
    }

    displayArray();


}


void displayArray()
{
    cout << "The array elements are : [ ";
    for (int i = 0; i < arr_size; i++)
    {
        cout << arr[i] << " ";
    }


    cout << "]" << endl;

    cout << "No. of iterations : " << no_of_it << endl;
}