#include <iostream>
#include <algorithm>
using namespace std;
int n,m,t,ans[8],num[8];

void dfs(int now ,int depth){
	if(depth==m){
		for(int i=0;i<m;i++)
			cout<<ans[i]<<" ";
		cout<<"\n";
		return;
	}
	int check2[10001]={0,};
	for(int i=now;i<n;i++){
		if(check2[num[i]])continue;
		check2[num[i]]=1;
		ans[depth]=num[i];
		dfs(i+1,depth+1);
	}
	
	
	
}
main(){
	ios::sync_with_stdio(0);
	cout.tie(NULL);
	cin>>n>>m;
	for(int i=0;i<n;i++)cin>>num[i];
	sort(num,num+n);
	dfs(0,0);
	
}
