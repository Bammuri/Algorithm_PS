#include <iostream>
#include <string>
#include <queue>
using namespace std;


string recursive(string &input,int &error){
	int num = 0;
	string answer = "";
	queue <char> q;
	int st_idx = -1;
	int cnt = 0;
	int scnt = 0;
	int ecnt = 0;
	bool cnt_flag = false;

	for (int i = 0; i < input.size(); i++) {
		if (!cnt_flag){
			if (input[i] >= '0' && input[i] <= '9') {
				if (num != 0)
					num *= 10 + input[i] - '0';
				else
					num = input[i] - '0';
			}
			else if (input[i] == '{') {
				cnt_flag = true;
				st_idx = i + 1;
				scnt++;
			}
			else if (input[i] >= 'a' && input[i] <= 'z') {
				answer += input[i];
			}
		}
		else {
			if (input[i] == '}')
				ecnt++;
			else if (input[i] == '{')
				scnt++;
			cnt++;
			if (scnt == ecnt){
				for (int i = 0; i < num; i++)
					answer += recursive(input.substr(st_idx, cnt - 1),error);
				cnt = 0;
				num = 0;
				cnt_flag = false;
			}
		}
	}
	//cout << input<<" "<<answer << "\n";
	if (answer == "")
		error = 1;
	return answer;
}

string solution(string &input){
	int error = 0;
	string answer = recursive(input, error);
	if (error)
		return "ERROR";
	return answer;
}

int main(){
	string input = "2{b3{ab}3{tc}}";
	cout<<solution(input)<<"\n";
	input = "a1{abc}";
	cout << solution(input) << "\n";
	input = "2{3{ab}2{d}}";
	cout << solution(input) << "\n";
	input = "abcd";
	cout << solution(input) << "\n";
	input = "abd2{ab}";
	cout << solution(input) << "\n";
	return 0;
}