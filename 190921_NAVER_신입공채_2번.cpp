#include <string>
#include <vector>
#include <set>
#include <iostream>
using namespace std;

vector<string> map;
bool star = false;
int Msize, s;
set <int> finish;

bool OOP(int x, int y) {
	return x < Msize&&x >= 0 && y < Msize&&y >= 0;
}
void next(char c, int x, int y) {
		//cout<<x<<" "<<y<<'\n';
	switch (c) {
	case '#':
		if (x + 1 == Msize) {//cout<<s<<"\n";
			finish.insert(s); return;
		}
		next(map[x + 1][y], x + 1, y);
		break;
	case '>':
		next(map[x][y + 1], x, y + 1);
		break;
	case '<':
		next(map[x][y - 1], x, y - 1);
		break;
	case '*':
		if (star) return;
		star = true;
		next(map[x + 1][y], x + 1, y);
		break;
	}
}

void start(char c, int x, int y) {
	//cout<<x<<" "<<y<<'\n';
	switch (c) {
	case '#':
		next(map[x + 1][y], x + 1, y);
		break;
	case '>':
		next(map[x][y + 1], x, y + 1);
		break;
	case '<':
		next(map[x][y - 1], x, y - 1);
		break;
	case '*':
		star = true;
		next(map[x + 1][y], x + 1, y);
		break;
	}
}
int solution(vector<string> drum) {
	map = drum;
	Msize = drum.size();
	for (int i = 0; i < drum[0].size(); i++) {
		s = i;
		star = false;
		start(map[0][i], 0, i);
		//cout << "\n";
	}
	int answer = finish.size();
	return answer;
}

int main() {
	vector<string> input = { "######", ">#*###", "####*#", "#<#>>#", ">#*#*<", "######" };
	cout<<solution(input)<<"\n";

	return 0;
}