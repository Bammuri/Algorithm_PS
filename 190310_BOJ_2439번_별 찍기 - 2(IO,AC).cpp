#include <cstdio>
int main(){
	int N;
	scanf("%d",&N);
	int j=N;
	while(N--){
	for(int k=0;k<N;k++)printf(" ");
	for(int i=0;i<j-N;i++)printf("*");
	printf("\n");
	}
}
