#include <iostream>
using namespace std;
int t;
main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>t;
	if(t%10!=0)cout<<-1;
	else cout<<t/300<<" "<<t%300/60<<" "<<t%60/10;
}
