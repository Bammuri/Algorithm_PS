 //정렬이 문제를 쉽게 풀 수 있는 실마리가 될 수 있다. 
 #include <iostream>
 #include <algorithm>
 #include <vector>
 
 using namespace std;
 
 vector <int> a;
 
int main(void){
	int n, k;
	cin >>n >>k;
	for(int i=0;i<n;i++){
		int x;
		cin>>x;
		a.push_back(x);
	}
	sort(a.begin(),a.end()); //기본적으로 오름차순 정렬  
	int result=1;
	for(int i=1;i<a.size();i++){
		if(a[i]-a[i-result]<=k)result++;
		
	} 
	
	cout<<result;
	
	return 0;
}
