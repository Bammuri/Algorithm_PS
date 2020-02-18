#include <iostream>
using namespace std;

int n, k;
int ret;


int get_pacto(int n)
{
	int sum = 1;
	if (n == 0)
		return (1);
	
	do
	{
		sum *= n;
	} while (--n);

	return (sum);
}

int main(){
	ios::sync_with_stdio(NULL);
	cin.tie(0);
	cin >> n >> k;

	ret = get_pacto(n) / (get_pacto(k) * get_pacto(n - k));
	
	cout << ret;
	return 0;
}