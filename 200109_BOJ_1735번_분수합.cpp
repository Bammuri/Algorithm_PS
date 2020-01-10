#include <iostream>
using namespace std;
int Z1, Z2, M1, M2;
int ans1, ans2,g;

int gcd(int a, int b) {
	if (b == 0) {
		return a;
	}
	return gcd(b, a%b);
}
int main() {
	cin >> Z1 >> M1 >> Z2 >> M2; 

	ans1 = Z1*M2 + Z2*M1;

	ans2 = M1 * M2;
	

	g=gcd(ans1, ans2);

	


	cout << ans1/g << " " << ans2/g;
	return 0;
}