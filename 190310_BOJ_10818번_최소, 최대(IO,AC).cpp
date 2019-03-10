#include <cstdio>
#define MIN(x,y) ((x)<(y)?(x):(y)) 
#define MAX(x,y) ((x)>(y)?(x):(y)) 
int main(){
	int N,min=1000000,max=-1000000,num;
	scanf("%d",&N);
	for(int i=0;i<N;i++){
	scanf("%d",&num);
	max=MAX(max,num);
	min=MIN(min,num);
	}
	printf("%d %d",min,max);
} 
