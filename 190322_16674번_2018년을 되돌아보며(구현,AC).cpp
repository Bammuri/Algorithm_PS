#include <cstdio>
char sum[12];
int c2=0,c0=0,c1=0,c8=0;
int main(){
	scanf("%s",sum);
	for(int i=0;sum[i]!='\0';i++){
		if(sum[i]=='2'||sum[i]=='0'||sum[i]=='1'||sum[i]=='8'){
			if(sum[i]=='2')c2++;
			else if(sum[i]=='0')c0++;
			else if(sum[i]=='1')c1++;
			else if(sum[i]=='8')c8++;
		}
		else{
			printf("0");return 0;
		}
	}
		if(c2*c0*c1*c8==0){
			printf("1");return 0;
		}
		else{
			if(c2==c0&&c1==c8&&c1==c0){
				printf("8");return 0;
			}
			else{
				printf("2");return 0;
			}
		}
}
