#include <iostream>
#include <algorithm>
using namespace std;
int n,m;
int num[8],check[8],ans[9];

void dfs(int depth){
	if(depth==m){
		for(int i=0;ans[i+1]!=0;i++)if(ans[i]>ans[i+1])return;
		for(int i=0;ans[i]!=0;i++){
			cout<<ans[i]<<" ";
		}
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
	ios::sync_with_stdio(0);
	cout.tie(NULL);
	cin>>n>>m;
	for(int i=0;i<n;i++)
		cin>>num[i];

	sort(num,num+n);
	dfs(0);
}
