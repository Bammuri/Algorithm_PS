// 3 2 1 0
//0 1 3
#include <cstdio>
main(){
	int n;
	scanf("%d",&n);
	int a=n-1,b=-1;
	for(int i=0;i<n;i++){
		if(i==n-1){for(int k=0;k<2*n-1;k++)printf("*");}
		else{
		for(int j=0;j<a;j++)printf(" ");
		if(i!=0)printf("*");
		for(int k=0;k<b;k++)printf(" ");
		printf("*\n");
		a--;b+=2;
		}
	}	
}
