//1611 ����
//1710 �������� tc1�� ���� ���� 
//1733 ����ִ� �ٱ������ ����.. �ľ�...
//+10 tc �ϳ� ����
//+30 ������ �ٽ� �ľ��ؼ� ����.. tc �ٸ���
//pass 2�ð��� ������ ���Ǵ�� ������ ����
#include <iostream>
#include <list>
#include <algorithm>

using namespace std;
#define FOR(i,n) for(int i=0;i<n;++i)

int k,ans=0;
int dx[4] = { 1, -1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };

struct cell{
	int x,y, life,count,live;
	bool operator<(const cell &o)const{
		return life > o.life;
	}
};

list <cell> cs;

int visit[350][350];

void solve(){
	while (k--){
		int size = cs.size();
		list <cell>::iterator it = cs.begin();
		while (size--){
			cell can = (*it);

			(*it).count--;

			if ((*it).live == 1 && (*it).life - 1 == (*it).count){
				FOR(a, 4){
					int nx = can.x + dx[a], ny = can.y + dy[a];
					if (visit[nx][ny] == 1)continue;

					visit[nx][ny] = 1; ans++;
					cs.push_back({ nx, ny, can.life, can.life, 0 });
				}
			}

			if ((*it).count == 0){
				if ((*it).live == 1){
					cs.erase(it++);
				}
				else{
					(*it).live = 1;
					(*it).count = can.life;
					++it;
				}
			}
			else{
				++it;
			}

		}
		cs.sort();
	}

	

}


int main(int argc, char** argv)
{
	int test_case;
	int T;

	cin >> T;

	for (test_case = 1; test_case <= T; ++test_case)
	{
		int n, m;
		ans = 0;
		cin >> n >> m >> k;
		cs.clear();
		memset(visit, 0, sizeof(visit));
		for(int i=150;i<150+n;i++)
			for (int j = 150; j < 150 + m; j++){
				
				int life;
				cin >> life;
				if (life != 0){
					ans++;
					cs.push_back({ i, j, life, life,0 });
					visit[i][j] = 1; 
				}
			}


		solve();
		cout <<"#"<<test_case<<" "<< cs.size()<< "\n";
	}
	return 0;
}