//190202_Baekjoon_수 정렬하기  insertion sort

#include <iostream>
using namespace std;

int main(){
	int n;
	cin>>n;
	int num[n];
	for(int i=0;i<n;i++){
		cin>>num[n];		
	} 
	
	sort(num,num+n);
	
	for(int i=0;i<n;i++){
		printf("%d",num[i]);
	}    
    return 0;
}
