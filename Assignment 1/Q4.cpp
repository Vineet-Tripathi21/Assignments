#include <iostream>

using namespace std;

int arr[5] = { 1, 2 , 2, 7 ,8};
int arr_size = 5;
int main()
{
    // (a) REVERSING THE ELEMENTS OF AN ARRAY //

    for (int i=0; i < (arr_size - 1) / 2; i++)
    {
        if (i == arr_size - i - 1)
        {
            break;
        }

        int temp;
        temp = arr[i];

        arr[i] = arr[arr_size - i - 1];

        arr[arr_size - i - 1] = temp;
    }

    for (int i = 0; i < arr_size; i++)
    {
        cout << arr[i] << " ";
    }





    // (b) Find the matrix multiplication // 
    
    int r1, c1, r2, c2;

    cout << "Enter rows and columns of matrix 1: ";
    cin >> r1 >> c1;
    cout << "Enter rows and columns of matrix 2: ";
    cin >> r2 >> c2;

    if (c1 != r2) {
        cout << "Matrix multiplication not possible.." << endl;
        return 0;
    }

    int A[10][10], B[10][10], C[10][10] = {0};

    cout << "Enter elements of matrix 1:\n";
    for (int i = 0; i < r1; i++)
        for (int j = 0; j < c1; j++)
            cin >> A[i][j];

    cout << "Enter elements of matrix 2:\n";
    for (int i = 0; i < r2; i++)
        for (int j = 0; j < c2; j++)
            cin >> B[i][j];

    for (int i = 0; i < r1; i++) {
        for (int j = 0; j < c2; j++) {
            C[i][j] = 0;
            for (int k = 0; k < c1; k++) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }

    cout << "Resultant Matrix:\n";
    for (int i = 0; i < r1; i++) {
        for (int j = 0; j < c2; j++) {
            cout << C[i][j] << " ";
        }
        cout << endl;
    }


    // (c) Find the transpose of the matrix // 


    int A[3][3] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    int transpose[3][3];

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            transpose[j][i] = A[i][j];
        }
    }


    cout << "\nTranspose Matrix:\n";
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << transpose[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}

    return 0;
}
