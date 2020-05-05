//2210시작
//2250 완성 TC다맞음 및 시간초과
//2306 sort 제거 vector.insert로 대체 AC
#include <iostream>
#include <vector>
using namespace std;

int N, M, K;

int A[10][10];
int dx[] = {-1,-1,-1,0,0,1,1,1};
int dy[] = {-1,0,1,-1,1,-1,0,1};
int nutri[10][10];
int summerplusnutri[10][10];
vector<int> map[10][10];



void spring()
{
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (!map[i][j].empty()) {
				for (int k = 0; k < map[i][j].size(); k++) {
					if (nutri[i][j] >= map[i][j][k]) {
						nutri[i][j] -= map[i][j][k];
						map[i][j][k]++;
					}
					else {
						summerplusnutri[i][j] += map[i][j][k] / 2;
						map[i][j].erase(map[i][j].begin()+k);
						k--;
					}
				}

			}
		}
	}
}


void summer() {
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			nutri[i][j] += summerplusnutri[i][j];
}

void fall() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (!map[i][j].empty()) {
				for (int k = 0; k < map[i][j].size(); k++) {
					if (map[i][j][k] % 5 == 0) {
						for (int a = 0; a < 8; a++) {
							int nx = i + dx[a];
							int ny = j + dy[a];
							if (nx >= N || nx < 0 || ny >= N || ny < 0)continue;
							map[nx][ny].insert(map[nx][ny].begin(), 1);
						}
					}
				}
			
			}
		}
	}

}

void winter() {
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
		nutri[i][j] += A[i][j];
	
}
int getTreeNum() {
	int sm = 0;
	for (int i = 0; i < N; i++) 
		for (int j = 0; j < N; j++) 
			sm += map[i][j].size();

	return sm;
}

int sol() {

	for (int i = 0; i < K; i++) {
		memset(summerplusnutri, 0, sizeof(summerplusnutri));
		spring();
		summer();
		fall();
		winter();
	}

	return getTreeNum();

}


int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> M >> K;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> A[i][j];
			nutri[i][j] = 5;
		}
	}

	for (int i = 0; i < M; i++) {
		int x, y, z;
		cin >> x >> y >> z;

		map[x-1][y-1].push_back(z);
	}

	cout<<sol();
	

	return 0;
}