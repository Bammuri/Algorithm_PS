#include <iostream>
#include <string>
using namespace std;
int N, K;

int ch[26], mx = 0, ap[26];
string stArr[50];


int check() {
	int anscnt = 0;
	for (int i = 0; i < N; i++) {
		bool flag = false;
		for (int j = 4; j < stArr[i].size() - 4; j++) {
			if (ch[stArr[i][j] - 'a'] == 0) { flag = true; break; }
		}
		if (flag == false) {
			anscnt++;
		}

	}
	return anscnt;
}

void dfs(int cur, int pick) {
	if (pick == K) {

		int tmp = check();
		if (mx < tmp)
			mx = tmp;
		return;
	}

	for (int i = cur; i <26; i++) {

		if (ch[i] == 0) {
			ch[i] = 1;
			dfs(i + 1, pick + 1);
			ch[i] = 0;
		}
	}



}



int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	ch['a' - 'a'] = 1;
	ch['t' - 'a'] = 1;
	ch['n' - 'a'] = 1;
	ch['i' - 'a'] = 1;
	ch['c' - 'a'] = 1;
	ap['a' - 'a'] = 1;
	ap['t' - 'a'] = 1;
	ap['n' - 'a'] = 1;
	ap['i' - 'a'] = 1;
	ap['c' - 'a'] = 1;

	cin >> N >> K;



	for (int i = 0; i < N; i++) {
		cin >> stArr[i];
		for (int j = 4; j < stArr[i].size() - 4; j++) {
			ap[stArr[i][j] - 'a'] = 1;
		}
	}

	if (K < 5) {
		cout << "0\n";
	}
	else {
		dfs(0, 5);
		cout << mx<<"\n";
	}


	return 0;
}