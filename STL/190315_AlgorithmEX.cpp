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
	
	//sort 기본적으로 오름차순정렬 
	
	sort(arr1,arr1+n);
	sort(arr2.begin(), arr2.end());
	//첫 원소의 주소와 마지막 원소의 다음 주소를 인자로 넘겨준다.
	
	sort(arr1, arr1+n, greater<int>());
	//내림차순 정렬
	
	sort(arr1, arr1+n,cmp);
	//비교함수를 만들어서 넘겨줄 수도 있다. ">" 내림차순 "<" 오름차순
	
	//stable_sort
	stable_sort(arr1,arr1+n);
	
	//lower_bound
	int idx=lower_bound(arr1,arr1+n,42)-arr1;
	printf("%d\n",idx);
	//첫 원소의 주소와 마지막 원소의 다음 주소와 비교할 원소를 넘겨준다.
	//구간내의 원소들은 정렬되어 있어햐 한다.
	//리턴 값은 해당 원소의 주소값이다. 없다면 arr1+n, arr1.end()을 리턴한다.
	
	//upper_bound
	vector<int>::iterator it=upper_bound(arr2.begin(),arr2.end(),54);
	if(it!=arr2.end())
		printf("%d\n",*it);
		
	//max_element
	printf("%d\n",*max_element(arr1,arr1+n));
	//첫 원소의 주소와 마지막 원소의 다음 주소를 인자로 넘겨준다.
	//구간내의 최대값을 가지는 원소의 주소를 리턴한다.
	
	
	//min_element
	printf("%d\n",*min_element(arr2.begin(),arr2.end()));
	
	//unique
	arr2.erase(unique(arr2.begin(),arr2.end()),arr2.end());
	//첫 원소의 주소와 마지막 원소의 다음 주소를 인자로 넘겨준다.
	//구간내의 중복된 원소를 구간의 끝부분으로 밀어주고 마지막 원소의 다음 주소를 리턴한다.
	//구간내의 원소들은 정렬되어 있어야 한다.
	//보통 erase와 함께 중복된 원소를 제거하는 방법으로 사용한다. 
	
	
	//next_permutation
	int arr[10];
	for(int i=0;i<10;i++) arr[i]=i;
	do{
		for(int i=0;i<10;i++) printf("%d ",arr[i]);
		printf("\n");
		
	}while(next_permutation(arr,arr+10));
	//첫 원소의 주소와 마지막 원소의 다음 주소를 인자로 넘겨준다.
	//구간내의 원소들의 다음 순열을 생성하고 true를 리턴한다.
	//다음 순열이 없다면 false를 리턴하다.
	//구간내의 원소들은 정렬되어 있어야 한다. 
}
