//1615 시작
//1659 tc 2개 맞음
//1505 idx%9후 tc 4개 맞음
//1558 갑자기 맞음;;;
//이닝끝나고 stat을 셋팅해주는 것 뺴먹음
#include <iostream>
#include <cstring>
using namespace std;
#define FOR(i,n) for(int i=0;i<n;++i)

int n,max1=0;
int act[50][9];
int order[9] = { 0, };//들어있는 값은 선수의 번호
int visit[9];
int stat[3];

void go(){
	int ining = 0,idx=0,tmp=0;
	memset(stat, 0, sizeof(stat));
	while (ining!=n){
		int outstat = 0;
		memset(stat, 0, sizeof(stat));
		while (outstat != 3){
			switch (act[ining][order[idx]]){
			case 0:
				outstat++;
				break;
			case 1:
				if (stat[2] == 1)tmp++;
				stat[2] = stat[1];
				stat[1] = stat[0];
				stat[0] = 1;

				break;
			case 2:
				if (stat[2] == 1)tmp++;
				if (stat[1] == 1)tmp++;
				stat[2] = stat[0];
				stat[1] = 1;
				stat[0] = 0;

				break;
			case 3:
				if (stat[2] == 1)tmp++;
				if (stat[1] == 1)tmp++;
				if (stat[0] == 1)tmp++;
				stat[2] = 1;
				stat[1] = 0;
				stat[0] = 0;
				break;
			case 4:
				if (stat[2] == 1)tmp++;
				if (stat[1] == 1)tmp++;
				if (stat[0] == 1)tmp++;
				tmp++;
				stat[2] = 0;
				stat[1] = 0;
				stat[0] = 0;

				break;
			}
			idx++;
			idx%=9;
		}
		ining++;
	}

	if (max1 < tmp) max1 = tmp;

}



void dfs(int depth){
	if (depth == 9){
		go();
		return;
	}
	if (depth == 3){//4번재 인덱스 3은 무조건 1번타자 고정
		order[depth] = 0;
		dfs(depth + 1);
	}
	for (int i = 1; i < 9; i++){
		if (visit[i])continue;
		visit[i] = 1;
		order[depth] = i;
		dfs(depth + 1);
		visit[i] = 0;
	}
		

}

void solve(){
	for (int i = 1; i < 9;i++){
		order[0] = i;
		visit[i] = 1;
		dfs(1);
		visit[i] = 0;
	}
	
	cout << max1;
}


int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;

	FOR(i, n){
		FOR(j, 9)
			cin >> act[i][j];
	}

	solve();

	return 0;

}