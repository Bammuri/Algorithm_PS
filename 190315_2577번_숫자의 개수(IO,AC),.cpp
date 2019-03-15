#include <cstdio>
#include <stdlib.h>
main(){
	int a,b,c;
	scanf("%d%d%d",&a,&b,&c);
	int ans=a*b*c;

	for(int i=0;i<10;i++){
		int tmp=ans;
		int count=0;
		bool flag=true;
		do{
			if(tmp<10)flag=false;
			if(tmp%10==i)count++;
			tmp/=10;
		}while(flag);
		printf("%d\n",count);		
	}
}
