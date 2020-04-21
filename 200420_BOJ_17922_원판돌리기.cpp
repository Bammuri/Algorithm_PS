//12 20시작
//13 20 초기완성 but 틀림
//14 44 다시 시작
//16 -30 찾음 모듈러연산문제 -1%3 c++에서는 -1이나옴
#include <iostream>
#include <cstring>
using namespace std;


int N,M,T;
int map[50][50];
int check[50][50];
int dx[4] = {0,1,-1,0};
int dy[4] = {1,0,0,-1};


void printmap()
{
	for (int i = 0; i < N; i++){
		for (int j = 0; j < M; j++)
			cout << map[i][j];
		cout << "\n";
	}
}


void spin(int i,int d){

	if (d == 0){
		int tmp = map[i][M - 1];
		for (int j = M - 1; j >= 1; j--)
			map[i][j] = map[i][j - 1];
		map[i][0] = tmp;
	}
	else{
		int tmp = map[i][0];
		for (int j = 0; j < M - 1; j++)
			map[i][j] = map[i][j + 1];
		map[i][M - 1] = tmp;
	}
}


void rotate(int x, int d, int k){

	for (int i = x; i < N + 1;i+=x){
			for (int a = 0; a < k; a++)
				spin(i-1,d);
	}

}

int find_num(int x,int y)
{
	int tar = map[x][y];
	int flag = 0;

	for (int i = 0; i < 4; i++){
		int nx = x + dx[i];
		int ny = (y + dy[i]) % M;
		if (ny == -1)
			ny = M - 1;
		if (nx < 0 || nx >= N) continue;
		if (map[nx][ny] == tar){
			check[nx][ny] = 1;
			flag = 1;
		}
	}
	if (flag){
		check[x][y] = 1;
		return 0;
	}
	return 1;
}

void plus_minus(){
	int sum = 0;
	int cnt = 0;
	for (int i = 0; i < N; i++){
		for (int j = 0; j < M; j++){
			if (map[i][j]){
				sum += map[i][j];
				cnt++;
			}
		}
	}
	double ave = (double)sum / cnt;

	for (int i = 0; i < N; i++){
		for (int j = 0; j < M; j++){
			if (!map[i][j]) continue;
			if (ave < (double)map[i][j])
				map[i][j]--;
			else if (ave >(double)map[i][j])
				map[i][j]++;
		}
	}


}

void del_num(){
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			if (check[i][j])
				map[i][j] = 0;

}

void after_process()
{
	int flag = 1;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			if (map[i][j])
				flag *= find_num(i, j);
	if (flag)
		plus_minus();
	else
		del_num();

}

int get_sum(){
	int ans = 0;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			if (map[i][j])
				ans += map[i][j];
		
	return ans;
}
int main(){

	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> M >> T;

	for (int i = 0; i < N; i++){
		for (int j = 0; j < M; j++){
			cin >> map[i][j];
		}
	}

	for (int i = 0; i < T; i++){
		int x, d, k;
		cin >> x >> d >> k;
		//printmap();
		rotate(x,d,k);
		memset(check, 0, sizeof(check));
		after_process();
		//printmap();
	}

	cout<<get_sum();
	return 0;
}