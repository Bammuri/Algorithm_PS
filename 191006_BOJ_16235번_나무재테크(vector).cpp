//2019.10.6 (일)
//처음에 거름은 5로 시작함 첫번쨰 오류 : 5분
//봄에 추가하고 여름에 영양분을 추가해야하는데 동시에 하다보니 두번째 오류 : 30분
//57번줄 sort()->insert로 바꿨더니 시간초과 이던것이 정답
//vector는 insert erase 시간이 많이 걸려 list나 deque 요망
//vector <vector<int> > a[10] 2차원 vector
//fill memset memcpy 
//vector.erase insert at find??
#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;



#define FOR(i,n) for(int i=0;i<n;i++)
int n, m, k,ans;
int veg[10][10], initveg[10][10],tveg[10][10];
vector <int> map[10][10];
int dx[8] = { -1, -1, 0, 1, 1, 1, 0, -1 };
int dy[8] = { 0, 1, 1, 1, 0, -1, -1, -1 };

void springsummer(){
	memset(tveg, 0, sizeof(tveg));

	FOR(i, n)FOR(j, n){
		int size = map[i][j].size();
		
		if (size){
			FOR(k, size){
				if (veg[i][j] >= map[i][j][k]){
					veg[i][j] -= map[i][j][k];
					map[i][j][k]++; 
				} else {
					tveg[i][j] += map[i][j][k] / 2;
					map[i][j].erase(map[i][j].begin() + k);
					k--; size--;
				}
			}
		}
	}
	FOR(i, n)FOR(j, n){
		veg[i][j] += tveg[i][j];
	}

}

void spread(int x, int y){

	FOR(i, 8){
		int nx = x + dx[i], ny = y + dy[i];
		if (nx < 0 || nx >= n || ny < 0 || ny >= n)continue;

		map[nx][ny].insert(map[nx][ny].begin(),1);
	}
}

void fall(){
	FOR(i, n)FOR(j, n){
		int size = map[i][j].size();
		if (size){
			FOR(k, size){
				if (map[i][j][k] % 5 == 0){
					spread(i, j);
				}
			}
		}
	}
}

void winter(){
	FOR(i, n)FOR(j, n){
		veg[i][j] += initveg[i][j];
	}
}
void printmap(){
	cout << "\n";
	FOR(i, n){
		FOR(j, n)cout << map[i][j].size() << " ";
		cout << "\n";
	}
	cout << "\n";
}

void printntri(){
	cout << "\n";
	FOR(i, n){
		FOR(j, n)cout << veg[i][j] << " ";
		cout << "\n";
	}
	cout << "\n";

}

void solve(){

	while (k--){
		springsummer();
		fall();
		winter();
		//printmap();
		//printntri();
	}
}

void ansp(){
	FOR(i, n)FOR(j, n){
		ans += map[i][j].size();
	}
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m >> k;
	
	FOR(i, n)
	FOR(j, n){
		cin >> initveg[i][j];
		veg[i][j] = 5;
	}

	FOR(i, m){
		int x, y, age;
		cin >> x >> y >> age;
		map[x - 1][y - 1].push_back(age);
	}
	solve();

	ansp();
	cout << ans;

	return 0;
}