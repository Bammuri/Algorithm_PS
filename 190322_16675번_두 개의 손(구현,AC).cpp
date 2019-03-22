#include <cstdio>
char ml,mr,tl,tr;
main(){
	scanf("%c %c %c %c",&ml,&mr,&tl,&tr);
	
	if((ml!=mr)&&(tl!=tr)){
		printf("?");
	}
	else if(ml==mr&&tl!=tr){
		if(ml=='R'&&(tr=='P'||tl=='P')) printf("TK");
		else if(ml=='P'&&(tr=='S'||tl=='S'))printf("TK");	
		else if(ml=='S'&&(tr=='R'||tl=='R')) printf("TK");
		else printf("?");
	}
	else if(ml!=mr&&tl==tr){
		if(tl=='R'&&(mr=='P'||ml=='P')) printf("MS");
		else if(tl=='P'&&(mr=='S'||ml=='S'))printf("MS");
		else if(tl=='S'&&(mr=='R'||ml=='R')) printf("MS");
		else printf("?");
	}
	else{
		if(ml=='R'){
			if(tl=='P')printf("TK");
			else if(tl=='S')printf("MS");
			else printf("?");
		}
		else if(ml=='P'){
			if(tl=='S')printf("TK");
			else if(tl=='R')printf("MS");
			else printf("?");
		}
		else{
			if(tl=='R')printf("TK");
			else if(tl=='P')printf("MS");
			else printf("?");
		}
	}
	
	
}
