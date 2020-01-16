#include <iostream>
#include <algorithm>
#include <stack>

using namespace std;

struct ans {
	int order, num;
};

stack <int> st;
int N, arr[1000002],a[1000002],len;
ans answ[1000002];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> N;
	for (int i = 0; i < N; i++) {
		int n;
		cin >> n;

		auto p = lower_bound(a, a + len, n);
		//cout << p - a<<"\n";
		*p = n;
		answ[i].order=p-a;
		answ[i].num = n;
		if (p == a + len)
			len++;

	}
	cout << len<<"\n";
	len--;
	for (int i = N-1; i  >=0; i--) {
		if (answ[i].order == len) {
			st.push(answ[i].num);
			len--;
		}
	}

	while (!st.empty()) {
		cout << st.top() << " ";
		st.pop();
	}



}