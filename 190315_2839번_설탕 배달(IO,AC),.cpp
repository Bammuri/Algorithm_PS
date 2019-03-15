#include <cstdio>
int dp[5001];
main(){
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)dp[i]=0x3ffffff;
	dp[3]=1;dp[5]=1;
	for(int i=6;i<=n;i++)dp[i]>dp[i-3]+1?dp[i]=dp[i-3]+1:dp[i];
	for(int i=6;i<=n;i++)dp[i]>dp[i-5]+1?dp[i]=dp[i-5]+1:dp[i];
	printf("%d",dp[n]==0x3ffffff?-1:dp[n]);
}
