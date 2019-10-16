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

typedef struct tree{
	vector <int> a;
}Tree;

#define FOR(i,n) for(int i=0;i<n;i++)
int n, m, k,ans;
int veg[100][100], initveg[100][100],tveg[100][100];
Tree map[100][100];
int dx[8] = { -1, -1, 0, 1, 1, 1, 0, -1 };
int dy[8] = { 0, 1, 1, 1, 0, -1, -1, -1 };

void springsummer(){
	memset(tveg, 0, sizeof(tveg));

	FOR(i, n)FOR(j, n){
		int size = map[i][j].a.size();
		
		if (size){
			FOR(k, size){
				if (veg[i][j] >= map[i][j].a[k]){
					veg[i][j] -= map[i][j].a[k];
					map[i][j].a[k]++; 
				} else {
					tveg[i][j] += map[i][j].a[k] / 2;
					map[i][j].a.erase(map[i][j].a.begin() + k);
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

		map[nx][ny].a.insert(map[nx][ny].a.begin(),1);
	}
}

void fall(){
	FOR(i, n)FOR(j, n){
		int size = map[i][j].a.size();
		if (size){
			FOR(k, size){
				if (map[i][j].a[k] % 5 == 0){
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
		FOR(j, n)cout << map[i][j].a.size() << " ";
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
		ans += map[i][j].a.size();
	}
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m >> k;
	
	FOR(i, n)
	FOR(j, n){
		cin >> initveg[i][j];
	}

	FOR(i, m){
		int x, y, age;
		cin >> x >> y >> age;
		map[x - 1][y - 1].a.push_back(age);
	}
	fill(veg[0], veg[0]+ 100*100, 5);
	solve();

	ansp();
	cout << ans;

	return 0;
}