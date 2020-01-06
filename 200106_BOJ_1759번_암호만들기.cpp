#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector <char> lst,answer;
int L, C,nm=0,nz=0;
int visit[15];

bool ismo(char &c) {

	switch (c) {
	case 'a':
	case 'e':
	case 'o':
	case 'i':
	case 'u':
		return true;
	}
	return false;

}

bool getzm() {
	int nm = 0, nz = 0;
	for (char c : answer) {

		if (ismo(c)) {
			nm++;
		}
		else {
			nz++;
		}
	}

	if (nm >= 1 && nz >= 2)
		return true;
	else
		return false;

}

void dfs(int depth,int idx) {
	if (depth == L) {
		if (getzm()) {
			for (auto c : answer)
				cout << c;
			cout << "\n";
		}
		return;
	}

	
	for (int i = idx; i < C;i++) {

		if (visit[i]) continue;

		visit[i] = 1;

		answer.push_back(lst[i]);
		dfs(depth + 1,i+1);
		answer.pop_back();

		
		visit[i] = 0;
	}


}



int main() {
	cin >> L >> C;
	
	for (int i = 0; i < C; i++) {
		char c;
		cin >> c;
		lst.push_back(c);
	}

	sort(lst.begin(), lst.end());

	dfs(0,0);

	return 0;
}