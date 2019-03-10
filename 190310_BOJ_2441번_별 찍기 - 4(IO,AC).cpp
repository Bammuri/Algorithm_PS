#include <cstdio>
main(){
	int n;
	scanf("%d",&n);
	for(int i=n;i>0;i--){
		
		for(int j=i;n-j>0;j++)printf(" ");
		for(int k=0;k<i;k++)printf("*");
		printf("\n");
	}
}

