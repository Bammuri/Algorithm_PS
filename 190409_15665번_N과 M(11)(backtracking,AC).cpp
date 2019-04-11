#include <iostream>
#include <algorithm>
using namespace std;
int n,m,num[7],ans[7];

void dfs(int depth){
	if(depth==m){
		for(int i=0;i<m;i++)
			cout<<ans[i]<<" ";
		cout<<"\n";
		return;
	}
	
	int check[10001]={0,};
	for(int i=0;i<n;i++){
		if(check[num[i]])continue;
		check[num[i]]=1;
		ans[depth]=num[i];
		dfs(depth+1);
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
