#include <cstdio>

main(){
	int t;
	scanf("%d",&t);
	for(int i=0;i<t;i++){
		int r;char str[21];
		scanf("%d",&r);
		scanf("%s",&str);
		for(int a=0;str[a]!=NULL;a++){
			for(int j=0;j<r;j++)printf("%c",str[a]);
		}	
		printf("\n");
	}
}
