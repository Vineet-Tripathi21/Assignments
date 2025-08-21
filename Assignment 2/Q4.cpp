#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

// (a) Write a program to concatenate one string to another string.
// (b) Write a program to reverse a string.
// (c) Write a program to delete all the vowels from the string.
// (d) Write a program to sort the strings in alphabetical order.
// (e) Write a program to convert a character from uppercase to lowercase.

string s1 = "Hello";
string s2 = "World";

int main()
{
    // (a) 
    string con_cat = s1 + s2;
    cout << "Concatenated string : " << con_cat << endl;
    //(b)

    string rev = "";
    for (int i = 0; i < s1.length(); i++)
    {
        rev += s1[s1.length() - 1 - i];
    }

    cout << "Reversed String : " << rev << endl;

    //(c)

    string non_vowel = "";
    for (char c : s1)
    {
        if (!(c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' || c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U'))
        {
            non_vowel += c;
        }
    }

    cout << "String without vowels :" << non_vowel << endl;

    // (d)


    string alpha_order = s1;

    // Firstly we change everything to lowercase then perform bubble sort..//

    transform(alpha_order.begin(), alpha_order.end(), alpha_order.begin(), ::tolower);



    for (int i = 0; i < alpha_order.length(); i++)
    {
        bool swapped = false;
        for (int j = 0; j < alpha_order.length() - 1; j++)
        {
            if (alpha_order[j] > alpha_order[j + 1])
            {
                char temp = alpha_order[j];
                alpha_order[j] = alpha_order[j + 1];
                alpha_order[j + 1] = temp;
                swapped = true;
            }
        }

        if (swapped == false)
        {
            break;
        }
    }

    cout << "String ordered according to chronlogical characters :" << alpha_order << endl;

    // (e)

    char chr;
    cout << "Please enter your character (UPPERCASE) : ";
    cin >> chr;
    cout << endl;

    chr += 32;

    cout << "Your character in lowercase : " << chr << endl;




    return 0;
}