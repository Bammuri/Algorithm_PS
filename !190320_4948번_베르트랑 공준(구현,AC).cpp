#include <cstdio>
const int MAX_NUM=123456;
bool isnotprime[2*MAX_NUM+1];

void getprime(){
	
	isnotprime[0]=isnotprime[1]=true;
	
	for(int i=2;i<=MAX_NUM*2;i++){
		if(isnotprime[i]) continue;
	
		for(int j=i*2;j<=MAX_NUM*2;j+=i) isnotprime[j]=true;
	}
} 

main(){
	getprime();
	int a;
	scanf("%d",&a);
	while(a!=0){
		int ans=0;
		for(int i=a+1;i<=2*a;i++){
			if(isnotprime[i])continue;
			ans++;
		}

		printf("%d\n",ans);
		scanf("%d",&a);
	}
	
}
