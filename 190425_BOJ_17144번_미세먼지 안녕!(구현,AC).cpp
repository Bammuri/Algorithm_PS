#include <cstdio>
#include <vector>
using namespace std;
int r,c,t,ans;
int dx[4]={0,1,0,-1};
int dy[4]={1,0,-1,0};
int map[50][50],tmap[50][50],zero[50][50];
vector <int> aircon;

void copymap(int (*a)[50],int (*b)[50]){
	for(int i=0;i<r;i++)
		for(int j=0;j<c;j++)
			a[i][j]=b[i][j];
}

void spot(int x,int y){
	int dust=map[x][y]/5,can=0;
	if(dust>0){
		for(int i=0;i<4;i++){
			int xx=x+dx[i],yy=y+dy[i];
			if(xx>=0&&xx<r&&yy>=0&&yy<c&&map[xx][yy]!=-1){
				tmap[xx][yy]+=dust;
				can++;
			}
		}
		tmap[x][y]+=map[x][y]-dust*can;
	}
	else if(dust==0)tmap[x][y]+=map[x][y];

}

void spread(){
	tmap[aircon[0]][0]=-1,tmap[aircon[1]][0]=-1;
	for(int i=0;i<r;i++){
		for(int j=0;j<c;j++){
			if(map[i][j]>0)
			spot(i,j);
		}
	}
	
	copymap(map,tmap);
}

void cycling(){
	for(int i=aircon[0]-1;i-1>=0;i--)
		map[i][0]=map[i-1][0];
	for(int i=0;i+1<c;i++)
		map[0][i]=map[0][i+1];
	for(int i=0;i+1<=aircon[0];i++)
		map[i][c-1]=map[i+1][c-1];
	for(int i=c-1;i-1>0;i--)
		map[aircon[0]][i]=map[aircon[0]][i-1];
	map[aircon[0]][1]=0;
	
	
	for(int i=aircon[1]+1;i+1<r;i++)
		map[i][0]=map[i+1][0];
	for(int i=0;i+1<c;i++)
		map[r-1][i]=map[r-1][i+1];
	for(int i=r-1;i-1>=aircon[1];i--)
		map[i][c-1]=map[i-1][c-1];
	for(int i=c-1;i-1>0;i--)
		map[aircon[1]][i]=map[aircon[1]][i-1];
	map[aircon[1]][1]=0;
	
}

void count(){
	for(int i=0;i<r;i++){
		for(int j=0;j<c;j++){
			if(map[i][j]!=-1)ans+=map[i][j];
		}
		
	}
	
}

void solve(){
	while(t--){
		copymap(tmap,zero);
		spread();
		cycling();
	}
	count();
	printf("%d",ans); 
}

main(){
	scanf("%d%d%d",&r,&c,&t);
	for(int i=0;i<r;i++)
		for(int j=0;j<c;j++){
			scanf("%d",&map[i][j]);
			if(map[i][j]==-1)aircon.push_back(i);
		}
		
	solve();
			
	
}
