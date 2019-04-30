#include <cstdio>
int num[20]={1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20};
int a,b;

void swap(int *a,int *b){
	int tmp=*a;
	*a=*b;
	*b=tmp;
}
main(){
	
	for(int i=0;i<10;i++){
		scanf("%d%d",&a,&b);
		int n=b-a+1;
		if(n%2==1)n+=1;
		n=n/2;
		for(int k=0;k<n;k++){
			swap(&num[a-1+k],&num[b-1-k]);
		}
	}
	for(int i=0;i<20;i++)printf("%d ",num[i]);
}
