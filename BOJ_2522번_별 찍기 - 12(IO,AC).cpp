// 2 1 0 1 2
// 1 2 3 2 1
#include <cstdio>
int main(){
	int n;
	scanf("%d",&n);
	int a=n-1,b=1;
	for(int i=0;i<n;i++){
		for(int k=0;k<a;k++)printf(" ");
		for(int j=0;j<b;j++)printf("*");
		a--;b++;printf("\n");
	}
	a++;b--;a++;b--;
	for(int i=0;i<n-1;i++){
		for(int k=0;k<a;k++)printf(" ");
		for(int j=0;j<b;j++)printf("*");
		a++;b--;printf("\n");
	}
}
