//1207
//1318 초안완성
//1320 TCAC
//바닥으로 떨어지는 경우 고려 x, q에 처음 들어가는 것이 dropable한지 확인 x
//1500drop check에 continue문넣어주니 AC
#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

int r, c,n;
int map[100][100],tmap[100][100];
int dx[] = { 1, 0, 0, -1 };
int dy[] = { 0, 1, -1, 0 };


void drop(int dropcnt){
	for (int i = 0; i < r; i++)
		for (int j = 0; j < c; j++)
			if (tmap[i][j])
				map[i + dropcnt][j] = tmap[i][j];

}


int drop_each(int ix, int iy){
	int dropable = ix == r - 1? 0:1;
	queue <pair<int, int>> q;
	memset(tmap, 0, sizeof(tmap));
	q.push(make_pair(ix, iy));
	tmap[ix][iy] = 1;
	map[ix][iy] = 0;
	
	while (!q.empty())
	{
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++){
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx < 0 || nx >= r || ny < 0 || ny >= c || map[nx][ny]==0 || tmap[nx][ny]) continue;
			tmap[nx][ny] = 1;
			map[nx][ny] = 0;
			if (nx == r - 1){
				dropable = 0;
				break;
			}
			q.push({ nx, ny });
		}
	}
	if (dropable){
		int dropcnt = 1;
		while (dropcnt < r){
			for (int i = 0; i < r; i++){
				for (int j = 0; j < c; j++){
					if ((tmap[i][j] && (i + dropcnt >= r)) || (tmap[i][j] && map[i + dropcnt][j])){
						//cout << "drop " << i << " " << j <<" "<<dropcnt<< "\n";
						drop(dropcnt - 1);
						return 1;
					}
				}
			}
			dropcnt++;
		}

	}

	for (int i = 0; i < r; i++)
		for (int j = 0; j < c; j++)
			if (tmap[i][j])
				map[i][j]=tmap[i][j];
	return 0;
}

void drop_check(int ix,int iy){
	map[ix][iy] = 0;

	for (int i = 0; i < 4; i++){
		int nx = ix + dx[i];
		int ny = iy + dy[i];
		if (nx < 0 || nx >= r || ny < 0 || ny >= c || map[nx][ny] == 0) continue;
		if (map[nx][ny] == 1){
			if (drop_each(nx, ny))
				return;
		}
	}

}

void thr(int h,int right){
	int x = r - h;
	int y = right ? c - 1 : 0;

	if (!right)
	{
		while (y < c){
			if (map[x][y] == 1){

				drop_check(x,y);
				return;
			}
			y++;
		}
	}
	else{
		while (y >= 0){
			if (map[x][y] == 1){
				drop_check(x,y);
				return;
			}
			y--;
		}
	}
}

void printmap(){
	cout << "\n";
	for (int i = 0; i < r; i++){
		for (int j = 0; j < c; j++){
			cout << map[i][j] << " ";
		}
		cout << "\n";
	}
}

void printans(){
	for (int i = 0; i < r; i++){
		for (int j = 0; j < c; j++){
			char ch = map[i][j] ? 'x' : '.';
			cout << ch ;
		}
		cout << "\n";
	}
}


int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> r >> c;

	for (int i = 0; i < r; i++){
		for (int j = 0; j < c; j++){
			char ch;
			cin >> ch;
			map[i][j] = (ch == '.' ? 0 : 1);
		}
	}

	cin >> n;

	for (int i = 0; i < n; i++){
		int x;
		cin >> x;
		thr(x,i%2);
		//printmap();
	}
	printans();

	return 0;
}