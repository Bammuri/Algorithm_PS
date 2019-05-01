#include <cstdio>
int n,rope[10001],ans,t,cnt=0;
main(){
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%d",&t);
		rope[t]++;
	}
	for(int i=10000;i>0;i--){
		cnt+=rope[i];
		if(rope[i])ans<i*cnt?ans=i*cnt:ans;
	}
	printf("%d",ans);
}

