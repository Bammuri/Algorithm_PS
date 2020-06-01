//1434 TC AC val 인덱스 오류
//1455 sAC q 처음들어가는 vist 표시문제
#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
using namespace std;

int N;
vector <int> adj[11];
int val[11];
int visit[11];
int ans = 1e9;

bool is_right()
{

	int check[11] = { 0, };
	queue <int> qr,qb;


	for (int i = 1; i <= N; i++){

		if (qr.empty() && visit[i])qr.push(i);
		if (qb.empty() && !visit[i])qb.push(i);
	}

	while (!qr.empty())
	{
		int cur = qr.front();
		qr.pop();
		check[cur] = 1;
		for (int i = 0; i < adj[cur].size(); i++){
			
			int nxt = adj[cur][i];
			if (!visit[nxt] || check[nxt]) continue;
			check[nxt] = 1;
			qr.push(nxt);
		}
	}

	while (!qb.empty())
	{
		int cur = qb.front();
		qb.pop();
		check[cur] = 1;
		for (int i = 0; i < adj[cur].size(); i++){

			int nxt = adj[cur][i];
			if (visit[nxt] || check[nxt]) continue;
			check[nxt] = 1;
			qb.push(nxt);
		}
	}


	for (int i = 1; i <= N; i++){

		if (!check[i]) return false;
	}
	return true;

}

void print_visit()
{
	for (int i = 1; i <= N; i++){

		cout << visit[i];
		
	}
	cout << "\n";
}

void sol(int d,int s){

	if (d == N) return;
	if (d > 0 && d < N)
	{
		//print_visit();
		if (is_right())
		{
			int r_sum = 0, b_sum = 0;
			for (int i = 1; i <= N; i++)
			{
				if (visit[i])r_sum += val[i];
				else b_sum += val[i];
			}
			if (ans > abs(r_sum - b_sum)){
				//print_visit();
				ans = abs(r_sum - b_sum);
			}
		}

	}


	for (int i = s; i <= N; i++){

		if (visit[i]) continue;
		visit[i] = 1;
		sol(d+1, i);
		visit[i] = 0;
	}

}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N;

	for (int i = 1; i <= N; i++)
		cin >> val[i];

	for (int i = 1; i <= N; i++)
	{
		int t;
		cin >> t;
		while (t--)
		{
			int n;
			cin >> n;
			adj[i].push_back(n);
		}
	}

	sol(0,1);

	if (ans == 1e9)
		cout << "-1";
	else
		cout << ans;
	return 0;
}