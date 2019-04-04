#include <cstdio>
int n,plu,mus,mul,div;
int num[11];
int max=-1987654321;
int min=1987654321;

void dfs(int now,int sum){
	
	if(plu>0){
		plu--;
		dfs(now+1,sum+num[now]);
		plu++;	
	}
	if(mus>0){
		mus--;
		dfs(now+1,sum-num[now]);
		mus++;
	}
	if(mul>0){
		mul--;
		dfs(now+1,sum*num[now]);
		mul++;
	}
	if(div>0){
		div--;
		dfs(now+1,sum/num[now]);
		div++;
	}
	if(now==n){
	max<sum?max=sum:max;
	min>sum?min=sum:min;}
}

main(){
	scanf("%d",&n);
	for(int i=0;i<n;i++)
		scanf("%d",&num[i]);
	scanf("%d %d %d %d",&plu,&mus,&mul,&div);	
	
	dfs(1,num[0]);
	
	printf("%d\n%d",max,min);
	
}
