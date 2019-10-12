/////////////////////////////////////////////////////////////////////////////////////////////
// �⺻ �����ڵ�� ���� �����ص� ���� �����ϴ�. ��, ����� ���� ����
// �Ʒ� ǥ�� ����� ���� �ʿ�� �����ϼ���.
// ǥ�� �Է� ����
// int a;
// float b, c;
// double d, e, f;
// char g;
// char var[256];
// long long AB;
// cin >> a;                            // int ���� 1�� �Է¹޴� ����
// cin >> b >> c;                       // float ���� 2�� �Է¹޴� ���� 
// cin >> d >> e >> f;                  // double ���� 3�� �Է¹޴� ����
// cin >> g;                            // char ���� 1�� �Է¹޴� ����
// cin >> var;                          // ���ڿ� 1�� �Է¹޴� ����
// cin >> AB;                           // long long ���� 1�� �Է¹޴� ����
/////////////////////////////////////////////////////////////////////////////////////////////
// ǥ�� ��� ����
// int a = 0;                            
// float b = 1.0, c = 2.0;               
// double d = 3.0, e = 0.0; f = 1.0;
// char g = 'b';
// char var[256] = "ABCDEFG";
// long long AB = 12345678901234567L;
// cout << a;                           // int ���� 1�� ����ϴ� ����
// cout << b << " " << c;               // float ���� 2�� ����ϴ� ����
// cout << d << " " << e << " " << f;   // double ���� 3�� ����ϴ� ����
// cout << g;                           // char ���� 1�� ����ϴ� ����
// cout << var;                         // ���ڿ� 1�� ����ϴ� ����
// cout << AB;                          // long long ���� 1�� ����ϴ� ����
/////////////////////////////////////////////////////////////////////////////////////////////
//1445�� ����
//1555�� �Ϸ�
//���Ѵ�� �Դٰ��� ó�� ����
//Ȧ��ó�� ����
//vector reset����
//+= =+����
//1627 �̵��� -20 1607 �������� 5���� 4�� ����
//map �ʱ�ȭ �̽� 30�� �ɷ� �ذ� but ����� �ð��ʰ� �ɸ�
//�� �� glo_visit�ְ�  15�� ��� �ð��ʰ� �ذ� 48�� ����
//2�� �ε��� ��Ÿ ���� 1715 
//�ذ� 2�ð� 10��
#include <iostream>
#include <vector>
#include <cstring>
#define FOR(i,n) for(int i=0;i<n;i++)

using namespace std;

typedef struct holl{
	int x, y;
};

int n,ans,tans;
int map[100][100], visit[100][100][4], glo_visit[100][100][4];
vector <holl> v[11];
// dir 0 �� 1 �� 2 �� 3 ��
int dx[4] = {0,1,0,-1};
int dy[4] = {1,0,-1,0};

