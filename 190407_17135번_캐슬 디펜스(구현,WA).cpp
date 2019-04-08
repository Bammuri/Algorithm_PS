#include <cstdio>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;
int n,m,d,ans=0;
int map[16][15],tmp[16][15],zero[16][15],check[16][15];
vector <int> num,idx(3,1);

void map_copy(int (*a)[15],int (*b)[15]){
	for(int i=0;i<n;i++)
	for(int j=0;j<m;j++)
		a[i][j]=b[i][j];
	
}
void solve(vector <int> id){
	int k=n,tm=0;
	
	map_copy(tmp,map);
	map_copy(check,zero);
	do{
		for(int z=0;z<id.size();z++){
			if(id[z]==0)continue;
			int a=num[z];
			int ti=16,tj=16,i,j,min=1987654321;
			for(i=k-1;i>=0;i--)
				for(j=0;j<m;j++)
					if(abs(k-i)+abs(a-j)<=d&&check[i][j]==0&&tmp[i][j]&&min>=abs(k-i)+abs(a-j)){
					if(j<tj){min=abs(k-i)+abs(a-j);ti=i,tj=j;}}		
			if(check[ti][tj]==1||ti==16){}
			else{
				/*printf("\n (%d)%d,%d/%d \n",a,ti,tj,k);*/tm++;check[ti][tj]=1;
			}
		}
	}while(k-->0);
	ans<tm?ans=tm:tm;
}


main(){
	scanf("%d%d%d",&n,&m,&d);
	for(int i=0;i<n;i++)
	for(int j=0;j<m;j++)
		scanf("%d",&map[i][j]);
		
	for(int i=0;i<n;i++)
		num.push_back(i);
		
	for(int i=0;i<n-idx.size();i++)
		idx.push_back(0);
		
	sort(idx.begin(),idx.end());
	do{
		solve(idx);
	}while(next_permutation(idx.begin(),idx.end()));
	
	printf("%d",ans);
}
