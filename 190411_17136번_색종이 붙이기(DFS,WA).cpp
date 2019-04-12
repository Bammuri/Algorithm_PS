#include <cstdio>
#include <vector>
using namespace std;
int paper[10][10];
int ans=100,pa_count[6];

void print_map(){
	printf("\n");
	for(int i=0;i<10;i++){
	for(int j=0;j<10;j++)
		printf("%d ",paper[i][j]);
	printf("\n");}
	printf("%d\n",ans);
}

void copy_paper(int (*a)[10],int (*b)[10]){
	for(int i=0;i<10;i++)
	for(int j=0;j<10;j++)
		a[i][j]=b[i][j];
}

bool can(int k,int i,int j){
	
	for(int a=i;a<i+k;a++)
		for(int b=j;b<j+k;b++)
			if(a>10||a<0||b>10||b<0||paper[a][b]!=1)return false;

	return true;
}

void dfs(int tmpans){
	
	int tp[10][10];
	copy_paper(tp,paper);
	for(int i=0;i<10;i++)
		for(int j=0;j<10;j++)
			if(paper[i][j]==1){
				for(int k=5;k>0;k--){
					if(ans<tmpans)return;
					if(pa_count[k]==5||i+k>=10||j+k>=10)continue;
					if(can(k,i,j)){
						for(int a=i;a<a+k;a++)
							for(int b=j;b<b+k;b++)paper[a][b]=k+1;
								pa_count[k]++;
								dfs(tmpans+1);
								pa_count[k]--;
								copy_paper(paper,tp);
					}		
				}
				return;	
			}
	
	if(ans>tmpans)ans=tmpans;
	//print_map();
	//printf("%d\n",tmpans);
}

main(){
	for(int i=0;i<10;i++)
	for(int j=0;j<10;j++)
		scanf("%d",&paper[i][j]);
	dfs(0);
	printf("%d",ans==100?-1:ans);
}
