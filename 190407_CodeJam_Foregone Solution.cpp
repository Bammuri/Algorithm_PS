#include <iostream>
#include <string>
using namespace std;
int z,t;
string n;

main(){
cin>>t;
for(z=0;z<t;z++){
    cin>>n;
   
    string a,b;
    
    for(int i=0;i<n.size();i++){
    
    	if(n[i]==52){
    		a+=50,b+=50;
    	}
    	else{
    		
    		a+=n[i],b+=48;
    	}
    }
    int ta=stoi(a),tb=stoi(b);
   cout<<"case #"<<z+1<<": "<<ta<<" "<<tb<<"\n";
   }


}
