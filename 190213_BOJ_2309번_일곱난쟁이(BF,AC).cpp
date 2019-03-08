#include <iostream>
#include <vector>
#include <algorithm> 
using namespace std;

int main(){
	vector <int> h;
	int sum=0;
	for(int i=0;i<9;i++){
		int ht;
		cin>>ht;
		sum+=ht;
		h.push_back(ht);
	}
	for(int i=0;i<h.size();i++){
		int j=i+1;
		for(j;j<h.size();j++ ){
			int mus=h[i]+h[j];
			if(sum-mus==100){
			cout<<h[i]<<" "<<h[j]<<"\n";
			h.erase(h.begin()+i);
			h.erase(h.begin()+j-1);
			}
		}	
		
	}
	sort(h.begin(),h.end());
	for(int i=0;i<h.size();i++){
		cout<<h[i]<<"\n";
	}
	return 0;
}
