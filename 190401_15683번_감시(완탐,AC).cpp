#include <cstdio>
int n,m,ans=1e9;
int map[8][8];

void copy_map(int (*a)[8],int (*b)[8]){
	for(int i=0;i<n;i++)
	for(int j=0;j<m;j++)
		a[i][j]=b[i][j];
}

void up(int x,int y){
	int a=x-1, b=y;
	while(a>=0){
		if(map[a][b]==6)break;
		if(map[a][b]==0)map[a--][b]=-1;
		else a--;
	}
}

void down(int x,int y){
	int a=x+1,b=y;
	while(a<n){
		if(map[a][b]==6)break;
		if(map[a][b]==0)map[a++][b]=-1;
		else a++;
	}	
}

void right(int x,int y){
	int a=x, b=y+1;
	while(b<m){
		if(map[a][b]==6)break;
		if(map[a][b]==0)map[a][b++]=-1;
		else b++;
	}
}

void left(int x,int y){
	int a=x, b=y-1;
	while(b>=0){
		if(map[a][b]==6)break;
		if(map[a][b]==0)map[a][b--]=-1;
		else b--;
	}
}

void dfs(int x,int y){
	int tm[8][8];
	bool f1=true;
	int i,j;
	
	if(y>=m){i=x+1;f1=false;}
	else i=x;
	
	for(i;i<n;i++){
		!f1?j=0:j=y;
		for(j;j<m;j++){
			if(f1)f1=false;

			if(map[i][j]>0&&map[i][j]<6){
				//printf("\n%d %d\n",i,j);
				switch(map[i][j]){
					case 1:
						copy_map(tm,map);
						up(i,j);
						dfs(i,j+1);
						copy_map(map,tm);
							
						down(i,j);
						dfs(i,j+1);
						copy_map(map,tm);
							
						right(i,j);
						dfs(i,j+1);
						copy_map(map,tm);
						
						left(i,j);
						dfs(i,j+1);
						copy_map(map,tm);
						break;
					case 2:
						
						copy_map(tm,map);
						right(i,j);left(i,j);
						dfs(i,j+1);
						copy_map(map,tm);
						
						up(i,j);down(i,j);
						dfs(i,j+1);
						copy_map(map,tm);
						break;
					case 3:
						
						copy_map(tm,map);
						up(i,j);right(i,j);
						dfs(i,j+1);
						copy_map(map,tm);
						
						left(i,j);up(i,j);
						dfs(i,j+1);
						copy_map(map,tm);
						
						down(i,j);left(i,j);
						dfs(i,j+1);
						copy_map(map,tm);
						
						right(i,j);down(i,j);
						dfs(i,j+1);
						copy_map(map,tm);
						break;
						
					case 4:
						
						copy_map(tm,map);
						up(i,j);right(i,j);left(i,j);
						dfs(i,j+1);
						copy_map(map,tm);
						
						left(i,j);up(i,j);down(i,j);
						dfs(i,j+1);
						copy_map(map,tm);
						
						down(i,j);left(i,j);right(i,j);
						dfs(i,j+1);
						copy_map(map,tm);
						
						right(i,j);down(i,j);up(i,j);
						dfs(i,j+1);
						copy_map(map,tm);
						break;
					case 5:
						
						copy_map(tm,map);
						up(i,j);right(i,j);left(i,j);down(i,j);
						//printf("\n(i,j+1)=(%d,%d)\n",i,j+1);
						dfs(i,j+1);
						//printf("\n(i,j+1)=(%d,%d)\n",i,j+1);
						copy_map(map,tm);
						
						break;
				}
			
			}
		}
	}
	int tmp=0;
	for(int i=0;i<n;i++)
	for(int j=0;j<m;j++)
		if(map[i][j]==0)tmp++;
		/*
for(int i=0;i<n;i++){
	for(int j=0;j<m;j++){
	printf("%2d",map[i][j]);}
	printf("\n");}printf("\n");
		*/
	ans=ans>tmp?tmp:ans;
	
}


main(){
	scanf("%d %d",&n,&m);
	for(int i=0;i<n;i++)
	for(int j=0;j<m;j++)
	scanf("%d",&map[i][j]);
	
	dfs(0,0);
	
	printf("%d",ans);
}
