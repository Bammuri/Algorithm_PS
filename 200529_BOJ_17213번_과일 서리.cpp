#include <iostream>
using namespace std;

long long N, M, ans = 1, tmp = 1;


void dfs(int d,int s)
{
	if (d == M - N){

		ans++;
		//cout << "\n";
		return;
	}


	for (int i = s; i < N; i++){
		//cout << i << " ";
		dfs(d + 1, i);
	}
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> N >> M;
	long long n = N, m = M; 
	while (--n){
		cout << n << " " << m << "\n";
		ans *= (--m);
		tmp *= n;
	}
	cout << ans << " " << tmp << "\n";
	cout << ans / tmp<<"\n";
	ans = 1;
	dfs(0,0);
	cout << ans - 1;
	return 0;
}
