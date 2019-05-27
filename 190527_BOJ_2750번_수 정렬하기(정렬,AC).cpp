/*#include <iostream>
#include <algorithm>
using namespace std;
int N;
int arr[1000];
main(){
	ios::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(NULL);
	cin>>N;
	for(int i=0;i<N;i++){
		cin>>arr[i];
	}
	sort(arr,arr+N);
	for(int i=0;i<N;i++){
		cout<<arr[i]<<"\n";
	}
}

*/
#include<cstdio>

void qsort(int a[], int s, int e){
	if( s>e) return;
	int p =e;
	int l =s;
	for (int i = s; i <e; ++i)
	{
		if(a[i] < a[p]){
			int t= a[i];
			a[i] = a[l];
			a[l++] = t;
		}
	}
	int t =a[p];
	a[p] = a[l];
	a[l] =t;
	qsort(a,s,l-1);
	qsort(a,l+1,e);
}
int main()
{
	int n;
	int a[1000];
	scanf("%d",&n);
	for( int i=0;i<n;++i)
	{
		scanf("%d",&a[i]);
	}
	qsort(a,0,n-1);
	for(int i=0;i<n; ++i)
	{
			printf("%d\n",a[i]);
	}
	return 0;
}
