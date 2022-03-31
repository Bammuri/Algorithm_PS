#include <string>
#include <sstream>
#include <iostream>
#include <cmath>


using namespace std;

int solution(string dartResult) {
	stringstream ss(dartResult);
	int answer = 0;
	int answerList[3] = { 0, };
	int strIdx = 0;
	
	for (int i = 0; i < 3; i++) {
		//parsing
		int score = 0;
		char bonus = 0;
		char option = 0;

		ss >> score;
		bonus = ss.get();
		option = ss.get();

		if (option != '*' && option != '#')
			ss.unget();

		//score
		answerList[i] = score;

		//bouns
		switch (bonus)
		{
		case 'S': 
			break;
		case 'D':
			answerList[i] = pow(answerList[i], 2);
			break;
		case 'T':
			answerList[i] = pow(answerList[i], 3);
			break;
		}

		//option
		if (option == 0) {
			continue;
		}
		else if (option == '#') {
			answerList[i] *= -1;
		}
		else if (option == '*') {
			if (i == 0) {
				answerList[i] *= 2;
			}
			else {
				answerList[i] *= 2; answerList[i - 1] *= 2;
			}
		}
	}

	for (auto a : answerList)
		answer += a;


	return answer;
}

int main() {
	string dartResult = "1S2D*3T";
	cout << solution(dartResult);

}