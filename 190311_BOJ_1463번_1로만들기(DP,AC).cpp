#include <cstdio>
int n,dp[1000001];
int main(){	
	scanf("%d",&n);
	for(int i=0;i<=n;i++)dp[i]=0x3ffffff;
	dp[1]=0;
	for(int i=2;i<=n;i++){
		if(i%2==0)dp[i]>dp[i/2]+1?dp[i]=dp[i/2]+1:dp[i];
		if(i%3==0)dp[i]>dp[i/3]+1?dp[i]=dp[i/3]+1:dp[i];
		dp[i]>dp[i-1]+1?dp[i]=dp[i-1]+1:dp[i];	
	}
	printf("%d",dp[n]);
}
