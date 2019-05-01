#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
int n,rope[100000],ans;

bool cmp(int a,int b){
	return a>b;
}

main(){
	scanf("%d",&n);
	
	for(int i=0;i<n;i++)
		scanf("%d",&rope[i]);
	
	sort(rope,rope+n,cmp);
	
	for(int i=0;i<n;i++){
		if(ans<rope[i]*(i+1))ans=rope[i]*(i+1);
	}
	
	printf("%d",ans);
}

