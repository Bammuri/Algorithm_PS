/*#include <string>
#include <vector>
#include <iostream>
#include <sstream>

using namespace std;

string g_s;

string checkNextChar(int &idx)
{
	string s;
	if (g_s[idx] >= '0' && g_s[idx] <= '9') {
		s = g_s[idx]; idx += 1;
		return s;
	}
	
	switch (g_s[idx]) {
	case 'z':
		s = "0";
		idx += 4;
		return s;
	case 'o':
		s = "1";
		idx += 3;
		return s;
	case 't':
		if (g_s[idx + 1] == 'w') {
			s = "2"; idx += 3;
		}
		else {
			s = "3"; idx += 5;
		}

		return s;
	case 'f':
		if (g_s[idx + 1] == 'o') {
			s = "4"; idx += 4;
		}
		else {
			s = "5"; idx += 4;
		}
		return s;
	case 's':
		if (g_s[idx + 1] == 'i') {
			s = "6"; idx += 3;
		}
		else {
			s = "7"; idx += 5;
		}
		
		return s;
	case 'e':
		s = "8"; idx += 5;
		return s;
	case 'n':
		s = "9"; idx += 4;
		return s;

	}
}

int solution(string s) {
	string answer = "";
	g_s = s;
	int answerInt = 0;

	for (int i = 0; i < s.length();) {
		answer+= checkNextChar(i);
	}
	stringstream ssDoub(answer);
	ssDoub >> answerInt;
	return answerInt;
}

int main() {
	string str = "one4seveneight";

	cout <<solution(str);// << "\n";
}
*/


#include <string>
#include <vector>
#include <algorithm>
#include <regex>

using namespace std;

vector<string> numbers = { "zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine", "ten" };

int solution(string s) {
	int answer = 0;
	regex r;
	for (int i = 0; i < numbers.size(); i++) {
		r = numbers[i];
		s = regex_replace(s, r, to_string(i));
	}
	answer = stoi(s);
	return answer;
}
