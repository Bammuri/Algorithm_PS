#include <iostream>
#include <algorithm>
using namespace std;
int n,m,num[8],ans[8],check[8];
// 1 7 9 9
void dfs(int depth,int before){
	if(depth==m){
		for(int i=0;i<m;i++)
			cout<<ans[i]<<" ";
		cout<<"\n";
		return;
	}
	
	int ncheck[10001]={0,};//항상 초기화 해주자!!! 
	for(int i=0;i<n;i++){
		if(check[i]||ncheck[num[i]])continue;
		check[i]=1;ncheck[num[i]]=1;
		ans[depth]=num[i];
		dfs(depth+1,i);
		check[i]=0;
	}
}

main(){
	ios::sync_with_stdio(0);
	cout.tie();
	cin>>n>>m;
	for(int i=0;i<n;i++)
		cin>>num[i];
		
	sort(num,num+n);
	
	dfs(0,-1);
}
