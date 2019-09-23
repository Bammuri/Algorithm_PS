#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<int> &num) {
	int len = num.size();
	vector <pair<int, int> > can(len);
	
	int lmax = -1987654321;
	int rmin = 1987654321;

	for (int i = 0; i < len; i++) {
		lmax = max(lmax, num[i]);
		can[i].first = lmax;
	}

	for (int i = len-1; i >= 0 ; i--) {
		rmin = min(rmin, num[i]);
		can[i].second = rmin;
	}

	for (int i = 0; i < len - 1; i++) {
		if (can[i].first < can[i + 1].second) return i + 1;
	}

	return len;


}


int main() {
	//N 2~300,000
	int N;
	scanf_s("%d", &N);
	vector<int> num(N);
	for (int i = 0; i < N; i++)
		scanf_s("%d", &num[i]);

	printf("%d", solution(num));

	return 0;
}