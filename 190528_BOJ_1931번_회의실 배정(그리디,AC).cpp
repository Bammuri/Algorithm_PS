#include <iostream>
#include <algorithm>
#include <utility>
using namespace std;
pair <int,int> semi[100000];
int n,f,s,ans=1;

void print(){
	for(int i=0;i<n;i++){
		cout<<semi[i].first<<" "<<semi[i].second<<"\n";
	}
}
void solve(){
	int sts=semi[0].second;
	
	for(int i=1;i<n;i++){
		int canf=semi[i].first,cans=semi[i].second;
		if(sts<=canf){
				sts=cans;
				ans++;
			}
			
	//cout<< "\n"<<" "<<sts<<"\n";
	}
	
	cout<<ans;
}
main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>f>>s;
		semi[i]={s,f};
	}
	sort(semi,semi+n,comp);
	//print();
	solve();
	
}
