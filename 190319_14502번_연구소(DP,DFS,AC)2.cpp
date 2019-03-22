#include <cstdio>
#include <queue>

using namespace std;

int dx[4]={0,0,1,-1};
int dy[4]={1,-1,0,0};
int n,m,ans=0;
int map[8][8],tmpmap[8][8];


void mapcopy(int (*a)[8],int (*b)[8]){
	for(int i=0;i<n;i++)
		for(int j=0;j<m;j++)
			a[i][j]=b[i][j];
}


void spread(){
	int spreadmap[8][8];
	mapcopy(spreadmap,tmpmap);
	std::queue <std::pair<int,int> >q;
	
	for(int i=0;i<n;i++)
		for(int j=0;j<m;j++)
			if(spreadmap[i][j]==2)
				q.push(std::make_pair(i,j));
	
	while(!q.empty()){
		int x=q.front().first;
		int y=q.front().second;
		q.pop();
		for(int i=0;i<4;i++){
			
				int nx=x+dx[i];
				int ny=y+dy[i];
		if(nx>=0&&nx<n&&ny>=0&&ny<m){
		
				if(spreadmap[nx][ny]==0){
					spreadmap[nx][ny]=2;
					q.push(std::make_pair(nx,ny));
				}
		}
		}
	}
	
	int tmp=0;
	for(int i=0;i<n;i++)
		for(int j=0;j<m;j++)
			if(spreadmap[i][j]==0)tmp++;

	ans=max(tmp,ans);
}

void setwall(int cnt){
	if(cnt==3){
	spread();
	return;
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			if(tmpmap[i][j]==0){
				tmpmap[i][j]=1;
				setwall(cnt+1);
				tmpmap[i][j]=0;
			}
		}
	}
}

main(){
	scanf("%d%d",&n,&m);
	for(int i=0;i<n;i++)
		for(int j=0;j<m;j++)
			scanf("%d",&map[i][j]);
	
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			if(map[i][j]==0){
				mapcopy(tmpmap,map);
				tmpmap[i][j]=1;
				setwall(1);
				tmpmap[i][j]=0;
			}
		}
	}
	printf("%d\n",ans);
}
