#include <iostream>
#include <algorithm>
#include <vector>
using namespace std; 

int main(){
	int T;
	cin >>T;
	vector <int> ans;
	for(int k=0;k<T;k++){
		int n;
		cin >>n;
		vector <int> a(n+1,0);
		vector <int> b(n+1,0);

		
		for(int i=0;i<n;i++){
			int tmp;
			cin >>tmp;
			a[i]=tmp;
		}
		
		for(int i=0;i<n;i++){
			int tmp;
			cin >>tmp;
			b[i]=tmp;
		}
		
		
		if(n>=3){

			for(int i=2;i<n;i+=2){
			a[i]=max(a[i]+b[i-2],a[i]+a[i-2]+b[i-1]);	
			b[i]=max(b[i]+a[i-2],b[i]+b[i-2]+a[i-1]);
			}
		
			if(n%2==0)
				cout<<max(a[n-2]+b[n-1],b[n-2]+a[n-1])<<'\n';
			else
				cout<<max(a[n-1],b[n-1])<<'\n';
				
		}
		else
			cout<<max(a[0]+b[1],b[0]+a[1])<<'\n';
		
	}
	
	return 0;
}
