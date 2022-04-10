#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(vector<vector<int>> board, vector<vector<int>> skill) {
	int answer = 0;
	vector<vector<int>> cs(board.size() + 1,vector<int>(board[0].size() + 1,0));

	for (auto iter : skill) {
		int r1 = iter[1], c1 = iter[2];
		int r2 = iter[3], c2 = iter[4];
		int val = (iter[0] == 1) ? iter[5] * -1 : iter[5];

		cs[r1][c1] += val;
		cs[r2 + 1][c2 + 1] += val;
		cs[r1][c2 + 1] += val * -1;
		cs[r2 + 1][c1] += val * -1;
	}

	for (int i = 0; i < cs.size(); i++) {
		for (int k = 1; k < cs[0].size(); k++) {
			cs[i][k] += cs[i][k - 1];
		}
	}

	for (int i = 0; i < cs[0].size(); i++) {
		for (int k = 1; k < cs.size(); k++) {
			cs[k][i] += cs[k - 1][i];
		}
	}

	for (int i = 0; i < board.size(); i++) {
		for (int k = 0; k < board[0].size(); k++) {
			board[i][k] += cs[i][k];
			if (board[i][k] > 0) answer++;
		}
	}

	return answer;
}

int main() {

	vector<vector<int>> board = { {5,5,5,5,5},{5,5,5,5,5},{5,5,5,5,5},{5,5,5,5,5} };
	vector<vector<int>> skill = { {1, 0, 0, 3, 4, 4},{1, 2, 0, 2, 3, 2},{2, 1, 0, 3, 1, 2},{1, 0, 1, 3, 3, 1}};

	cout<< solution(board, skill);


	return 0;
}