#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(string s) {
	int answer = s.length();

	for (int tokSize = 1; tokSize <= s.size() / 2; tokSize++) {
		string tans = "";
		string tokStr = s.substr(0, tokSize);
		int AppearCnt = 1;

		for (int i = tokSize; i < s.size(); i += tokSize) {
			if (tokStr == s.substr(i, tokSize)) {
				AppearCnt++;
			}
			else {
				if (AppearCnt > 1) tans += to_string(AppearCnt);
				tans += tokStr;
				
				tokStr = s.substr(i,tokSize);
				AppearCnt = 1;
			}
		}
		if (AppearCnt > 1) tans += to_string(AppearCnt);
		tans += tokStr;
		
		if (answer > tans.length()) answer = tans.length();
	}
	
	return answer;
}

int main() {
	vector<string> s = { "aabbaccc",
						"ababcdcdababcdcd",
						"abcabcdede",
						"abcabcabcabcdededededede",
						"xababcdcdababcdcd" };
	for (int i = 0; i < s.size(); i++)
		cout << solution(s[i])<<'\n';
}