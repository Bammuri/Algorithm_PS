#include <cstdio>
#include <vector>
using namespace std;
int topni[1000][8];
int turn[1000];
int t;

void turn_c(int a){
	int tmp=topni[a][0];
	for(int j=7;j>0;j--)topni[a][(j+1)%8]=topni[a][j];
	topni[a][1]=tmp;
}

void turn_cw(int a){
	int tmp=topni[a][0];
	for(int j=0;j<7;j++)topni[a][j]=topni[a][j+1];
	topni[a][7]=tmp;
}

void move(int a,int b){
	turn[a-1]=b;
	for(int i=a-1;i+1<t;i++){
		if((topni[i][2]!=topni[i+1][6])&&turn[i]==1)turn[i+1]=-1;
		else if((topni[i][2]!=topni[i+1][6])&&turn[i]==-1)turn[i+1]=1;
		//printf("\n> %d %d %d %d %d\n",i,topni[i][2],topni[i+1][6],turn[i],turn[i+1]);
	}
	
	for(int i=a-1;i-1>=0;i--){
		
		if((topni[i][6]!=topni[i-1][2])&&turn[i]==1)turn[i-1]=-1;
		else if((topni[i][6]!=topni[i-1][2])&&turn[i]==-1)turn[i-1]=1;
		//printf("\n< %d %d %d %d %d\n",i,topni[i][2],topni[i+1][6],turn[i],turn[i-1]);
	}
	
	for(int i=0;i<t;i++){
		if(turn[i]==-1)turn_cw(i);
		else if(turn[i]==1)turn_c(i);
	}
}

main(){
	scanf("%d",&t);	
	for(int i=0;i<t;i++)
		for(int j=0;j<8;j++)
			scanf("%1d",&topni[i][j]);
	int k,a,b;
	scanf("%d",&k);
	for(int i=0;i<k;i++){
		for(int i=0;i<t;i++)turn[i]=0;
		scanf("%d %d",&a,&b);
		move(a,b);
		/*for(int i=0;i<t;i++){
		for(int j=0;j<8;j++){
			printf("%d",topni[i][j]);
		}
		printf("\n"); 
		}*/
	}
	int ans=0;
	for(int i=0;i<t;i++)ans+=topni[i][0];
	printf("%d\n",ans);
	
	//for(int i=0;i<t;i++)printf("%d",turn[i]);
	
	
}
