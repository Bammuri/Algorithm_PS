//�����迭�̴�. ������ ��ġ�� �ִ� �������ٰ�, �ڿ��� ���Ҹ� �߰��ϴ� ������ O(1)(���һ�ȯ�м�)�� �����Ѵ�. 
#include <iostream>
#include <vector>
using namespace std;

struct Node{
	int a;
	int b;
};

main(){
	int n=4,m=7;
	vector <int> vec1;
	//int �ڷ����� �����ϴ� �����迭
	
	vector <double> vec2; 
	//double �ڷ����� �����ϴ� �����迭
	
	vector <Node> vec3; 
	//����ڰ� ������ Node ����ü�� �����ϴ� �����迭
	
	vector <int> vec4(n);
	//������ �ʱ� ũ�⸦ n���� ����
	
	vector <int> vec5(n,1); 
	//������ �ʱ� ũ�⸦ n���� �����ϰ� 1�� �ʱ�ȭ
	
	vector<vector<int> > vec6(n,vector<int>(m,0));
	// ũ�Ⱑ n*m�� 2���� ���͸� �����ϰ� 0���� �ʱ�ȭ
	
	vec1.push_back(5);vec1.push_back(7);vec1.push_back(1);
	//������ �� �ڿ� ���� 5,7,1 �߰�
	
	vec1.pop_back();
	//������ �� �� ���� ����
	
	printf("%d\n",vec1.size()); 
	//������ ũ�� ���
	
	vec1.resize(n); 
	//������ ũ�⸦ n���� �缳��
	
	vec1.clear();
	//������ ��� ���� ���� 
	
	vec1.begin();vec1.end();
	//������ ù ������ �ּ�, ������ ������ ���� �ּ� ����
	
	vec1.erase(vec1.begin(),vec1.end());
	//[a,b) �ּ� ������ �ش��ϴ� ���� ����(��� ���� ����)
	
	vec1.push_back(5);vec1.push_back(7);vec1.push_back(1);
	//������ �� �ڿ� ���� 5,7,1 �߰�
	
	vector<int> vec7=vector<int>(vec1.begin()+2,vec1.end());
	//vec7�� vec1�� 2��° ���Һ��� ������ ���ұ��� �����Ͽ� ����
}
	
