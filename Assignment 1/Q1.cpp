#include <iostream>
using namespace std;


// MENU DRIVEN PROGRAM

void createArray(int* arr, int size);
void displayArray();
void insertElement(int element, int idx);
int linearSearch(int ele);
void deleteElement(int element);

int running = 1;
int arr[100];
int arr_size = 0;


int main() {


    while (running)
    {
        cout << endl;
        cout << "Menu - Driven - Program\n";
        cout << "----------——MENU——---------" << endl;
        cout << "1.CREATE" << endl;
        cout << "2.DISPLAY" << endl;
        cout << "3.INSERT" << endl;
        cout << "4.DELETE" << endl;
        cout << "5.LINEAR SEARCH" << endl;
        cout << "6.EXIT" << endl;

        int opt = 0;
        cout << "Enter your choice:";
        cin >> opt;

        switch (opt)
        {
        case 1:
            int size;
            cout << "Please enter size of array" << endl;
            cin >> size;
            createArray(arr, size);
            break;
        case 2:
            displayArray();
            break;
        case 3:
            int ele;
            int pos;
            int idx; // As position and idx are not the same, idx = pos - 1
            cout << "Please enter element to insert" << endl;
            cin >> ele;
            cout << "Please enter position to enter element" << endl;
            cin >> pos;

            idx = pos - 1;

            insertElement(ele, idx);
            break;
        case 4:
            int e;
            cout << "Please enter element to delete :" << endl;
            cin >> e;
            deleteElement(e);

            break;
        case 5:
            int elem;
            cout << "Enter element to search :";
            cin >> elem;

            cout << endl;
            int r;
            r = linearSearch(elem);

            if (r == -1)
            {
                cout << "Element not found in array" << endl;
            }
            else
            {
                cout << "Elemen FOUND at index " << r << endl;
            }

            break;
        case 6:
            cout << "Exiting program......" << endl;
            running = 0;
            break;
        default:
            cout << "This is not a valid option, please try again.";
        }


    }

    return 0;
}


void createArray(int arr[], int size)
{
    arr_size = size;

    for (int i = 0; i < size; i++)
    {
        int element;
        cout << "Enter no. " << (i + 1) << "element" << endl;
        cin >> element;

        arr[i] = element;
    }

    cout << "Array has been created successfully !" << endl;
    cout << endl;
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

    cout << " ARRAY SIZE = " << arr_size << endl;
}

void insertElement(int element, int idx)
{
    for (int i = arr_size - 1; i <= idx; i--)
    {
        arr[i + 1] = arr[i];

    }

    arr[idx] = element;
    arr_size++;
    displayArray();
}

void deleteElement(int element)
{
    int idx;
    idx = linearSearch(element);
    if (idx == -1)
    {
        cout << "Element does not exist in array";
        return;
    }

    for (int i = idx + 1; i < arr_size; i++)
    {
        arr[i - 1] = arr[i];
    }
    // Acc to this logic, the last element will be a copy of the second last, but we will reduce the array size so the last element does not show
    arr_size--;

    displayArray();


}

int linearSearch(int ele)
{
    for (int i = 0; i < arr_size; i++)
    {
        if (arr[i] == ele)
        {
            return i;

        }


    }

    return -1;
}