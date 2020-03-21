#include <iostream>
#include <algorithm>
using namespace std;

int n, m, k;
int board[42][42];
int r, c;
int paper[12][12];

// paper�� 90�� ȸ���ϴ� �Լ�
void rotate(){
	int tmp[12][12];

	for (int i = 0; i < r; i++)
		for (int j = 0; j < c; j++)
			tmp[i][j] = paper[i][j];

	for (int i = 0; i < c; i++)
		for (int j = 0; j < r; j++)
			paper[i][j] = tmp[r - 1 - j][i];

	swap(r, c);
}

// board�� ��ƼĿ�� ���� �� �ִ� �ڸ��� �ִ��� Ȯ���ϴ� �Լ�. �ڸ��� ���� ��� board�� ������ �� true�� ��ȯ.
bool paste_check(){
	for (int x = 0; x <= n - r; x++){
		for (int y = 0; y <= m - c; y++){ // (x,y)�� �������� (0,0)�� �ö󰣴�.
			bool pastable = true;
			for (int i = 0; i < r; i++){
				if (!pastable) break;
				for (int j = 0; j < c; j++){
					if (board[x + i][y + j] == 1 && paper[i][j] == 1){
						pastable = false;
						break;
					}
				}
			}
			if (!pastable) continue;
			// (x,y) ~ (x+r-1, y+c-1)�� ��ƼĿ�� ���� �� �ִ�.
			for (int i = 0; i < r; i++){
				for (int j = 0; j < c; j++){
					if (paper[i][j] == 1)
						board[x + i][y + j] = 1;
				}
			}
			return true;
		}
	}
	return false;
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m >> k;
	while (k--){
		cin >> r >> c;
		for (int i = 0; i < r; i++)
			for (int j = 0; j < c; j++)
				cin >> paper[i][j];
		if (paste_check()) continue;
		rotate(); // 90��
		if (paste_check()) continue;
		rotate(); // 180��
		if (paste_check()) continue;
		rotate(); // 270��
		if (paste_check()) continue;
	}
	int cnt = 0;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			cnt += board[i][j];
	cout << cnt << '\n';
}