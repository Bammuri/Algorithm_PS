#include <cstdio>
int topni[4][9],f0=0,f1=0,f2=0;

void topcopy(int (*a)[9],int (*b)[9]){
	for(int i=0;i<4;i++)
		for(int j=0;j<8;j++)
			a[i][j]=b[i][j];
		
}

void turn_c(int a){
	int tmp[4][9];
		topcopy(tmp,topni);
		for(int j=0;j<8;j++)topni[a][(j+1)%8]=tmp[a][j];
}

void turn_cw(int a){
	int tmp[4][9];
		topcopy(tmp,topni);
		for(int j=0;j<8;j++)topni[a][j]=tmp[a][(j+1)%8];
}

void move(int a,int b){
	
	switch(a){
		
		case 1:
			if(b==1){
				f0=0,f1=0,f2=0;
				if(topni[0][2]!=topni[1][6])f0=1;
				if(topni[1][2]!=topni[2][6])f1=1;
				if(topni[2][2]!=topni[3][6])f2=1;
				turn_c(0);
				if(f0)turn_cw(1);
				if(f0*f1)turn_c(2);
				if(f0*f1*f2)turn_cw(3);
			}
			else{
				f0=0,f1=0,f2=0;
				if(topni[0][2]!=topni[1][6])f0=1;
				if(topni[1][2]!=topni[2][6])f1=1;
				if(topni[2][2]!=topni[3][6])f2=1;
				turn_cw(0);
				if(f0)turn_c(1);
				if(f0*f1)turn_cw(2);
				if(f0*f1*f2)turn_c(3);
			}
			break;
		case 2:
			if(b==1){
				f0=0,f1=0,f2=0;
				if(topni[0][2]!=topni[1][6])f0=1;
				if(topni[1][2]!=topni[2][6])f1=1;
				if(topni[2][2]!=topni[3][6])f2=1;
				turn_c(1);
				if(f0)turn_cw(0);
				if(f1)turn_cw(2);
				if(f1*f2)turn_c(3);
			}
			else{
				f0=0,f1=0,f2=0;
				if(topni[0][2]!=topni[1][6])f0=1;
				if(topni[1][2]!=topni[2][6])f1=1;
				if(topni[2][2]!=topni[3][6])f2=1;
				turn_cw(1);
				if(f0)turn_c(0);
				if(f1)turn_c(2);
				if(f1*f2)turn_cw(3);
			}
			break;
		case 3:
			if(b==1){
				f0=0,f1=0,f2=0;
				if(topni[0][2]!=topni[1][6])f0=1;
				if(topni[1][2]!=topni[2][6])f1=1;
				if(topni[2][2]!=topni[3][6])f2=1;
				turn_c(2);
				if(f1)turn_cw(1);
				if(f2)turn_cw(3);
				if(f0*f1)turn_c(0);
			}
			else{
				f0=0,f1=0,f2=0;
				if(topni[0][2]!=topni[1][6])f0=1;
				if(topni[1][2]!=topni[2][6])f1=1;
				if(topni[2][2]!=topni[3][6])f2=1;
				turn_cw(2);
				if(f1)turn_c(1);
				if(f2)turn_c(3);
				if(f0*f1)turn_cw(0);//
			}
			break;
		case 4:
			if(b==1){
				f0=0,f1=0,f2=0;
				if(topni[0][2]!=topni[1][6])f0=1;
				if(topni[1][2]!=topni[2][6])f1=1;
				if(topni[2][2]!=topni[3][6])f2=1;
				turn_c(3);
				if(f2)turn_cw(2);
				if(f2*f1)turn_c(1);
				if(f2*f1*f0)turn_cw(0);
			}
			else{
				f0=0,f1=0,f2=0;
				if(topni[0][2]!=topni[1][6])f0=1;
				if(topni[1][2]!=topni[2][6])f1=1;
				if(topni[2][2]!=topni[3][6])f2=1;
				turn_cw(3);
				if(f2)turn_c(2);
				if(f2*f1)turn_cw(1);
				if(f2*f1*f0)turn_c(0);
			}
			break;
		}	
}

main(){
	for(int i=0;i<4;i++)
		for(int j=0;j<8;j++)
			scanf("%1d",&topni[i][j]);

	int k,a,b;
	scanf("%d",&k);
	for(int i=0;i<k;i++){
		scanf("%d %d",&a,&b);
		move(a,b);
	}
	
	int ans=0,two=1;
	
	for(int i=0;i<4;i++)
	{
		ans+=topni[i][0]*two;
		two*=2;
	}
	printf("%d\n",ans);
	/*
	for(int i=0;i<4;i++){
		for(int j=0;j<8;j++){
			printf("%d",topni[i][j]);
		}
		printf("\n"); 
	}
	*/
	
}
