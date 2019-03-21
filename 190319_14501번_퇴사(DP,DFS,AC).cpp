#include <cstdio>
#include <algorithm>
int d[16];
int t[16];
int p[16];
int n;
int ans;

int dp(int day){
	if(day==n+1) return 0;
	if(day>n+1) return -1987654321;
	if(d[day]>0) return d[day];
	return d[day]=std::max(dp(day+1),dp(day+t[day])+p[day]);
}

void dfs(int day, int sum){
	if(day==n+1){
		ans=std::max(ans,sum);
		return;
	}
	dfs(day+1,sum);
	if(day+t[day]<=n+1)
		dfs(day+t[day],sum+p[day]);
}


main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d%d",&t[i],&p[i]);
	printf("%d ",dp(1));
	//dfs(1,0);
	printf("%d",ans);
}
