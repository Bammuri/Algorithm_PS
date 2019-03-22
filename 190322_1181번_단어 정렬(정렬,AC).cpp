#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
string words[20001];
bool compare(string a,string b){
	if(a.size()==b.size()) return a<b;
	else return a.size()<b.size();
}

main(){
	ios_base::sync_with_stdio(false); cin.tie(0);
	int n;
	cin>>n;
	
	for(int i = 0; i < n; i++)cin>>words[i];
	sort(words,words+n,compare);
	
	for(int i=0;i<n;i++){
		if(i>0&&words[i]==words[i-1])continue;
		cout<<words[i]<<'\n';
	}
}
