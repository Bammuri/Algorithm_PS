//스택 자료구조이다.
#include <iostream>
#include <stack>
using namespace std;

main(){
	stack<int> st;
	//int 자료형을 저장하는 스택 생성
	
	st.push(1);
	st.push(2);
	st.push(3);
	st.push(4);
	st.push(5);
	//원소 삽입
	
		
	while(!st.empty()){ 
       int T = st.top();   st.pop();
	   printf("%d ", T); 
  	 } 
	printf("\n"); 
	
	//st.pop();
	//맨 위 원소 팝 
	
	//printf("%d\n",st.top());
	//맨 위 원소 값 출력 
	
	//printf("%d\n",st.empty());
	//스택이 비어있다면 1 아니면 0
	
	printf("%d\n",st.size());
	//스택에 저장되어 있는 원소의 수 출력 
} 
