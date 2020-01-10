#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int N, H,mn=1987654321,cnt=0;


int main() {
	cin >> N >> H;
	vector<int>l(N / 2);
	vector<int>h(N / 2);
	for (int i = 0; i < N/2; i++) {
		cin >> l[i] >> h[i];
	}

	sort(l.begin(), l.end());
	sort(h.begin(), h.end());

	for (int i = 1; i <= H; i ++) {
		
		//lower
		int u = N / 2 - (lower_bound(l.begin(), l.end(), i)-l.begin());
		
		//upper
		int v = N / 2 - (upper_bound(h.begin(), h.end(), H - i) - h.begin());

		cout << u << " " << v << "\n";
		if (mn > u + v) {
			mn = u + v;
			cnt = 1;
		}
		else if(mn==u+v) {
			cnt++;
		}
	}

	cout << mn << " " << cnt;

	return 0;
}