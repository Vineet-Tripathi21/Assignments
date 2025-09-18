#include <iostream>
#include <string>
using namespace std;

int main() {

	string str1 = "listen";
	string str2 = "silent";
	int sum_str1 = 0;
	int sum_str2 = 0;


	if (str1.length() != str2.length()) {
		printf("The strings are not Anagrams.");
	}
	else {
		for (int i = 0; i < str1.length(); i++) {
			sum_str1 += str1[i];
			sum_str2 += str2[i];

		}
		if (sum_str1 == sum_str2) {
			printf("The strings are Anagrams.");
		}
		else {
			printf("The strings are not Anagrams.");
		}
			
			
	}
	
}