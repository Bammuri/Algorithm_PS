#include <iostream>
#include <algorithm>
using namespace std;

int gN, gM;
int S[20];

int recur(int idx, int M, int Ssum) {
	if (idx == gN) 
		return Ssum;
	
	if (M > 0) {
		if (M == gM)
			return max(recur(idx + 1, M - 1, Ssum + S[idx]), recur(idx + 1, M, Ssum));
		return max(recur(idx + 1, M - 1, Ssum + S[idx]), recur(idx + 1, M + 1, Ssum));
	}

	if (M == gM)
		return recur(idx + 1, M, Ssum);
	return recur(idx + 1, M + 1, Ssum);
}

int main() {

	cin >> gN >> gM;
	
	for (int i = 0; i < gN; i++)
		cin >> S[i];
	
	cout<<recur(0, gM, 0);

	return 0;
}