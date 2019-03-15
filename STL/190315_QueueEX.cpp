#include <iostream>
#include <queue>
using namespace std;

main(){
	queue<int> q;
	//int자료형을 저장하는 큐 생성
	
	q.push(1);
	q.push(2);
	q.push(3);
	q.push(4);
	q.push(5);
	//원소 삽입
	
	while(!q.empty()){ 
       int T = q.front();   q.pop();
	   printf("%d ", T); 
  	 } 
	printf("\n"); 
	
	//q.pop();
	//맨 위 원소 팝
	
	//printf("%d\n",q.front());
	//맨 위 원소 값 출력
	
	//printf("%d\n",q.empty());
	//큐가 비어있다면 1 아니면 0
	
	printf("%d\n",q.size());
	//큐에 저장되어 있는 원소의 수 출력 
}
