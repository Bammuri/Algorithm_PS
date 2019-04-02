#include <cstdio>
int sk[20][20];
int n,ans=1e9;
int team[20];//1 ¸µÅ©ÆÀ 2 ½ºÅ¸Æ®ÆÀ 


int min(int a,int b){return (a>b)?b:a;}

void dfs(int now){
	if(now==n){
		int asum=0,bsum=0;
		int an=0,bn=0;
		int at[20],bt[20];
		for(int i=0;i<n;i++){
			if(team[i]==1)at[an++]=i;
			else bt[bn++]=i;
		} 
		
		if(an==0||bn==0)return;
		
		for(int i=0;i<an;i++){
			for(int j=i+1;j<an;j++){
				int a=at[i];int b=at[j];
				asum=asum+sk[a][b]+sk[b][a];
			
			}
		}
		for(int i=0;i<bn;i++){
			for(int j=i+1;j<bn;j++){
				int c=bt[i];int d=bt[j];
				bsum=bsum+sk[c][d]+sk[d][c];
			}
		}
		
		int tmp=asum-bsum;
		if(tmp<0)tmp*=-1;

		ans=min(ans,tmp);
		return;
	}
	
		team[now]=1;
		dfs(now+1);
	
		team[now]=2;
		dfs(now+1);

	
}

main(){
	scanf("%d",&n);
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
			scanf("%d",&sk[i][j]);
	
	dfs(0);
	printf("%d",ans);
}
