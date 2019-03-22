#include <cstdio>
char text[6][16];
main(){
	for(int i=0;i<5;i++)
					scanf("%s",&text[i]);
	
	for(int i=0;i<16;i++)
		for(int j=0;j<5;j++){
			if(text[j][i]==NULL)continue;
				printf("%c",text[j][i]);}
}
