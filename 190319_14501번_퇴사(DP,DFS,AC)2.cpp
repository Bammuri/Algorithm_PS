#include <cstdio>
#include <algorithm>
int t[16];//상담기간 
int p[16];//상담금액 
int n,dpa[16];
int ans=0;
int dp(int day){
	if(day==n+1)return 0;
	if(day>n+1)return -1987654321;
	if(dpa[day]>0)return dpa[day];
	return dpa[day]=std::max(dp(day+1),dp(day+t[day])+p[day]);
}

void dfs(int day,int sum){
	if(day==n+1){
		ans=std::max(sum,ans);
		return;
	}
	dfs(day+1,sum);
	if(day+t[day]<n+1)
		dfs(day+t[day],sum+p[day]);
}

main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d%d",&t[i],&p[i]);
	printf("%d",dp(1)); 
	//dfs(1,0);
	//printf("%d",ans);
}
