#include <iostream>
#include <algorithm>
using namespace std;
int n,m,num[8],ans[10];

void dfs(int depth){
	if(depth==m){
		for(int i=0;i<m;i++)
			cout<<ans[i]<<" ";
		cout<<"\n";return;
	}
	
	for(int i=0;i<n;i++){
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
