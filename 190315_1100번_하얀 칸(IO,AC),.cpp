#include <cstdio>
main(){
	char chess[9];
	int row=0,col=0,ans=0;
	for(int row=0;row<8;row++){
		scanf("%s",&chess); 
	    for(int col=0;col<8;col++){
	    	if((col+row)%2==0&&chess[col]=='F')ans++;
	    }
	}
	printf("%d",ans);
}
