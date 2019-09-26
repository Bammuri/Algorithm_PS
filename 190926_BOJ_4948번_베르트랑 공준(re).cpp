#include <iostream>
using namespace std;
const int MAX_NUM = 123456;
bool isnotprime[2 * MAX_NUM + 1];
int n;

void getprime(){
	isnotprime[0] = isnotprime[1] = true;

	for (int i = 2; i < 2 * MAX_NUM + 1; i++)
	{
		if (isnotprime[i])continue;

		for (int j = i * 2; j < 2 * MAX_NUM; j += i)isnotprime[j] = true;
	}
}

void printprime(){
	for (int i = 0; i < 2* MAX_NUM + 1; i++)
	{
		cout << isnotprime[i] << "\n";
	}
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	getprime();

	//printprime();
	cin >> n;
	while (n != 0){
		int ans = 0;
		for (int i = n+1; i < 2*n+1 ; i++)
		{
			if (isnotprime[i])continue;

			ans++;
		}

		cout << ans<<"\n";

		cin >> n;
	}

	return 0;
}