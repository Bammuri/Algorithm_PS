#include <iostream>
#include <vector>
#include <string>

using namespace std;

string top[3] = { "com","net","org" };
int answer = 0;



bool is_lowalpha(char cad) {
	return 'a' <= cad && cad <= 'z';
}

bool spc_char(char cad) {
	return cad == '@' || cad == '.';
}

void solve(string email) {
	bool flag0 = false, flag1 = false;
	for (int j = 0; j < email.size(); j++) {
		if (!flag0 && !is_lowalpha(email[j]) && !spc_char(email[j]))
			return;
		if (!flag1 && !is_lowalpha(email[j]) && !spc_char(email[j]))
			return;
		if (flag0&&email[j] == '@')return;
		if (flag1&&email[j] == '.')return;
		if (email[j] == '@') { flag0 = true; }
		else if (flag0&&email[j] == '.') { flag1 = true; continue; }
		//cout<<email[j]<<'\n';
		if (flag0&&flag1) {
			for (int k = 0; k < 3; k++) {
				int start = j;
				int count = 0;
				for (int a = 0; a < 3; a++) {
					//cout<<email[start]<<" "<<top[k][a]<<"\n";
					if (top[k][a] == email[start++]) count++;
					if (count == 3) { answer++; return; }
				}
			}
		}
	}
}
int solution(vector<string> emails) {
	for (int i = 0; i < emails.size(); i++) {
		solve(emails[i]);
		cout << '\n';
	}
	return answer;
}


int main() {
	vector <string> emails={"d@co@m.com", "a@abc.com", "b@def.com", "c@ghi.net"};
	cout<<solution(emails)<<"\n";
	return 0;
}