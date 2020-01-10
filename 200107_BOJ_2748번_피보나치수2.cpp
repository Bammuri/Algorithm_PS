#include <iostream>
using namespace std;
long long N,fibo[100];

long long getfibo() {
	fibo[0] = 0;
	fibo[1] = 1;
	fibo[2] = 1;

	for (int i = 3; i <= N; i++) {
		fibo[i] = fibo[i - 1] + fibo[i - 2];

	}

	
	return fibo[N];
}

int main() {
	cin >> N;

	cout<<getfibo();
	

	return 0;
}