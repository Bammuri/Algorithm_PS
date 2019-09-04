#include <iostream>
#include <vector>
#include <queue>
#define MAX 20001

using namespace std;

vector<int> c[MAX];
queue<int> q;
int result,N,M,a,b;
int Answer;

void init(){
	for(int i=0;i<MAX;i++)c[i].clear();
	result=0;
	queue<int> empty;
	swap(q,empty);
}


void vectorDrop(int now,int target){
	for(int i=0;i<c[now].size();i++){
		if(c[now][i]==target){
			c[now].erase(c[now].begin()+i);
		}
	}
}

void dropnode(int target){
	vectorDrop(c[target][0],target);
	vectorDrop(c[target][1],target);
	if(c[c[target][0]].size()==2)q.push(c[target][0]);
	if(c[c[target][1]].size()==2)q.push(c[target][1]);
	
}

void find(int target,int now,int depth){
	if(depth==3){
		for(int i=0;i<c[now].size();i++){
			if(c[now][i]==target){
				result++;
				dropnode(target);
				return;
			}
		}
		return;
	}
	
	for(int i=0;i<c[now].size();i++){
		find(target,c[now][i],depth+1);
	}
	
}

int main(int argc, char** argv)
{
	int T, test_case;
	cin >> T;
	for(test_case = 0; test_case  < T; test_case++)
	{
		init();
		Answer = 0;
		cin>>N>>M;
		for(int i=0;i<M;i++){
			cin>>a>>b;
			c[a].push_back(b);
			c[b].push_back(a);
		}
		
		for(int i=0;i<MAX;i++){
			if(c[i].size()==2)q.push(i);
			
		}
		
		while(!q.empty()){
			int x=q.front();
			q.pop();
			find(x,x,1);
		}
		
		
		Answer=N-result;
			
		cout << "Case #" << test_case+1 << endl;
		cout << Answer << endl;
	}

	return 0;//Your program should return 0 on normal termination.
}
