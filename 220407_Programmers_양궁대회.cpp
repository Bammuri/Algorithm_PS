#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<int> g_answer;
int g_maxGap;



bool compLastScore(vector<int>& lion) {
	if (g_answer.empty())
		return true;
	for (int i = 10; i >= 0; i--) {
		if (lion[i] > g_answer[i]) return true;
		if (lion[i] < g_answer[i]) return false;
	}
	return true;
}

void calScore(vector<int>& lion, vector<int>& apeche)
{
	int lionScore = 0, apecheScore = 0;


	for (int i = 0; i < apeche.size(); i++) {
		if (lion[i] > 0 || apeche[i] > 0) {
			if (lion[i] > apeche[i]) {
				lionScore += 10 - i;
			}
			else {
				apecheScore += 10 - i;
			}
		}
	}
	int scoreGap = lionScore - apecheScore;
	if (scoreGap > 0 && ((g_maxGap < scoreGap) || (g_maxGap == scoreGap && compLastScore(lion)))) {
		g_maxGap = scoreGap;
		g_answer = lion;
	}

}

// 0 1 2 3 4 5 6 7 8 9 10 (11개)
void dfs(int depth, int arrowNum, vector<int>& lion, vector<int>& apeche) {
	if (depth == 10 || arrowNum == 0) {
		if (arrowNum > 0)
			lion[10] = arrowNum;
		calScore(lion, apeche);
		if (arrowNum > 0)
			lion[10] = 0;
		return;
	}
	//선택
	if (arrowNum >= apeche[depth] + 1) {
		lion[depth] = apeche[depth] + 1;
		dfs(depth + 1, arrowNum - lion[depth], lion, apeche);
	}
	//no 선택
	lion[depth] = 0;
	dfs(depth + 1, arrowNum, lion, apeche);
}

vector<int> solution(int n, vector<int> info) {
	vector<int> lion = { 0,0,0,0,0,0,0,0,0,0,0 };

	dfs(0, n, lion, info);

	if (g_answer.empty())
		g_answer.push_back(-1);
	return g_answer;
}


int main() {
	vector<int> info = { 1,0,0,0,0,0,0,0,0,0,0 };
	vector<int> ans = solution(1, info);


	for (auto& i : ans)
		cout << i << " ";
	return 0;
}