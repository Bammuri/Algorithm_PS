#include <cstdio>
#define min(a,b) (((a)<(b))?(a):(b))

main(){
	int b1,b2,b3,mb,c1,c2;
	scanf("%d%d%d",&b1,&b2,&b3);
	scanf("%d%d",&c1,&c2);
	printf("%d",min(b3,min(b1,b2))+min(c1,c2)-50);
}
