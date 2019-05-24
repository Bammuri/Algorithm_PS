#include <iostream>
#include <string>
using namespace std;

string taebo;
int L=0,R=0,flag=0;
main(){
	
	cin>>taebo;
	for(int i=0;i<taebo.size();i++){
		if(taebo[i]=='@'&&!flag)L++;
		else if(taebo[i]=='^'&&!flag)flag=1;
		else if(taebo[i]=='@'&&flag)R++;
	}
	cout<<L<<" "<<R;
}
