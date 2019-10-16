//1150 ����
//1206 �ϼ� ���� 6���� 5�� ���� operator<����
//1319 ���� �ٸ� ���� 45���� ����
//1424 ���� m <-n ������... 2�ð� 30��;;
#include <iostream>
#include <queue>
#include <algorithm>
#include <algorithm>
#include <cstring>
using namespace std;
 
#define FOR(i,n) for(int i=0;i<n;i++)
int n, m, d,answer;
int imap[16][15], map[16][15], check[16][15], tmap[16][15];
int nums[3];
int dx[4] = { 1, -1, 0, 0 };
int dy[4] = { 0, 0, 1, -1 };

struct eme{
	int x, y;
	bool operator<(const eme& o)const{
		return y < o.y;
	}
};

void bfs(int i){

	queue <eme> q;
	vector <eme> ans;

	q.push({ n, nums[i] });
	int turn = d;
	while (turn--){
		int s = q.size();

		while (s--){
			int x = q.front().x;
			int y = q.front().y;
			q.pop();

			FOR(i, 4){
				int nx = x + dx[i];
				int ny = y + dy[i];
				if (nx >= n || ny >= m || nx < 0 || ny < 0)continue;


				if (map[nx][ny]){//���� �ִٸ� ���� �� �ִ� �ĺ�
					ans.push_back({ nx, ny });
				}
				q.push({ nx, ny });
			}
		}
		if (!ans.empty()){
			sort(ans.begin(), ans.end());//�Ÿ��� ���� �ĺ��鿡�� y��ǥ�� ���� ������ ����
			check[ans[0].x][ans[0].y]=1;//�� �ü��� ��ġ���� ���� ���� ��ǥ�� check�迭�� ǥ��
			return;
		}
	}
}

void go(){
	cout << "num " << nums[0] << nums[1] << nums[2] << "\n";
	int cnt = n;//�ִ� ���� �̵��ϴ� Ƚ�� ���� �� 
	int tmp = 0;
	while (cnt--){
		FOR(i, 3){
			bfs(i);//�� �ü��� ��ġ���� ���� ���� ��ǥ�� check�迭�� ǥ��
		}
		
		FOR(a, n)FOR(b, m){

			if (check[a][b]){//���� ���� ��ǥ�� check�� �Ǿ� �ִٸ� ���̰� ����
				check[a][b] = 0;
				map[a][b] = 0;
				tmp++;
			}
		}
		FOR(a,m)tmap[0][a] = 0;
		FOR(a, n-1)FOR(b, m){
			tmap[a + 1][b] = map[a][b];
		}
		memcpy(map, tmap, sizeof(tmap));

		cout << "\n"<<cnt;
		FOR(i, n){
			FOR(j, m){
				cout << map[i][j] << " ";
			}
			cout << "\n";
		}
		cout << "\n";
		cout << "tmp " << tmp << "\n";
	}

	cout << "tmp " << tmp << "\n";
	if (answer < tmp)answer = tmp;//�� ���տ��� �ִ밪 ����

}


void dfs(int ch, int depth){

	if (depth == 3){
		// 3���� �ü� ��ġ�� ������ ȭ�� �ùķ��̼�
		memcpy(map, imap, sizeof(imap));
		go();
		return;
	}

		for (int ne = ch + 1; ne < m; ne++){
			nums[depth] = ne;
			dfs(ne, depth + 1);
		}

}


void solve(){

	//nums�� �������� �ü��� 3���� ���� dfs�̿�
	FOR(i, n){
		nums[0] = i;
		dfs(i, 1);

	}

	cout << answer << "\n";
}



int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	//�ʱ�ȭ
	cin >> n >> m >> d;

	FOR(i, n)FOR(j, m){
		cin >> imap[i][j];
	}

	solve();

	
	return 0;
}