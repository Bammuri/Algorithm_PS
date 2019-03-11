#include <cstdio>
int dp[1001];
int main(){
	int n;
	scanf("%d",&n);
	dp[1]=1;dp[2]=3;
	for(int i=3;i<=n;i++){
	if(i%2==0)dp[i]=(2*dp[i-1]+1)%10007;
	else dp[i]=(2*dp[i-1]-1)%10007;
	}
	printf("%d",dp[n]);
}
