#include <cstdio>
int main(){
	int m,d,day_sum=0;//항상 초기화를 해주자  
	int days[12]={31,28,31,30,31,30,31,31,30,31,30,31};
	scanf("%d %d",&m,&d);
	for(int i=0;i<m-1;i++)day_sum+=days[i];//short와 int <비교시 오류가 난다.  
	day_sum+=d;
	switch(day_sum%7){
		case 0: printf("SUN\n");break;
		case 1: printf("MON\n");break;
		case 2: printf("TUE\n");break;
		case 3: printf("WED\n");break;
		case 4: printf("THU\n");break;
		case 5: printf("FRI\n");break;
		case 6: printf("SAT\n");break;		
	}
} 
