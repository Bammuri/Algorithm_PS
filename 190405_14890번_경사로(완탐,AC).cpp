#include <cstdio>
#include <cmath> 
int n,L,ans=0,t1=0,t2=0;
int map[100][100];
main(){
	scanf("%d%d",&n,&L);
	for(int i=0;i<n;i++)
	for(int j=0;j<n;j++)
		scanf("%d",&map[i][j]);
		
	for(int i=0;i<n;i++){ 
		int cnt=1;//현재까지의 연속된 높이의 계단 수
		int f1=1;
		for(int j=0;j+1<n;j++){	
			if(map[i][j]==map[i][j+1])cnt++;
			else if(map[i][j]-map[i][j+1]==-1){if(cnt>=L)cnt=1;else f1=0;}
			else if(map[i][j]-map[i][j+1]==1){if(cnt<0)f1=0;else cnt=-(L-1);}
			else f1=0;		
		}	
		if(cnt>=0&&f1){/*printf("\n %d\n",i);*/t1++;}
	}
	for(int i=0;i<n;i++){ 
		int cnt=1;//현재까지의 연속된 높이의 계단 수
		int f2=1;
		for(int j=0;j+1<n;j++){
			if(map[j][i]==map[j+1][i])cnt++;
			else if(map[j][i]-map[j+1][i]==-1){if(cnt>=L)cnt=1;else f2=0;}
			else if(map[j][i]-map[j+1][i]==1){if(cnt<0)f2=0;else cnt=-(L-1);}
			else f2=0;		
		}
		if(cnt>=0&&f2){/*printf("\n %d\n",i);*/t2++;}
	
	}
	printf("%d",t1+t2);}
