#include <cstdio>

int n,k,re,N_re;
long long sum,plus;


main(){
	
	while(scanf("%d %d",&n,&k)!=-1){
		
		sum=n;plus=n/k;re=0;N_re=n%k;
		
		do{
		re=N_re;
		sum+=plus;
		
		if(plus+re>=k){
			if((plus+re)%k!=0)
					N_re=(plus+re)%k;
			else
				N_re=0;
			plus=(plus+re)/k;
			
		}
		else
			plus=0;	

		}while(plus>0);
		printf("%lld\n",sum);
	}

} 
