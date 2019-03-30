#include <cstdio>

int map[51][51];
int al_clean[51][51];
int n,m,ans=0;
int dx[4]={0,0,-1,1};
int dy[4]={-1,1,0,0};
int f[4];

struct location{
	int x;
	int y;
	int h;
};
struct location lo;

int turn_left(struct location lo){
	return lo.h=(lo.h-1)<0?3:lo.h-1;
}

int see_left(struct location lo){
	switch(lo.h){
		case 0:
		 return map[lo.x][lo.y-1];
		case 1:
		 return map[lo.x-1][lo.y];
		case 2:
		 return map[lo.x][lo.y+1];
		case 3:
		 return map[lo.x+1][lo.y];
	}
}

int see_left_c(struct location lo){
	switch(lo.h){
		case 0:
		 return al_clean[lo.x][lo.y-1];
		case 1:
		 return al_clean[lo.x-1][lo.y];
		case 2:
		 return al_clean[lo.x][lo.y+1];
		case 3:
		 return al_clean[lo.x+1][lo.y];
	}
}

int is_left_clean(struct location lo){
	if(see_left_c(lo)==0)return 0;
	else return 1;
}

int see_behind(struct location lo){
	switch(lo.h){
		case 0:
		 return map[lo.x+1][lo.y];
		case 1:
		 return map[lo.x][lo.y-1];
		case 2:
		 return map[lo.x-1][lo.y];
		case 3:
		 return map[lo.x][lo.y+1];
	}
}

void go_behind(struct location lo){
	switch(lo.h){
		case 0:
			lo.x+=1;break;
		case 1:
			lo.y-=1;break;
		case 2:
			lo.x-=1;break;
		case 3:
			lo.y+=1;break;			
	}
}

void go_front(struct location lo){
	switch(lo.h){
		case 0:
			lo.x-=1;break;
		case 1:
			lo.y+=1;break;
		case 2:
			lo.x+=1;break;
		case 3:
			lo.y-=1;break;			
	}
}


void do_clean(struct location lo){
	if(!al_clean[lo.x][lo.y]&&!map[lo.x][lo.y]){
	al_clean[lo.x][lo.y]=1;ans++;
	}
	
	for(int i=0;i<4;i++){
		f[i]=0;
		if(map[lo.x+dx[i]][lo.x+dy[i]]==1||al_clean[lo.x+dx[i]][lo.y+dy[i]]==1)f[i]=1;
	}
	
	if(f[0]*f[1]*f[2]*f[3]&&see_behind(lo)==1)return;
	else if(f[0]*f[1]*f[2]*f[3]&&see_behind(lo)==0){
	go_behind(lo);do_clean(lo);
	}
	
	if(see_left(lo)==0&&is_left_clean(lo)==0){
	turn_left(lo);go_front(lo);do_clean(lo);
	}
	else if(is_left_clean(lo)==1||see_left(lo)==1){
	turn_left(lo);do_clean(lo);
	}

}

main(){
	scanf("%d %d",&n,&m);
	scanf("%d%d%d",&lo.x,&lo.y,&lo.h);
	for(int i=0;i<n;i++)
		for(int j=0;j<m;j++)
			scanf("%1d",&map[i][j]);
	
	do_clean(lo);
	
	printf("%d",ans);
}
