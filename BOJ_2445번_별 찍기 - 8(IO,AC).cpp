// 1 2 3 4 5 4 3 2 1
//8 6 4 2 0 2 4 6 8

#include <cstdio>
int main(){
	int n;
	scanf("%d",&n);
	int a=1,b=2*n-2;
	for(int i=0;i<n;i++){
		for(int j=0;j<a;j++)printf("*");
		for(int k=0;k<b;k++)printf(" ");
		for(int j=0;j<a;j++)printf("*");
		a++;b-=2;printf("\n");
	}
	a--;b+=2;a--;b+=2;
	for(int i=0;i<n-1;i++){
		for(int j=0;j<a;j++)printf("*");
		for(int k=0;k<b;k++)printf(" ");
		for(int j=0;j<a;j++)printf("*");
		a--;b+=2;printf("\n");
	}
}
