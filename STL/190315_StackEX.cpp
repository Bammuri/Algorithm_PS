//���� �ڷᱸ���̴�.
#include <iostream>
#include <stack>
using namespace std;

main(){
	stack<int> st;
	//int �ڷ����� �����ϴ� ���� ����
	
	st.push(1);
	st.push(2);
	st.push(3);
	st.push(4);
	st.push(5);
	//���� ����
	
		
	while(!st.empty()){ 
       int T = st.top();   st.pop();
	   printf("%d ", T); 
  	 } 
	printf("\n"); 
	
	//st.pop();
	//�� �� ���� �� 
	
	//printf("%d\n",st.top());
	//�� �� ���� �� ��� 
	
	//printf("%d\n",st.empty());
	//������ ����ִٸ� 1 �ƴϸ� 0
	
	printf("%d\n",st.size());
	//���ÿ� ����Ǿ� �ִ� ������ �� ��� 
} 
