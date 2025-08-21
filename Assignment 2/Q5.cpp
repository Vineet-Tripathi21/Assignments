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





    

    return 0;
}