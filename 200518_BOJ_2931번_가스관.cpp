#include <iostream>
#include <queue>
using namespace std;

int r, c;
char map[26][26];

int dx[] = { -1, 0, 1, 0 };
int dy[] = { 0, 1, 0, -1 };

bool Zbool,Mbool;
queue <pair<int, int>> mq, zq;
typedef struct st{
	int x, y, d;
}st;


st can_start(queue <pair<int, int>> &q){


	int x = q.front().first;
	int y = q.front().second;

	for (int i = 0; i < 4; i++){
		int nx = x + dx[i];
		int ny = y + dy[i];

		if (nx < 0 || nx >= r || ny < 0 || ny >= c || map[nx][ny] == '.' || map[nx][ny] == 'Z' || map[nx][ny] == 'M')continue;

		return{ nx, ny, i };
	}
	return{ -1, -1,-1 };
}

bool can_go(int x, int y, int d)
{
	if (d == 0){
		if (map[x][y] == '1' || map[x][y] == '+' || map[x][y] == '4' || map[x][y] == '|' || (!Zbool&&map[x][y] == 'Z') || (!Mbool&&map[x][y] == 'M'))
			return true;
	}
	else if (d == 1){
		if (map[x][y] == '-' || map[x][y] == '+' || map[x][y] == '3' || map[x][y] == '4' || (!Zbool&&map[x][y] == 'Z') || (!Mbool&&map[x][y] == 'M'))
			return true;
	}
	else if (d == 2){
		if (map[x][y] == '|' || map[x][y] == '+' || map[x][y] == '2' || map[x][y] == '3' || (!Zbool&&map[x][y] == 'Z') || (!Mbool&&map[x][y] == 'M'))
			return true;
	}
	else if (d == 3){
		if (map[x][y] == '-' || map[x][y] == '+' || map[x][y] == '1' || map[x][y] == '2' || (!Zbool&&map[x][y] == 'Z') || (!Mbool&&map[x][y] == 'M'))
			return true;
	}
	return false;
}
char get_adopt(int x, int y){
	int ch[4] = { 0, 0, 0, 0 };
	for (int i = 0; i < 4; i++){
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (nx < 0 || nx >= r || ny < 0 || ny >= c)continue;
		if (can_go(nx, ny, i))
			ch[i] = 1;
	}
	//for (int i = 0; i < 4;i++)
	//	cout << ch[i];
	if (ch[0] == 1 && ch[1] == 1 && ch[2] == 0 && ch[3] == 0)
		return '2';
	else if (ch[0] == 1 && ch[1] == 0 && ch[2] == 1 && ch[3] == 0)
		return '|';
	else if (ch[0] == 1 && ch[1] == 0 && ch[2] == 0 && ch[3] == 1)
		return '3';
	else if (ch[0] == 0 && ch[1] == 1 && ch[2] == 1 && ch[3] == 0)
		return '1';
	else if (ch[0] == 0 && ch[1] == 1 && ch[2] == 0 && ch[3] == 1)
		return '-';
	else if (ch[0] == 0 && ch[1] == 0 && ch[2] == 1 && ch[3] == 1)
		return '4';
	else if (ch[0] == 1 && ch[1] == 1 && ch[2] == 1 && ch[3] == 1)
		return '+';
	else
		return  'n';
}
void dfs(int x, int y,int d){


	if (map[x][y] == '.'){
		cout<<x+1<<" "<<y+1<<" "<< get_adopt(x, y)<<"\n";
		return;
	}

	if (map[x][y] == '1'){
		if (d == 0)
			dfs(x + dx[1], y + dy[1], 1);
		else if (d == 3)
			dfs(x + dx[2], y + dy[2], 2);
	}
	else if (map[x][y] == '2'){
		if (d == 2)
			dfs(x + dx[1], y + dy[1], 1);
		else if (d == 3)
			dfs(x + dx[0], y+ dy[0], 0);
	}
	else if (map[x][y] == '3'){
		if (d == 1)
			dfs(x + dx[0], y + dy[0], 0);
		else if (d == 2)
			dfs(x + dx[3], y + dy[3], 3);
	}
	else if (map[x][y] == '4'){
		if (d == 0)
			dfs(x + dx[3], y + dy[3], 3);
		else if (d == 1)
			dfs(x + dx[2], y + dy[2], 2);
	}
	else if (map[x][y] == '+'){
		if (d == 1)
			dfs(x + dx[1], y + dy[1], 1);
		else if (d == 3)
			dfs(x + dx[3], y + dy[3], 3);
		else if (d == 0)
			dfs(x + dx[0], y + dy[0], 0);
		else if (d == 2)
			dfs(x + dx[2], y + dy[2], 2);
	}
	else if (map[x][y] == '-'){
		if (d == 1)
			dfs(x + dx[1], y + dy[1], 1);
		else if (d == 3)
			dfs(x + dx[3], y + dy[3], 3);
	}
	else if (map[x][y] == '|'){
		if (d == 0)
			dfs(x + dx[0], y + dy[0], 0);
		else if (d == 2)
			dfs(x + dx[2], y + dy[2], 2);
	}

}


void sol(){
	st p = can_start(mq); 
	if (p.d != -1)
		Mbool = 1;

	p = can_start(zq);
	if (p.d != -1){
		Zbool = 1;
		dfs(p.x, p.y, p.d);
		return;
	}

	p = can_start(mq);
	
	dfs(p.x, p.y, p.d);

}


int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> r >> c;


	for (int i = 0; i < r; i++){
		for (int j = 0; j < c; j++){
			cin >> map[i][j];
			if (map[i][j] == 'M')
				mq.push(make_pair(i, j));
			else if (map[i][j] == 'Z')
				zq.push(make_pair(i, j));
		}
	}

	sol();


	return 0;
}

