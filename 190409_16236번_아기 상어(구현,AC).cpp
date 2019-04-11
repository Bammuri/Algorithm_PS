#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int n,map[22][22],dis[22][22];
int ans=0,size=2,size_tmp=0,tmp=0,t_x=0,t_y=0,x,y,t_min;
int dx[4]={0,1,0,-1},dy[4]={1,0,-1,0};
vector <pair<int,int>> can;
queue <pair<int,int>> q;

void dis_ini(){
	for(int i=0;i<n;i++)
	for(int j=0;j<n;j++)
		dis[i][j]=-1;
}

void print_map(){
	cout<<"\n";
	for(int i=0;i<n;i++){
	for(int j=0;j<n;j++){
		cout<<map[i][j]<<" ";}
		cout<<"\n";}
		cout<<"\n";
	for(int i=0;i<n;i++){
	for(int j=0;j<n;j++){
		cout<<dis[i][j]<<" ";}
		cout<<"\n";}
		cout<<"\n";
		cout<<size<<"\n";
}

void bfs(){
	
	while(!q.empty()){
			int nowx=q.front().first;
			int nowy=q.front().second;
			q.pop();
			for(int i=0;i<4;i++){	
				int a=nowx+dx[i];int b=nowy+dy[i];
				if(a<0||a>=n||b<0||b>=n||map[a][b]>size||dis[a][b]>=0)continue;//||map[a][b]>size
				//return 시키면 그냥 종료된다.. continue!!! 
				q.push(make_pair(a,b));dis[a][b]=dis[nowx][nowy]+1;
			}
	}

}

void get_distance(){
	dis_ini();
	dis[x][y]=0;
	q.push(make_pair(x,y));
	bfs();	
}

void eat(){
	map[x][y]=0;
	ans+=t_min;
	x=t_x,y=t_y,map[x][y]=9;size_tmp++;
	if(size==size_tmp)size++,size_tmp=0;
}

void get_close(){
	t_min=1987654321;t_x=21;t_y=21;
	for(int i=0;i<can.size();i++){
		int cx=can[i].first,cy=can[i].second;
		
		int tmp2=dis[cx][cy];
		if(tmp2==-1)continue;
		
		if(t_min>tmp2)t_min=tmp2,t_x=cx,t_y=cy;
		else if(t_min==tmp2){
			if(t_x>cx){
				t_x=cx;
				t_y=cy;
			}
			else if(t_x==cx){
				if(t_y>cy){
					t_x=cx;
					t_y=cy;
				}
			}
		}
	}
	if (t_min==1987654321)t_min=0;
}


int search(){
	tmp=0;
	can.clear();
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
			if(map[i][j]<size&&map[i][j]<=6&&map[i][j]!=0){can.push_back(make_pair(i,j)),tmp++;}
			else if(map[i][j]==9)x=i,y=j;
	
	return tmp;
}

void solve(){
	
	while(1){
		
		int k=search();
		
		get_distance();
		if(k==1){
			t_x=can[0].first;t_y=can[0].second;
			if(dis[t_x][t_y]==-1)t_min=0,t_x=21;
			else t_min=dis[t_x][t_y];
			eat();
		}
		else if(k==0)break;
		else{
			get_close();
			eat();
		}
		//print_map();
		//cout<<ans<<"\n";
		if (t_x==21){
		cout<<ans;return;}
	}
	
	 cout<<ans;
}
main(){
	ios::sync_with_stdio(0);
	cout.tie(NULL);
	cin>>n;
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
			cin>>map[i][j];
	
	solve();
}
