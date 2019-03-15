//딕셔너리 자료구조이다. 원소의 삽입과 삭제, 탐색 등의 연산은 O(logn)을 보장한다.
#include <iostream>
#include <map>
using namespace std;
main(){
	map<int, int> m;
	//int 자료형을 key로 int자료형을 저장하는 딕셔너리 자료구조 생성
	
	m.insert(make_pair(4,5));	/*OR*/ m[5]=6;
	//(4,5)원소 삽입
	

	printf("%d,%d\n",m.find(4)->first,m.find(4)->second); 
	//key와 연관된 원소를 pair<키 자료형, 데이터 자료형> 형태로 리턴함
	
	printf("%d\n",m.count(4));
	//key와 연관된 원소의 개수를 리턴함 
	
	printf("%d\n",m.size());
	//저장된 원소의 수를 리턴함
	
	m.erase(++m.begin());
	//해당 주소의 원소 삭제
	
	m.clear();
	//모든 원소 삭제	 
} 
