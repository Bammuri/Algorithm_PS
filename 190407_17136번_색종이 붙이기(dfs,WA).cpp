#include <cstdio>
#include <vector>
using namespace std;
int paper[10][10],t_paper[10][10];
int ans=1987654312,pa_count[6],visited[6];
void go_next(int k,int d,int tmpans);

void copy_paper(int (*a)[10],int (*b)[10]){
	for(int i=0;i<10;i++)
	for(int j=0;j<10;j++)
		a[i][j]=b[i][j];
}
bool ending(){
	bool f1=true;
	for(int i=0;i<10;i++)
		for(int j=0;j<10;j++)
		if(t_paper[i][j])return false;
}

bool can(int k,int i,int j){
	int a,b,flag=1;
	for(a=i;a<i+k&&a<10;a++)
		for(b=j;b<j+k&&b<10;b++)
			if(t_paper[a][b]!=1||(b==9&&b!=j+k-1))flag=0;
	if(a!=i+k&&b!=i+k)flag=0;

	return flag;
}

void solve(int k,int d,int tmpans){
	if(ending()){ans>tmpans?ans=tmpans:ans;return;}

	int tp[10][10];

	vector <pair<int,int> > candid;
		for(int i=0;i<10;i++)
			for(int j=0;j<10;j++)
				if(can(k,i,j))
					candid.push_back(make_pair(i,j));
		if(candid.size()>5)return;
		if(candid.size()){
		
			for(int i=0;i<candid.size();i++){
			
			int g=candid[i].first,h=candid[i].second;
			for(int a=g;a<g+k;a++)
				for(int b=h;b<h+k;b++)
					t_paper[a][b]=2;
			tmpans++;
			
			if(d==5){ans>tmpans?ans=tmpans:ans;return;}
			else go_next(k,d,tmpans);
			}
		}
		else go_next(k,d,tmpans);
}

void go_next(int k,int d,int tmpans){
	int tp[10][10];
	copy_paper(tp,t_paper);
		
		for(int i=0;k+i<=5;i++){
			
		
			solve(k+i,d+1,tmpans);
			copy_paper(t_paper,tp);
		
		}
		for(int i=1;k-i>0;i++){
			
			solve(k-i,d+1,tmpans);
			copy_paper(t_paper,tp);
		
		}
}



main(){
	for(int i=0;i<10;i++)
	for(int j=0;j<10;j++)
		scanf("%d",&paper[i][j]);

	
	for(int k=1;k<=5;k++){
	copy_paper(t_paper,paper);
	
	solve(k,1,0);

	}

	printf("%d",ans==1987654312?-1:ans);
}
