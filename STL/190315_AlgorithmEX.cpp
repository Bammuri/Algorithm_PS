#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool cmp(const int a,const int b){
	return a>b;
}

main(){
	int arr1[100000];
	vector<int> arr2(100000,1);
	int n=100000;
	
	//sort �⺻������ ������������ 
	
	sort(arr1,arr1+n);
	sort(arr2.begin(), arr2.end());
	//ù ������ �ּҿ� ������ ������ ���� �ּҸ� ���ڷ� �Ѱ��ش�.
	
	sort(arr1, arr1+n, greater<int>());
	//�������� ����
	
	sort(arr1, arr1+n,cmp);
	//���Լ��� ���� �Ѱ��� ���� �ִ�. ">" �������� "<" ��������
	
	//stable_sort
	stable_sort(arr1,arr1+n);
	
	//lower_bound
	int idx=lower_bound(arr1,arr1+n,42)-arr1;
	printf("%d\n",idx);
	//ù ������ �ּҿ� ������ ������ ���� �ּҿ� ���� ���Ҹ� �Ѱ��ش�.
	//�������� ���ҵ��� ���ĵǾ� �־��� �Ѵ�.
	//���� ���� �ش� ������ �ּҰ��̴�. ���ٸ� arr1+n, arr1.end()�� �����Ѵ�.
	
	//upper_bound
	vector<int>::iterator it=upper_bound(arr2.begin(),arr2.end(),54);
	if(it!=arr2.end())
		printf("%d\n",*it);
		
	//max_element
	printf("%d\n",*max_element(arr1,arr1+n));
	//ù ������ �ּҿ� ������ ������ ���� �ּҸ� ���ڷ� �Ѱ��ش�.
	//�������� �ִ밪�� ������ ������ �ּҸ� �����Ѵ�.
	
	
	//min_element
	printf("%d\n",*min_element(arr2.begin(),arr2.end()));
	
	//unique
	arr2.erase(unique(arr2.begin(),arr2.end()),arr2.end());
	//ù ������ �ּҿ� ������ ������ ���� �ּҸ� ���ڷ� �Ѱ��ش�.
	//�������� �ߺ��� ���Ҹ� ������ ���κ����� �о��ְ� ������ ������ ���� �ּҸ� �����Ѵ�.
	//�������� ���ҵ��� ���ĵǾ� �־�� �Ѵ�.
	//���� erase�� �Բ� �ߺ��� ���Ҹ� �����ϴ� ������� ����Ѵ�. 
	
	
	//next_permutation
	int arr[10];
	for(int i=0;i<10;i++) arr[i]=i;
	do{
		for(int i=0;i<10;i++) printf("%d ",arr[i]);
		printf("\n");
		
	}while(next_permutation(arr,arr+10));
	//ù ������ �ּҿ� ������ ������ ���� �ּҸ� ���ڷ� �Ѱ��ش�.
	//�������� ���ҵ��� ���� ������ �����ϰ� true�� �����Ѵ�.
	//���� ������ ���ٸ� false�� �����ϴ�.
	//�������� ���ҵ��� ���ĵǾ� �־�� �Ѵ�. 
}
