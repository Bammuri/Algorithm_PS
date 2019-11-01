//1205 시작 1255종료
#include <string>
#include <vector>
#include <stack>

using namespace std;


string answer = "";

bool al(string str){
	int o = 0, c = 0;
	stack <char> s;
	for (int i = 0; i<str.size(); i++){
		if (str[i] == '('){
			s.push('(');
		}
		else {
			if (s.empty()){
				return false;
			}
			s.pop();
		}
	}
	return true;

}

string recur(string str){
	string tmp;
	int size = str.size();
	if (size == 0) return str;

	string u = "", v = "";
	int o = 0, c = 0;
	for (int i = 0; i<size; ++i){
		if (o == c&&o != 0 && c != 0){
			v += str[i];
		}
		else {
			if (str[i] == '('){
				++o;
				u += str[i];
			}
			else {
				++c;
				u += str[i];
			}
		}
	}

	if (al(u)){
		tmp += u + recur(v);
	}
	else {
		tmp += '(' + recur(v) + ')';

		for (int i = 1; i<u.size() - 1; i++){
			if (u[i] == '('){
				tmp += ')';
			}
			else{
				tmp += '(';
			}
		}
	}
	return tmp;
}

string solution(string p) {
	answer += recur(p);

	return answer;
}