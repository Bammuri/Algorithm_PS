//45분완성 q.pop() 안, 범위오류 
//90분AC 처음 값 입력 오류, while문 안에 넣으면 안댐
#include <iostream>
#include <cstring>
#include <queue>
#include <cmath>
using namespace std;

int map[20][20],tmap[20][20],prmap[20][20];
int N,total_sum,ans=1987654321;
int dx[4] = { 0, 0, 1, -1 };
int dy[4] = { 1, -1, 0, 0 };

typedef struct lo{
	int x, y;
}lo;



void printmap(int cmap[20][20]){
	cout << "\n";
	for (int x = 0; x < N; x++){
		for (int y = 0; y < N; y++){

			cout << cmap[x][y] << " ";
		}
		cout << "\n";
	}

}

int calcul(int rs, int re, int cs, int ce,int sun)
{
	queue <lo> q;
	int sum=0;
	switch(sun){
	case 1:
		q.push({ 0, 0 });
		tmap[0][0] = 1;
		sum += map[0][0];
		break;
	case 2:
		q.push({ 0, N - 1 });
		tmap[0][N-1] = 1;
		sum += map[0][N-1];
		break;
	case 3:
		q.push({ N - 1, 0 });
		tmap[N-1][0] = 1;
		sum += map[N-1][0];
		break;
	case 4:
		q.push({ N - 1, N - 1 });
		tmap[N-1][N-1] = 1;
		sum += map[N-1][N-1];
		break;
	} 

	while (!q.empty()){
		int x = q.front().x;
		int y = q.front().y;
		
		q.pop();
		//cout << x <<" "<< y<<"\n";
		for (int d = 0; d < 4; d++){
			int nx = x + dx[d];
			int ny = y + dy[d];
			if (tmap[nx][ny] || nx < rs || nx > re || ny < cs || ny > ce) continue;
			tmap[nx][ny] = 1;
			sum += map[nx][ny];
			//cout << nx << " " << ny << "\n";
			q.push({ nx, ny });
		}

	}
	//cout << sum<<" ";
	return sum;
}

void go(int x, int y){

	for (int d1 = 1; d1 < N; d1++){
		for (int d2 = 1; d2 < N; d2++){
			if (y - d1 < 0 || y + d2 >= N) continue;
			if (x + d1 + d2 >= N) continue;
			memset(tmap, 0, sizeof(tmap));

			for (int i = 0; i <= d1; i++){
				tmap[x + i][y - i] = 1;
				tmap[x + d2 + i][y + d2 - i] = 1;
			}

			for (int i = 0; i <= d2; i++){
				tmap[x + i][y + i] = 1;
				tmap[x + d1 + i][y - d1 + i] = 1;
			}
			//printmap(tmap);
			int s1 = calcul(0, x + d1 - 1, 0, y,1);
			//printmap(tmap);
			int s2 = calcul(0, x + d2, y, N - 1,2);
			//printmap(tmap);
			int s3 = calcul(x + d1, N - 1, 0, y - d1 + d2 - 1,3);
			//printmap(tmap);
			int s4 = calcul(x + d2, N - 1, y - d1 + d2 - 1, N - 1,4);
			//printmap(tmap);
			int s5 = total_sum - s1 - s2 - s3 - s4;
			int mx = max(max(max(max(s1, s2), s3), s4), s5);
			int mn = min(min(min(min(s1, s2), s3), s4), s5);

			if (ans > mx - mn){
				memcpy(prmap, tmap, sizeof(tmap));
				ans = mx - mn;
			}
		}
	}
}

void sol(){
	
	for (int x = 0; x < N; x++){
		for (int y = 0; y < N; y++){
			
			go(x, y);
		}
	}


}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N;

	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++){
			cin >> map[i][j];
			total_sum += map[i][j];
		}

	sol();
	cout << ans<<"\n";

	//printmap(prmap);
	return 0;
}