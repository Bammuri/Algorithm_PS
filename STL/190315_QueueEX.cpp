#include <iostream>
#include <queue>
using namespace std;

main(){
	queue<int> q;
	//int�ڷ����� �����ϴ� ť ����
	
	q.push(1);
	q.push(2);
	q.push(3);
	q.push(4);
	q.push(5);
	//���� ����
	
	while(!q.empty()){ 
       int T = q.front();   q.pop();
	   printf("%d ", T); 
  	 } 
	printf("\n"); 
	
	//q.pop();
	//�� �� ���� ��
	
	//printf("%d\n",q.front());
	//�� �� ���� �� ���
	
	//printf("%d\n",q.empty());
	//ť�� ����ִٸ� 1 �ƴϸ� 0
	
	printf("%d\n",q.size());
	//ť�� ����Ǿ� �ִ� ������ �� ��� 
}
