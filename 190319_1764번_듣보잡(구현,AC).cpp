#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
using namespace std;
int n,m,cnt=0;
vector <string> nhs;

main(){
	ios::sync_with_stdio(0);

	cin>>n>>m;
	nhs.resize(n+m);
	for(int i=0;i<n+m;i++)cin>>nhs[i];
		
	sort(nhs.begin(),nhs.end());
	for(int i=1;i<n+m;i++)
		if(nhs[i]==nhs[i-1])
				cnt++;	
	cout<<cnt<<'\n';
			
	for(int i=1;i<n+m;i++)
		if(nhs[i]==nhs[i-1])
			cout<<nhs[i]<<'\n';
	
}
