#include <cstdio>
int n,k,coin[11],ans;
main(){
	scanf("%d %d",&n,&k);
	for(int i=0;i<n;i++){
		scanf("%d",&coin[i]);
	}
	for(int i=n-1;i>=0;i--){
		ans+=k/coin[i];
		k%=coin[i];
	}
	printf("%d",ans);
}
