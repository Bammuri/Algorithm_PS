#include <cstdio>
int map[501][501],ans=0;
int check[501][501];
int n,m;
int dx[]={-1,0,1,0};
int dy[]={0,1,0,-1};

void dfs(int x,int y,int depth,int sum){
		if(depth==4){ans=ans<sum?sum:ans;return;}
		for(int i=0;i<4;i++){
				int nx=x+dx[i];
				int ny=y+dy[i];
				if(x>=0&&x<n&&y>=0&&y<m){
					if(!check[nx][ny]){
					check[nx][ny]=1;
					dfs(nx,ny,depth+1,sum+map[nx][ny]);
					check[nx][ny]=0;
					}
				}	
		}
}

void ou(int x,int y){
	//っ 
	if(x-1>=0&&x+1<n&&y+1<m&&y>=0){
		int tmp=map[x][y]+map[x][y+1]+map[x-1][y+1]+map[x+1][y+1];
		ans=ans<tmp?tmp:ans;
		//ans=ans<tmp?printf(" %d, %d ",x,y):ans;
	}
	
	//た 
	if(x-1>=0&&x+1<n&&y<m&&y-1>=0){
		int tmp=map[x][y]+map[x][y-1]+map[x-1][y-1]+map[x+1][y-1];
		ans=ans<tmp?tmp:ans;
		//ans=ans<tmp?printf(" %d, %d ",x,y):ans;
	}
	
	//で 
	if(x>=0&&x+1<n&&y+1<m&&y-1>=0){
		int	tmp=map[x][y]+map[x+1][y+1]+map[x+1][y]+map[x+1][y-1];
		ans=ans<tmp?tmp:ans;
		//ans=ans<tmp?printf(" %d, %d ",x,y):ans;
	}
	
	//ぬ 
	if(x-1>=0&&x<n&&y+1<m&&y-1>=0){
		int tmp=map[x][y]+map[x-1][y-1]+map[x-1][y]+map[x-1][y+1];
		ans=ans<tmp?tmp:ans;
		//ans=ans<tmp?printf(" %d, %d ",x,y):ans;
	}
	
}

void solve(){
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			check[i][j]=1;
			dfs(i,j,1,map[i][j]);
			ou(i,j);
			check[i][j]=0;
		}
	}
}

main(){
	scanf("%d %d",&n,&m);
	for(int i=0;i<n;i++)
		for(int j=0;j<m;j++)
			scanf("%d",&map[i][j]);
			
	solve();
	printf("%d",ans);
	
}
