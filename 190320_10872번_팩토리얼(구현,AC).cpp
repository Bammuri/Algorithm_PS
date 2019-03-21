#include <cstdio>
main(){
	int a,sum=1;
	scanf("%d",&a);
	for(int i=1;i<=a;i++)sum*=i;
	printf("%d",sum);
} 
