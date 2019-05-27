//0ms 수행시간을 줄이는 i*i!! 
#include <cstdio>
int N;
main(){
	scanf("%d",&N);
	for(int i=2;i*i<=N;i++){
		if(N%i==0){
		printf("%d\n",i);
		N/=i--;
		}
	}
    if(N>1)printf("%d",N);
}
//28ms
/*
#include <cstdio>
int N;
main(){
	scanf("%d",&N);
	for(int i=2;i<=N;i++){
		if(N%i==0){
		printf("%d\n",i);
		N/=i--;
		}
	}
}*/
