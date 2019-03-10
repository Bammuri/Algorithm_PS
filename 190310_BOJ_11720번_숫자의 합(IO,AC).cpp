#include <cstdio>
int main(){
	int N,sum=0;
	char input[101];
	
	scanf("%d",&N); 
	scanf("%s",input);
	
	for(int i=0;i<N;i++){
		sum+=input[i]-48;
	}
	printf("%d",sum);
}
