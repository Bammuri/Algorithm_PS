#include <cstdio>

main(){
	int n,c1=0,c0=0,z;
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%d",&z);
		if(z==1)c1++;
		else c0++;
	}
	c1>c0?printf("Junhee is cute!"):printf("Junhee is not cute!");
}
