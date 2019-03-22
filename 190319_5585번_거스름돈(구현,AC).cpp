#include <cstdio>
int c[6]={500,100,50,10,5,1},i;
main(){
	int money,ans=0;
	scanf("%d",&money);
	money=1000-money;
	while(i<6){
	
	if(money>=c[i]){
		ans=ans+(money/c[i]);
		money%=c[i];
	}
	i++;
	}
	printf("%d",ans);
}
