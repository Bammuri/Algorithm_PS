#include <cstdio>
bool check[1001];

main(){
	int n,k,count=1;
	scanf("%d%d",&n,&k);
	for(int i=2;i<=n;i++){
		if(check[i])continue;
		for(int j=i;j<=n;j+=i){
			if(check[j]) continue;s
			if(count++==k)printf("%d ",j);
			check[j]=true;
		}
	}
} 
