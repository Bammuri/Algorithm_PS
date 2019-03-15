#include <cstdio>
int num[10001],num2[10001];
main(){
	int n,x,index=0;
	scanf("%d%d",&n,&x);
	for(int i=0;i<n;i++){
		scanf("%d",&num[i]);
		if(x>num[i])num2[index++]=num[i];
	}
	for(int i=0;i<index;i++)printf("%d ",num2[i]);
} 
