#include <cstdio>
#include <cmath> 
int r,c,m,ans;
int fish[10000][5],check[10000];
int map[100][100];

void erase(int x){
	for(int i=0;i<m;i++)
		if(fish[i][4]==x)check[i]=1;
}

void getfish(int x){
	for(int i=0;i<r;i++){
		if(map[i][x]>0){erase(map[i][x]);ans+=map[i][x];
		//printf("\n(%d)%d\n",x,map[i][x]);
		map[i][x]=0;break;}
	}
}

void movefish(){
	for(int i=0;i<m;i++){
		if(check[i])continue;
		map[fish[i][0]-1][fish[i][1]-1]=0;
		switch(fish[i][3]){
			case 1:
				fish[i][2]%=(2*r-2);
				if(fish[i][0]-fish[i][2]<=0){
					fish[i][0]=abs(fish[i][0]-fish[i][2])+2;
					fish[i][3]=2;
					if(fish[i][0]>r){
					fish[i][3]=1;
					 fish[i][0]=(r-(fish[i][0]-r));}
				}
				else
					fish[i][0]-=fish[i][2];
				
				break;
			case 2:
				fish[i][2]%=(2*r-2);
				if(fish[i][0]+fish[i][2]>r){
				
					fish[i][0]=(r)-(fish[i][0]+fish[i][2]-(r));
					fish[i][3]=1;
					if(fish[i][0]<=0){
					fish[i][3]=2;
					fish[i][0]=abs(fish[i][0])+2;}
				}
				else
					fish[i][0]+=fish[i][2];
				
				break;
				
				
			case 3:
				fish[i][2]%=(2*c-2);
				if(fish[i][1]+fish[i][2]>c){
				
					fish[i][1]=(c)-(fish[i][1]+fish[i][2]-(c));
					fish[i][3]=4;
					if(fish[i][1]<=0){
							fish[i][3]=3;
					fish[i][1]=abs(fish[i][1])+2;}
				}
				else
					fish[i][1]+=fish[i][2];
				
				break;
				
			case 4:
				fish[i][2]%=(2*c-2);
				if(fish[i][1]-fish[i][2]<=0){
					fish[i][1]=abs(fish[i][1]-fish[i][2])+2;
					fish[i][3]=3;
					if(fish[i][1]>c){
					fish[i][3]=4;
					 fish[i][1]=(c-(fish[i][1]-c));}
				}
				else
					fish[i][1]-=fish[i][2];
				
				break;
		}
	}
}

void setfish(){
	for(int i=0;i<m;i++){
	if(check[i])continue;
	
		if(map[fish[i][0]-1][fish[i][1]-1]>0){
			if(map[fish[i][0]-1][fish[i][1]-1]<fish[i][4]){	
				erase(map[fish[i][0]-1][fish[i][1]-1]);
				map[fish[i][0]-1][fish[i][1]-1]=fish[i][4];
			
			}
			else{
				erase(fish[i][4]);
			}
		}
		else
			map[fish[i][0]-1][fish[i][1]-1]=fish[i][4];
	}
	
}
void printmap(){
	for(int i=0;i<r;i++){
		for(int j=0;j<c;j++){
			printf("%d ",map[i][j]);
		}
		printf("\n");
	}
		printf("\n");
}

void solve(){

	for(int i=0;i<c;i++){
		setfish();
		//printmap();
		getfish(i);
		movefish();
	}
	printf("%d",ans);
}

main(){
	scanf("%d%d%d",&r,&c,&m);
	for(int i=0;i<m;i++)
		for(int j=0;j<5;j++)
			scanf("%d",&fish[i][j]);
	solve();
}
