#include<cstdio>

using namespace std;

int coins[101];
int dp[10001];

int main(){
	int n,k;
	scanf("%d %d",&n,&k);
	for(int i=0;i<=k;i++){
		dp[i]=0x7ffffff;
	}
	for(int i=1;i<=n;i++){
	scanf("%d",&coins[i]);
	dp[coins[i]]=1;
	}
	for(int i=0;i<n;i++){
		for(int j=coins[i+1];j<=k;j++){
			if(dp[j]>dp[j-coins[i+1]]+1)dp[j]=dp[j-coins[i+1]]+1;
		}
	}

	printf("%d",dp[k]==0x7ffffff?-1:dp[k]);
	
}
