#include <iostream>

// FINDING SUM OF EVERY ROW AND COLUMN OF A 2D ARRAY MATRIX // 
using namespace std;

void displayMatrix();

int arr2d[100][100];
int row_count, column_count;

int main()
{
    cout << "Please enter the no. of rows : ";
    cin >> row_count;

    cout << "Please enter the no. of columns : ";
    cin >> column_count;


    for (int r = 0; r < row_count; r++)
    {
        for (int c = 0; c < column_count; c++)
        {
            int ele;
            cout << "Please enter row " << r + 1 << " column " << c + 1 << " element:";
            cin >> ele;
            arr2d[r][c] = ele;
        }
    }

    cout << "The matrix is :" << endl;
    displayMatrix();

    cout << endl;

    // ROW SUM
    for (int r = 0; r < row_count; r++)
    {
        int sum = 0;
        for (int c = 0; c < column_count; c++)
        {
            sum += arr2d[r][c];
        }

        cout << "The sum of Row " << r + 1 << " = " << sum << endl;
    }




    // COLUMN SUM
    for (int c = 0; c < column_count; c++)
    {
        int sum = 0;
        for (int r = 0; r < row_count; r++)
        {
            sum += arr2d[r][c];
        }

        cout << "The sum of Column " << c + 1 << " = " << sum << endl;
    }


    return 0;
}



void displayMatrix()
{
    for (int r = 0; r < row_count; r++)
    {
        for (int c = 0; c < column_count; c++)
        {
            cout << arr2d[r][c] << " ";
        }

        cout << endl;
    }
}