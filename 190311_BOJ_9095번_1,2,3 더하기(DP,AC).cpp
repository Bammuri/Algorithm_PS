#include <cstdio>
int dp[99999];
int main(){
	int n,T;
	scanf("%d",&T);
	for(int k=0;k<T;k++){
	scanf("%d",&n);
	dp[1]=1;dp[2]=2;dp[3]=4;
	for(int i=4;i<=n;i++)dp[i]=dp[i-1]+dp[i-2]+dp[i-3];
	printf("%d",dp[n]);
	}
}
