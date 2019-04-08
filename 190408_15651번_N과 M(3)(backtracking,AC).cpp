#include <iostream>
#include <vector>
using namespace std;
int n,m;

vector <int> ans(8,0);
void dfs(int depth){

	if(depth==m){
		for(int i=0;ans[i]!=0;i++)
			cout<<ans[i]<<" ";
		cout<<"\n";
		return;
	}
	for(int i=1;i<n+1;i++){
		ans[depth]=i;
		dfs(depth+1);
	
	}
}
main(){
	ios::sync_with_stdio(0);
	cout.tie(NULL);
	cin>>n>>m;
	dfs(0);
}
