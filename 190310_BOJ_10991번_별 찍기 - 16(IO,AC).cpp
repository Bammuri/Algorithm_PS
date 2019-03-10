//3 2 1 0
//0 1 2 3
#include <cstdio>
main(){
	int n;
	scanf("%d",&n);
	int a=n-1,b=0;
	for(int k=0;k<n;k++){
		for(int i=0;i<a;i++)printf(" ");
		for(int j=0;j<b;j++)printf("* ");
		printf("*");
		printf("\n");a--;b++;
	}
}
