#include <iostream>
#include <queue>
#include <vector>
#define MAX 200001

using namespace std;

vector<int> a[MAX];
queue<int> q;
int result;

//vector���� Ư���� ���Ҹ� ã�� �����մϴ�. 
void vectorDrop(int now,int target){
	for(int i=0;i<a[now].size();i++){
		if(a[now][i]==target){
			a[now].erase(a[now].begin()+i);
		}
	}
} 

//�ﰢ�� ����Ŭ�� �߰����� �� ó���ϴ� �Լ��Դϴ�.
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

//DFS�� �̿��ؼ� �ﰢ�� ����Ŭ�� ã���ϴ�.
void find(int target,int now,int count) {
	if(count==3)
	{
		for(int i=0;i<a[now].size();i++)
		{
		//�ﰢ�� ����Ŭ 	
			if(a[now][i]==target)
			{
			result++;
			process(target); //target node�� ����� �۾� 
			return; 
			}
		}
		return ;
	}
	//����� ��带 DFS Ž���մϴ�. 
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
	//����� ������ 2���� ��带 ť�� ����
	for(int i=1;i<=n;i++){
		if(a[i].size()==2){
			q.push(i);
		}
	}
	//ť�� ����� ������ ����Ŭ�� ã�� ó���մϴ�. 
	while(!q.empty()){
		int x=q.front();
		q.pop();
		find(x,x,1);
	}
	cout<<n-result<<'\n';
}



