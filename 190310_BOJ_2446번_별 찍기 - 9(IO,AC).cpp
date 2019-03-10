//0 1 2 3 4 3 2 1 0
//9 7 5 3 1 3 5 7 9
#include <cstdio>
int main(){
	int N;
	scanf("%d",&N);
	int a=0,b=2*N-1;
	for(int k=0;k<N;k++){
		for(int i=0;i<a;i++)printf(" ");
		for(int j=0;j<b;j++)printf("*");
		printf("\n");a++;b-=2;
	}
	a--;b+=2;	a--;b+=2;
	for(int k=0;k<N-1;k++){
		for(int i=0;i<a;i++)printf(" ");
		for(int j=0;j<b;j++)printf("*");
		printf("\n");	
		a--;b+=2;
	}
}
