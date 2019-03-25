#include <cstdio>
#include <string>
#include <iostream>
#include <algorithm>
#include <map>
using namespace std;

int n,m,cnt=0;
string s;

main(){
	scanf("%d%d",&n,&m);
	
	map<string, int> mp;
	
	for(int i=0;i<n;i++){
		cin>>s;
		mp[s]=1;
	}
	
	for(int i=0;i<m;i++){
		cin>>s;
		if(mp.find(s)!=mp.end()){
			cnt++;mp[s]++;
		}
	}
	
	printf("%d\n",cnt);
	map<string,int>::iterator it =mp.begin();
	while(it!=mp.end()){
		if(it->second==2)cout<<it->first<<'\n';
		it++;
	}
	
}
