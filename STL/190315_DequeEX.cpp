//�����迭�̴�. ������ ��ġ�� �ִ� ���� ���ٰ�, �հ� �ڿ��� ���Ҹ� �߰��ϴ� ������ O(1)�� �����Ѵ�. 
#include <iostream>
#include <deque>
using namespace std;
main(){
	deque<int> dq;
	//int �ڷ����� �����ϴ� �����迭 ����
	
	dq.push_front(5);
	//�迭 �� �տ� ���� 5 �߰�
	
	dq.push_back(5);
	//�迭 �� �ڿ� ���� 5 �߰� 
	
	dq.pop_front();
	//�迭 �� ���� ���� ����
	
	dq.pop_back();
	//�迭 �� ���� ���� ����
	
	//�������� vector�� ���� 
}

