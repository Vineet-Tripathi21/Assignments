#include <iostream>

using namespace std;


/*

5) Space required to store any two-dimensional array is 𝑛𝑢𝑚𝑏𝑒𝑟 𝑜ƒ 𝑟𝑜𝑤𝑠 × 𝑛𝑢𝑚𝑏𝑒𝑟 𝑜ƒ
𝑐𝑜𝑙𝑢𝑚𝑛𝑠. Assuming array is used to store elements of the following matrices,
implement an efficient way that reduces the space requirement.
(a) Diagonal Matrix.
(b) Tri-diagonal Matrix.
(c) Lower triangular Matrix.
(d) Upper triangular Matrix.
(e) Symmetric Matrix

*/


int main()
{
    // (a) Diagonal Matrix //

    const int n = 5; // 3 X 3 matrix

    int diag_arr[n];
    cout << "Please enter the diagonal values :";

    for (int i = 0; i < n; i++)
    {
        cout << "Please enter the " << i+ 1 <<  " diagonal value :";   
        cin >> diag_arr[i];
    }

    cout << "Displaying Diagonal Matrix" << endl;
    
    cout << "[";
    for (int i = 0; i < n; i++)
    {
        for (int j= 0; j < n; j++)
        {

            if ( i != j)
            {
                cout << 0 << " ";
            }
            else
            {
                cout << diag_arr[i] << " ";
            }
        }

        cout << endl;
        cout << " ";
    
    }
    cout << "]";


    
    // (b) Tri-gonal Matrix // 

    const int n = 5;
    const int size = 3*n - 2;  
    int tri[size];  

    for (int i = 0; i < n; i++) {
        tri[i] = 10 + i; 
    }

    for (int i = 0; i < n-1; i++) {
        tri[n + i] = 20 + i;

    for (int i = 1; i < n; i++) {
        tri[2*n - 1 + (i-1)] = 30 + i;
    }

    for (int i = 0; i < size; i++) {
        cout << tri[i] << " ";
    }
    cout << endl;


    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == j) cout << tri[i] << " ";                 
            else if (j == i+1) cout << tri[n + i] << " ";     
            else if (j == i-1) cout << tri[2*n - 1 + (i-1)] << " "; 
            else cout << "0 ";
        }
        cout << endl;
    }


    // (c)

        
    // int n = 4;
    // int size = n * (n + 1) / 2; 
    // int lower[size];      


    // int val = 1;
    // for (int i = 0; i < n; i++) {
    //     for (int j = 0; j <= i; j++) {
    //         int index = (i * (i + 1)) / 2 + j;
    //         lower[index] = val++;
    //     }
    // }


    // cout << "Stored Lower Triangular Array (1D): ";
    // for (int i = 0; i < size; i++) {
    //     cout << lower[i] << " ";
    // }
    // cout << endl;

    // cout << "Reconstructed Matrix:" << endl;
    // for (int i = 0; i < n; i++) {
    //     for (int j = 0; j < n; j++) {
    //         if (i >= j) {
    //             int index = (i * (i + 1)) / 2 + j;
    //             cout << lower[index] << " ";
    //         } else {
    //             cout << "0 ";
    //         }
    //     }
    //     cout << endl;
    // }



    // (d)

    // const int n = 4;
    // const int size = n * (n + 1) / 2;  
    // int upper[size];        


    // int val = 1;
    // for (int i = 0; i < n; i++) {
    //     for (int j = i; j < n; j++) {
    //         int index = (i * (2 * n - i + 1)) / 2 + (j - i);
    //         upper[index] = val++;
    //     }
    // }


    // for (int i = 0; i < size; i++) {
    //     cout << upper[i] << " ";
    // }
    // cout << endl;

    // for (int i = 0; i < n; i++) {
    //     for (int j = 0; j < n; j++) {
    //         if (i <= j) {
    //             int index = (i * (2 * n - i + 1)) / 2 + (j - i);
    //             cout << upper[index] << " ";
    //         } else {
    //             cout << "0 ";
    //         }
    //     }
    //     cout << endl;
    // }
    

    // return 0;
}
