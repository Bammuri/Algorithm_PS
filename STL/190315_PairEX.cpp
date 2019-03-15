//pair 2개의 데이터를 저장할 수 있는 변수이다. 비교 연산시 1순위-first 2순위-second로 판별한다.
#include <iostream>
#include <utility>
using namespace std;
main(){
	pair<int,int> p;
	//int, int 자료형을 저장하는 변수 선언
	
	p=make_pair(4,5);
	//(4,5)를 p에 저장
	
	p={4,5};
	//c++11부터 가능 
} 
