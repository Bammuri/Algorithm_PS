#include <iostream>
#include <algorithm>
using namespace std;

int n, m, k;
int board[42][42];
int r, c;
int paper[12][12];

// paper를 90도 회전하는 함수
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

// board에 스티커가 붙을 수 있는 자리가 있는지 확인하는 함수. 자리가 있을 경우 board를 갱신한 후 true를 반환.
bool paste_check(){
	for (int x = 0; x <= n - r; x++){
		for (int y = 0; y <= m - c; y++){ // (x,y)에 모눈종이의 (0,0)이 올라간다.
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
			// (x,y) ~ (x+r-1, y+c-1)에 스티커를 붙일 수 있다.
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
		rotate(); // 90도
		if (paste_check()) continue;
		rotate(); // 180도
		if (paste_check()) continue;
		rotate(); // 270도
		if (paste_check()) continue;
	}
	int cnt = 0;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			cnt += board[i][j];
	cout << cnt << '\n';
}