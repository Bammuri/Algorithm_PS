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
		vector <int> ansa(n+1,0);
		vector <int> ansb(n+1,0);
		
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
		
		if(n==1)
			cout<<max(a[0],b[0])<<'\n';
		else if(n==2)
			cout<<max(a[0]+b[1],b[0]+a[1])<<'\n';
		else{
			
			ansa[0]=a[0]; ansb[0]=b[0];
			ansa[1]=b[0]+a[1]; ansb[1]=a[0]+b[1];
						
			for(int i=2;i<n;i++){
			ansa[i]=max(a[i]+ansb[i-1],a[i]+ansb[i-2]);	
			ansb[i]=max(b[i]+ansa[i-1],b[i]+ansa[i-2]);
			}
			
			cout<<max(ansa[n-1],ansb[n-1])<<'\n';
		}
	
	}
	
	return 0;
}
