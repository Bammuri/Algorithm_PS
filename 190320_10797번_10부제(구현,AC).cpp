#include <cstdio>
main(){
	int a,count=0;
	scanf("%d",&a);
	for(int i=0;i<5;i++){
		int b;
		scanf("%d",&b);
		if(a==b)count++;
	}
	printf("%d",count);
} 
