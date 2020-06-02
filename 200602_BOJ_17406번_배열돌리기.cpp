//1040 TC AC
//1055 AC 문제이해, 받는 인자를 섞어야함
#include <iostream>
#include <vector>
using namespace std;

int N, M , K;

int map[50][50], omap[50][50];

typedef struct unit{
	int r, c, s;
};

vector <unit> vec;
int order[6],visit[6];
int ans = 1e9;

void print_map(){
	cout << "\n";
	for (int i = 0; i < N; i++){
		for (int j = 0; j < M; j++){
			cout<<map[i][j]<<" ";
		}
		cout << "\n";
	}
}


void rotate(int r,int c,int ts){

	int tmp[50] = { 0, };
	int s = 1;
	//print_map();
	while (s <= ts){
		//print_map();
		for (int i = 0; i < s * 2; i++)
			tmp[i] = map[r - 1 - s][c - 1 - s + i];

		for (int i = 0; i < s * 2; i++)
			map[r - 1 - s + i][c - 1 - s] = map[r - 1 - s + i + 1][c - 1 - s];
		for (int i = 0; i < s * 2; i++)
			map[r - 1 + s][c - 1 - s + i] = map[r - 1 + s][c - 1 - s + i + 1];
		for (int i = 0; i < s * 2; i++)
			map[r - 1 + s - i][c - 1 + s] = map[r - 1 + s - i -1][c - 1 + s];
		for (int i = 0; i < s * 2; i++)
			map[r - 1 - s][c - 1 - s + i + 1] = tmp[i];

		s++;
	}

	//print_map();
}

int getAMin(){
	int tans = 1e9;
	for (int i = 0; i < N; i++){
		int tmp = 0;
		for (int j = 0; j < M; j++){
			tmp += map[i][j];
		}
		if (tans > tmp)
			tans = tmp;
	}
	return tans;
}

void dfs(int d){
	if (d == vec.size()){
		memcpy(map, omap, sizeof(map));

		for (int i = 0; i < d; i++){
			rotate(vec[order[i]].r, vec[order[i]].c, vec[order[i]].s);
		}
		int t= getAMin();
		if (ans > t)
			ans = t;
	}
	

	for (int i = 0; i < vec.size(); i++){
		if (visit[i]) continue;
		visit[i] = 1;
		order[d] = i;
		dfs(d+1);
		visit[i] = 0;
	}
}


int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> M >> K;

	for (int i = 0; i < N; i++){
		for (int j = 0; j < M; j++){
			cin >> omap[i][j];
		}
	}

	for (int i = 0; i < K; i++){
		int r, c, s;
		cin >> r >> c >> s;
		vec.push_back({ r, c, s });
	}

	dfs(0);


	cout << ans;

	return 0;
}