//��ųʸ� �ڷᱸ���̴�. ������ ���԰� ����, Ž�� ���� ������ O(logn)�� �����Ѵ�.
#include <iostream>
#include <map>
using namespace std;
main(){
	map<int, int> m;
	//int �ڷ����� key�� int�ڷ����� �����ϴ� ��ųʸ� �ڷᱸ�� ����
	
	m.insert(make_pair(4,5));	/*OR*/ m[5]=6;
	//(4,5)���� ����
	

	printf("%d,%d\n",m.find(4)->first,m.find(4)->second); 
	//key�� ������ ���Ҹ� pair<Ű �ڷ���, ������ �ڷ���> ���·� ������
	
	printf("%d\n",m.count(4));
	//key�� ������ ������ ������ ������ 
	
	printf("%d\n",m.size());
	//����� ������ ���� ������
	
	m.erase(++m.begin());
	//�ش� �ּ��� ���� ����
	
	m.clear();
	//��� ���� ����	 
} 
