//균형잡은 이진트리이다. 원소 삽입과 삭제, 탐색 등의 연산은 O(logn)을 보장한다. 
#include <iostream>
#include <set>
using namespace std;

main(){
	set<int> s;
	//int 자료형을 저장하는 균형잡힌 이진트리 생성
	
	s.insert(5);
	//원소 5 삽입
	
	if(s.find(6)!=s.end()) 
		printf("존재합니다.\n");
	else 
		printf("없습니다.\n");
	//원소에서 6을 찾음 있다면 해당 원소의 주소값 아니라면 s.end()리턴
	
	printf("%d",s.size());
	//저장된 원소의 수를 리턴
	
	s.clear();
	//모든 원소 삭제
	
	s.erase(++s.begin());
	//해당 주소의 원소 삭제(2번째 원소 삭제) 
}

