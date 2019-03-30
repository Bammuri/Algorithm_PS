#include <cstdio>
#include <algorithm>
using namespace std;
int n, m, map[51][51],x,y,h,ans=1;
int dx[]={-1,0,1,0};
int dy[]={0,1,0,-1};

void do_clean(){
	while(true){
		bool clean=false;
		for(int k=0;k<4;k++){
			int nh=(h+3)%4;
			int nx=x+dx[nh],ny=y+dy[nh];
			h=nh;
			if(!map[nx][ny]){
				map[nx][ny]=2;
				clean=true;
				ans++;
				x=nx;y=ny;
				break;
			}
		}
		if(!clean){
			if(map[x-dx[h]][y-dy[h]]==1)return;
			else x-=dx[h],y-=dy[h];
		}
	}
} 

main(){
	scanf("%d%d",&n,&m);
	scanf("%d%d%d",&x,&y,&h);
	for(int i=0;i<n;i++)
		for(int j=0;j<m;j++)
			scanf("%d",&map[i][j]);
	map[x][y]=2;		
	do_clean();	
	printf("%d",ans);
}
