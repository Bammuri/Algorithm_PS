#include <cstdio>
int map[21][21];
int dice[6]={0,0,0,0,0,0};// À§,¿·¿Þ,¾Æ,¿·¿À,¿·À§,¿·¾Æ 
int N,M,x,y,K;


void dice_move(int a){
		int t0,t1,t2,t3,t4,t5;
		switch(a){
		case 1:
			t1=dice[1],t2=dice[2],t3=dice[3],t0=dice[0];
			dice[3]=t0;
			dice[2]=t3;
			dice[1]=t2;
			dice[0]=t1;break;
		case 2:
			t1=dice[1],t2=dice[2],t3=dice[3],t0=dice[0];
			dice[3]=t2;
			dice[2]=t1;
			dice[1]=t0;
			dice[0]=t3;break;
		case 3:
			t0=dice[0],t2=dice[2],t4=dice[4],t5=dice[5];
			dice[4]=t0;
			dice[5]=t2;
			dice[2]=t4;
			dice[0]=t5;break;
		case 4:
			t0=dice[0],t2=dice[2],t4=dice[4],t5=dice[5];
			dice[4]=t2;
			dice[2]=t5;
			dice[5]=t0;
			dice[0]=t4;break;
		}
}

int isinrange(int a,int b){
	if(a<0||a>=N||b<0||b>=M) return 0;
	else{x=a;y=b;return 1;}
}

void whatisinthemap(){
	if(map[x][y]==0)map[x][y]=dice[2];
	else{dice[2]=map[x][y];map[x][y]=0;}
}

int main(){
	
	scanf("%d%d%d%d%d",&N,&M,&x,&y,&K);

	for(int i=0;i<N;i++){
		for(int j=0;j<M;j++)scanf("%d",&map[i][j]);
	}	
	
	for(int i=0;i<K;i++){
		int num;
		scanf("%d",&num);
		
		if(num==1){
			if(isinrange(x,y+1)){	
				dice_move(num);
				whatisinthemap();	
			}
			else continue;
		} 
		else if(num==2){
			if(isinrange(x,y-1)){	
				dice_move(num);
				whatisinthemap();	
			}
			else continue;
		}
		else if(num==3){
			if(isinrange(x-1,y)){
				dice_move(num);
				whatisinthemap();	
			}
			else continue;
		}
		else {
			if(isinrange(x+1,y)){
				dice_move(num);
				whatisinthemap();	
			}
			else continue;
		}
		printf("%d\n",dice[0]);

	}
}
