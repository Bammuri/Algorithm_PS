#include <iostream>
#include <algorithm>

using namespace std;
short num[10001]={0,};

int main(){
	int n;
	cin>>n;
	
	for(int i=0;i<n;i++){
		int tmp;
		scanf("%d",&tmp);
		num[tmp]++;
	} 
	for(int i=1;i<10001;i++){
		int cnt=num[i];
		while(cnt>0){
			printf("%d\n",i);
			cnt--;
		}
	}    
    return 0;
}
