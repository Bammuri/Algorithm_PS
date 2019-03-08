#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h>
using namespace std;

int main(){
	int N,K;
	cin>>N>>K; 
	vector <int> coin(N,9999);
	int DP[10001];
	memset(DP, -1, 10001 );
	
	for(int i=0;i<coin.size();i++){
		int n;
		cin>>n;
		coin[i]=n;
	}
	DP[0]=0;

	sort(coin.begin(),coin.end(),greater <int>());
	
	for(int i=0;i<K+1;i++){
		for(int j=0;j<coin.size();j++){
			
			
				int tmp=DP[i+1-coin[j]]+1;
				if(DP[i+1]>tmp||DP[i+1]==-1)DP[i+1]=tmp;
	
		
		}
	}
	for(int i=1;i<K+1;i++)cout<<DP[i]<<" ";
	//cout<<DP[K];
	return 0;
}
