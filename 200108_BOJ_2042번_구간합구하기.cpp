#include<iostream>
#include<cmath>
using namespace std;

long long a, b, c,ans;
long long N, M, K, h, tree_size;
long long arr[3000001];



void getidxtree() {
	long long tmp = tree_size/2;
	while (tmp!=1) {
		for (int i = tmp; i < tmp + tmp; i++) {
			arr[i / 2] += arr[i];
		}
		tmp /= 2;
	}

}


void change(int where,int what) {
	arr[where-1 + tree_size/2]= what;

	long long tmp = where - 1 +tree_size/2;
	while (tmp != 1) {
		if (tmp % 2 == 0) {
			arr[tmp / 2] = arr[tmp] + arr[tmp + 1];
		}
		else {
			arr[tmp / 2] = arr[tmp-1] + arr[tmp];
		}
		tmp /= 2;
	}

}

long long getsum(int st,int ed,int inx,int s,int e) {

	if (st <= s && e <= ed)
		return arr[inx];
	if (ed < s || e < st) 
		return 0;


	int m = (s + e) / 2;
	return getsum(st, ed, inx * 2, s, m) + getsum(st, ed, inx * 2 + 1, m + 1, e);
}

void printarr() {
	for (int i = 0; i < tree_size; i++) {
		cout<<arr[i]<<" ";
	}
	cout << "\n";
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> N >> M >> K;

	int h = (int)ceil(log2(N));
	tree_size = (1 << (h + 1));
	//cout << tree_size << "\n";
	for (int i = 0; i < N; i++) {
		cin >> arr[i + tree_size/2];
	}
	//printarr();
	
	getidxtree();
	//printarr();
	for (int i = 0; i < M + K; i++) {
		cin >> a >> b >> c;

		if (a == 1) {
			change(b,c);
		}
		else if(a==2) {
			cout<<getsum(b,c,1,1, tree_size/2)<<"\n";
		}
		//printarr();
	}
	return 0;
}
