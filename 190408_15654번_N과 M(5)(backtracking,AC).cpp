#include<iostream>
#include<algorithm>
using namespace std;
int num[8],check[8],n,m;
int ans[9]={0,0,0,0,0,0,0,0,0};

void dfs(int depth){
	if(depth==m){
		for(int i=0;ans[i]!=0;i++)
			cout<<ans[i]<<" ";
		cout<<"\n";
		return;
	}
	for(int i=0;i<n;i++){
		if(check[i])continue;
		check[i]=1;
		ans[depth]=num[i];
		dfs(depth+1);
		check[i]=0;
	}	
}
main(){
	ios::sync_with_stdio(false);
	cout.tie(NULL);
	cin>>n>>m;
	for(int i=0;i<n;i++)
		cin>>num[i];
	sort(num,num+n);
	dfs(0);
}
