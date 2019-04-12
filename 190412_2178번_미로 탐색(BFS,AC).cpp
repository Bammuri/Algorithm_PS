#include <cstdio>
#include <queue>
using namespace std;
int n,m,map[101][101],dis[101][101];
int dx[4]={0,1,0,-1},dy[4]={1,0,-1,0};
queue <pair<int,int> > q;

void print_dis(){
	for(int i=0;i<n;i++){
	for(int j=0;j<m;j++)
		printf("%2d ",dis[i][j]);
		printf("\n");
		}
	printf("\n");
}

void bfs(){
	while(!q.empty()){
		int a=q.front().first, b=q.front().second;

		q.pop();
		for(int i=0;i<4;i++){
			int c=a+dx[i],d=b+dy[i];
			if((c>=0&&d>=0&&c<n&&d<m&&map[c][d])){///c->d로 안바꿔서 1시간..  
			dis[c][d]=dis[a][b]+1;
			map[c][d]=0;
			q.push(make_pair(c,d));	
			}
			
		}
	
	}
}
main(){

	scanf("%d%d",&n,&m);
	for(int i=0;i<n;i++)
		for(int j=0;j<m;j++)
			scanf("%1d",&map[i][j]);
	
	map[0][0]=0;
	dis[0][0]=1;		
	q.push(make_pair(0,0));
	bfs();
	print_dis();
	printf("%d",dis[n-1][m-1]);
}
