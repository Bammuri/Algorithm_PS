//�������� ����Ʈ���̴�. ���� ���԰� ����, Ž�� ���� ������ O(logn)�� �����Ѵ�. 
#include <iostream>
#include <set>
using namespace std;

main(){
	set<int> s;
	//int �ڷ����� �����ϴ� �������� ����Ʈ�� ����
	
	s.insert(5);
	//���� 5 ����
	
	if(s.find(6)!=s.end()) 
		printf("�����մϴ�.\n");
	else 
		printf("�����ϴ�.\n");
	//���ҿ��� 6�� ã�� �ִٸ� �ش� ������ �ּҰ� �ƴ϶�� s.end()����
	
	printf("%d",s.size());
	//����� ������ ���� ����
	
	s.clear();
	//��� ���� ����
	
	s.erase(++s.begin());
	//�ش� �ּ��� ���� ����(2��° ���� ����) 
}

