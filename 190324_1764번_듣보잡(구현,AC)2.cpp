#include <bits/stdc++.h>
using namespace std;

int n,m,cnt=0,i;
vector <string> ns,ans;
string k;

main(){
	ios::sync_with_stdio(0);

	cin>>n>>m;
	for(ns.resize(n);i<n;cin>>ns[i++]);
	sort(ns.begin(),ns.end());
	
	for(;cin>>k;)
		if(binary_search(ns.begin(),ns.end(),k))ans.push_back(k);
	sort(ans.begin(),ans.end());
	
	cout<<ans.size()<<'\n';
	vector<string>::iterator it;
	for(it=ans.begin();it!=ans.end();it++) cout<<*it<<'\n';
	
}
