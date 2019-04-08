#include <iostream>
#include <vector>
using namespace std;
int n,m,k=0;
int check[9];
vector <int> ans(8,0);
void dfs(int index,int depth){

	if(depth==m){
		for(int i=0;ans[i]!=0;i++)
			cout<<ans[i]<<" ";
		cout<<"\n";
		return;
	}
	
	for(int i=index+1;i<n+1;i++){
		if(check[i])continue;
		check[i]=1;
		ans[depth]=i;
		dfs(i,depth+1);
		check[i]=0;
	}
}

main(){
	ios::sync_with_stdio(0);
	cout.tie(NULL);
	cin>>n>>m;
	dfs(0,0);
}
