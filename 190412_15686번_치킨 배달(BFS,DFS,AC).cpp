#include <iostream>
#include <queue>
using namespace std;
int n,m,ans=1987654321; 
int dx[4]={0,1,0,-1},dy[4]={1,0,-1,0};
int map[50][50],dis[50][50],zero[50][50],check[50][50];
vector <pair<int,int> >chickk,chick;
vector <pair<int,int> >house;

void print_dis(){//������� ���� ����� 
	for(int i=0;i<n;i++){
	
	for(int j=0;j<n;j++){
	
		cout<<dis[i][j]<<" ";}
	cout<<"\n";}
	cout<<"\n";
}

void copy_map(int (*a)[50],int (*b)[50]){//�����Լ� 
	for(int i=0;i<n;i++)
	for(int j=0;j<n;j++)
		a[i][j]=b[i][j];
}

void cnt_dis(){
	copy_map(check,zero);//bfs�� ���� �湮check �ʱ�ȭ 
	queue <pair<int,int> >cchick;//���Ϳ��� ť�� ġŲ���ű�� 
	for(int i=0;i<chickk.size();i++){
		cchick.push(make_pair(chickk[i].first,chickk[i].second));
		check[chickk[i].first][chickk[i].second]=1;
	}

	while(!cchick.empty()){//bfs�� dis�迭�� �ּҰŸ� ��� 
		int a=cchick.front().first,b=cchick.front().second;
		
		cchick.pop();
		for(int i=0;i<4;i++){
			int x=a+dx[i],y=b+dy[i];
			if(	x>=0&&x<n&&y>=0&&y<n&&!check[x][y]){
				check[x][y]=1;
				dis[x][y]=dis[a][b]+1;
				cchick.push(make_pair(x,y));
				
			}

		}

	}
	
}

void dfs(int depth,int x,int y){
	if(depth==m){//�ִ� m�� ������ 
		copy_map(dis,zero);
		cnt_dis();//�Ÿ���� 
		int tmp=0;
		print_dis();
		for(int i=0;i<house.size();i++){//map�� �ִ� ��� ���Ÿ��� �� 
			tmp+=dis[house[i].first][house[i].second];
		}
		if(ans>tmp)ans=tmp;//�ּҰ� ã�� 
		return; 
	}
	
	int j=y,flag=0;
	int t_map[50][50];
	for(int i=x;i<n;i++){
		if(flag)j=0;
		for(;j<n;j++){
			flag=1;
			if(map[i][j]==2){
				chickk.push_back(make_pair(i,j));//ġŲ�� �ĺ��� vector�� �ֱ� 
				//print_chick();
				if(j+1>=n) dfs(depth+1,i+1,0);///j+1�ɶ� ����ó�� ��������!!!! 
				else dfs(depth+1,i,j+1);//���� ġŲ������ 
				chickk.pop_back();//���Ϳ��� ���� 
			}
		}
	}
	
}
main(){
	ios::sync_with_stdio(0);
	cout.tie(NULL);
	cin>>n>>m;
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++){
			cin>>map[i][j];
			if(map[i][j]==1)house.push_back(make_pair(i,j));//����ǥ ��� 
			else if(map[i][j]==2)chick.push_back(make_pair(i,j));//ġŲ�� ��ǥ ��� 
		}
	for(int i=0;i<chick.size();i++)	dfs(0,chick[i].first,chick[i].second);//ġŲ�� ��� dfs 
	cout<<ans;
}
