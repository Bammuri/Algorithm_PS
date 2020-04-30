#include <cstdio>
#include <iostream>
#include <vector>
#define ABS(n) (((n)>0)?(n):(-(n)))

using namespace std;

int sk[21][21];
int n, ans = 1987654321;
int team[21];// 0 ½ºÅ¸Æ®ÆÀ 1 ¸µÅ©ÆÀ 

int min(int a, int b){ return (a<b) ? a : b; }


void dfs(int now, int t1, int t2){

	if (now == n + 1){
		if (t1 != t2)return;
		int sum1 = 0, sum2 = 0;
		vector <int> a1, a2;
		for (int i = 1; i < n+1; i++){
			if (team[i])
				a1.push_back(i);
			else 
				a2.push_back(i);
		}
		for (int i = 0; i<a1.size(); i++){
			for (int j = i + 1; j<a1.size(); j++){
				int a = a1[i];
				int b = a1[j];
				sum1 = sum1 + sk[a][b] + sk[b][a];
			}
		}
		for (int i = 0; i<a2.size(); i++){
			for (int j = i + 1; j<a2.size(); j++){
				int a = a2[i];
				int b = a2[j];
				sum2 = sum2 + sk[a][b] + sk[b][a];
			}
		}
		ans = min(ans, ABS(sum1 - sum2));
		return;
	}

	team[now] = 0;
	dfs(now + 1, t1 + 1, t2);
	team[now] = 1;
	dfs(now + 1, t1, t2 + 1);

}


int main(){
	scanf_s("%d", &n);
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			scanf_s("%d", &sk[i][j]);


	dfs(1, 0, 0);

	printf("%d", ans);
}