#include <cstdio>
#include <vector>
using namespace std;
int n,ans=0;
int map[101][101];
int dx[]={1,0,-1,0};
int dy[]={0,-1,0,1};
int x,y,d,g;
vector <int> st;

void draw(){
	for(int i=0;i<st.size();i++){
		int dir=st[i];
		x+=dx[dir];y+=dy[dir];
		map[x][y]=1;
	}
}

main(){
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%d %d %d %d",&x,&y,&d,&g);
		map[x][y]=1;
		st.clear();
		st.push_back(d);
		while(g-->0)
			for(int i=st.size()-1;i>=0;i--)
				st.push_back((st[i]+1)%4);
		draw();
	}
	for(int i=0;i<100;i++)
	for(int j=0;j<100;j++)
	if(map[i][j]==1&&map[i+1][j]==1&&map[i][j+1]==1&&map[i+1][j+1]==1)ans++;

	printf("%d",ans);
}