void start(int x,int y, int dir){
	int sx = x, sy = y;
	//cout << "\n\n" << x << " " << y << " " << dir << "\n";
	while (1){
		//cout << "\n" << x << " " << y << " " << dir << " " << tans<<" "<<ans; "\n";
		x += dx[dir]; y += dy[dir];
		if (visit[x][y][dir])return;
		visit[x][y][dir]++;
		//cout << x << " " << y << " " << dir << " " << tans << " " << ans; "\n";
		if (x < 0){
			dir = 1; tans++; continue;
		} 
		else if (y < 0){ 
			dir = 0; tans++; continue;
		}
		else if (x>=n){
			dir = 3; tans++; continue;
		}
		else if (y>=n){
			dir = 2; tans++; continue;
		}
		//cout << x << " " << y << " " << dir << " " << tans << " " << ans; "\n";
		if (x == sx&&y == sy){
			ans < tans ? ans = tans : ans;
			return;
		}

		switch (map[x][y]){
		case -1:
			ans < tans ? ans = tans : ans;
			return;
		case 0:
			break;
		case 1:
			tans++;
			switch (dir){
			case 0:
				dir = 2;
				break;
			case 1:
				dir = 0;
				break;
			case 2:
				dir = 3;
				break;
			case 3:
				dir = 1;
				break;
			}
			break;
		case 2:
			tans++;
			switch (dir){
			case 0:
				dir = 2;
				break;
			case 1:
				dir = 3;
				break;
			case 2:
				dir = 1;
				break;
			case 3:
				dir = 0;
				break;
			}
			break;
		case 3:
			tans++;
			switch (dir){
			case 0:
				dir = 1;
				break;
			case 1:
				dir = 3;
				break;
			case 2:
				dir = 0;
				break;
			case 3:
				dir = 2;
				break;
			}
			break;
		case 4:
			tans++;
			switch (dir){
			case 0:
				dir = 3;
				break;
			case 1:
				dir = 2;
				break;
			case 2:
				dir = 0;
				break;
			case 3:
				dir = 1;
				break;
			}
			break;
		case 5:
			tans++;
			switch (dir){
			case 0:
				dir = 2;
				break;
			case 1:
				dir = 3;
				break;
			case 2:
				dir = 0;
				break;
			case 3:
				dir = 1;
				break;
			}
			break;
		case 6:
			if (v[6][0].x == x&&v[6][0].y == y){
				x = v[6][1].x, y = v[6][1].y;
			}
			else {
				x = v[6][0].x, y = v[6][0].y;
			}
			break;
		case 7:
			if (v[7][0].x == x&&v[7][0].y == y){
				x = v[7][1].x, y = v[7][1].y;
			}
			else {
				x = v[7][0].x, y = v[7][0].y;
			}
			break;
		case 8:
			if (v[8][0].x == x&&v[8][0].y == y){
				x = v[8][1].x, y = v[8][1].y;
			}
			else {
				x = v[8][0].x, y = v[8][0].y;
			}
			break;
		case 9:
			if (v[9][0].x == x&&v[9][0].y == y){
				x = v[9][1].x, y = v[9][1].y;
			}
			else {
				x = v[9][0].x, y = v[9][0].y;
			}
			break;
		case 10:
			if (v[10][0].x == x&&v[10][0].y == y){
				x = v[10][1].x, y = v[10][1].y;
			}
			else {
				x = v[10][0].x, y = v[10][0].y;
			}
			break;
		}
		
	}
}

void solve(){

	FOR(i, n){
		FOR(j, n){
			if (map[i][j] == 0){
				FOR(k, 4){
					if (glo_visit[i][j][k]) continue;
					glo_visit[i][j][k]=1;
					memset(visit, 0, sizeof(visit));
					tans = 0;
					start(i,j,k);
					int ii = i; int jj = j;
					switch (k){
					case 0:
						while (map[ii][jj] == 0&&jj<n){
							glo_visit[ii][jj][k] = 1;
							jj++;
						}
						break;
					case 1:
						while (map[ii][jj] == 0 && ii<n){
							glo_visit[ii][jj][k] = 1;
							ii++;
						}
						break;
					case 2:
						while (map[ii][jj] == 0 && jj>=0){
							glo_visit[ii][jj][k] = 1;
							jj--;
						}
						break;
					case 3:
						while (map[ii][jj] == 0 && ii >= 0){
							glo_visit[ii][jj][k] = 1;
							ii--;
						}
						break;
			
					}

				}
			}
		}
	}

}

int main(int argc, char** argv)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int test_case;
	int T;

	cin >> T;
	
	for (test_case = 1; test_case <= T; ++test_case)
	{
		vector <holl> v1[11];
		memcpy( v,  v1,sizeof(v));
		memset(map, 0, sizeof(map));
		memset(glo_visit, 0, sizeof(glo_visit));
		ans= 0;
		cin >> n;
		FOR(i, n)FOR(j, n){
			cin >> map[i][j];
			if (map[i][j] > 5 && map[i][j] < 11){
				v[map[i][j]].push_back({ i, j });
			}
		}

		solve();
		cout << "#" << test_case << " " << ans <<"\n";
	}
	return 0;
}