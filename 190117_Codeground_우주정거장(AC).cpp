#include <iostream>
#include <queue>
#include <vector>
#define MAX 200001

using namespace std;

vector<int> a[MAX];
queue<int> q;
int result;

//vector에서 특정한 원소를 찾아 제거합니다. 
void vectorDrop(int now,int target){
	for(int i=0;i<a[now].size();i++){
		if(a[now][i]==target){
			a[now].erase(a[now].begin()+i);
		}
	}
} 

//삼각형 사이클을 발견했을 때 처리하는 함수입니다.
void process(int target){
	
	vectorDrop(a[target][0],target);
	vectorDrop(a[target][1],target);
	if(a[a[target][0]].size()==2){
		q.push(a[target][0]);
	}
	if(a[a[target][1]].size()==2){
		q.push(a[target][1]);
	}
}

//DFS를 이용해서 삼각형 사이클을 찾습니다.
void find(int target,int now,int count) {
	if(count==3)
	{
		for(int i=0;i<a[now].size();i++)
		{
		//삼각형 사이클 	
			if(a[now][i]==target)
			{
			result++;
			process(target); //target node를 지우는 작업 
			return; 
			}
		}
		return ;
	}
	//연결된 노드를 DFS 탐색합니다. 
	for(int i=0 ;i<a[now].size();i++){
		find(target,a[now][i],count+1);
	}
}

int main(){
	int n,m;
	cin>>n>>m;
	for(int i=0;i<m;i++){
		int x,y;
		cin>>x>>y;
		a[x].push_back(y);
		a[y].push_back(x);
	}
	//연결된 간선이 2개인 노드를 큐에 삽입
	for(int i=1;i<=n;i++){
		if(a[i].size()==2){
			q.push(i);
		}
	}
	//큐가 비워질 때까지 사이클을 찾아 처리합니다. 
	while(!q.empty()){
		int x=q.front();
		q.pop();
		find(x,x,1);
	}
	cout<<n-result<<'\n';
}



