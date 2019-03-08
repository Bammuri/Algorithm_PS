#include <iostream>
#include <vector>
#include <limits.h>
using namespace std;

int main(){
	int num;
	cin>>num;
	vector <int> DP(num+1,0);
	DP[1]=0;
	DP[2]=1;
	DP[3]=1;
	for(int i=4;i<num+1;i++){
		int candid2=INT_MAX,candid3=INT_MAX;
		if(i%2==0)candid2=DP[i/2]+1;
		if(i%3==0)candid3=DP[i/3]+1;
		DP[i]=DP[i-1]+1;
		(candid2>=candid3?candid3:candid2)>=DP[i]?DP[i]:DP[i]=candid2>=candid3?candid3:candid2;

	}
	std::cout<<DP[num];
	return 0;
}
