#include <iostream>
#include <string>
using namespace std;

int main(){

	//char to string
	char ch[10] = "hello";

	string str1(ch);

	string str2 = " ";
	str2 = ch;

	cout << "str1 : " << str1 << "\n";
	cout << "str2 : " << str2 << "\n";

	//string to char

	char ch2[10];

	strcpy(ch2, str2.c_str());

	cout << "ch2 : " << ch2 << "\n";


	return 0;
}