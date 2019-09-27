#include <iostream>
#include <vector>
#include <map>
#include <cstring>
#include <algorithm>

#define FOR(i,n) for(int i=0;i<n;++i)

using namespace std;
int a[101][101], ta[101][101];

int r, c, k;
int rowC = 3, colC = 3;
int numCount[101];
int time = 0;

struct elem{
	int n, c;
	bool operator <(const elem& o)const{
		if (c == o.c)return n < o.n;
		return c < o.c;
	}
};

void printarray(){
	cout << "\n";
	for (int i = 0; i < rowC; i++){
		for (int j = 0; j < colC; j++){
			cout << a[i][j] << " ";
		}
		cout << "\n";
	}
	cout << "\n";
}


void solveR(){
	memset(ta, 0, sizeof(ta));
	int h = rowC, w = colC, tcolC = 0;
	FOR(i, h){
		map <int, int> m;
		vector <elem> v;
		FOR(j, w) if (a[i][j] != 0) m[a[i][j]]++;
		map <int, int>::iterator it;
		for (it = m.begin(); it != m.end(); it++){
			v.push_back({(*it).first,(*it).second});
		}
		sort(v.begin(),v.end());
		vector <elem>::iterator itv;
		int k=0;
		for (itv = v.begin(); itv != v.end(); itv++){
			if (k < 100) ta[i][k++] = (*itv).n;
			if (k < 100) ta[i][k++] = (*itv).c;
		}
		tcolC=max(tcolC, k);

	}
	colC = tcolC;
	memcpy(a, ta, sizeof(ta));
}

void solveC(){
	memset(ta, 0, sizeof(ta));
	int h = rowC, w = colC, trowC = 0;
	FOR(i, w){
		map <int, int> m;
		vector <elem> v;
		FOR(j, h) if (a[j][i] != 0) m[a[j][i]]++;
		map <int, int>::iterator it;
		for (it = m.begin(); it != m.end(); it++){
			v.push_back({ (*it).first, (*it).second });
		}
		sort(v.begin(), v.end());
		vector <elem>::iterator itv;
		int k = 0;
		for (itv = v.begin(); itv != v.end(); itv++){
			if (k < 100) ta[k++][i] = (*itv).n;
			if (k < 100) ta[k++][i] = (*itv).c;
		}
		
		trowC = max(trowC, k);
	}
	rowC = trowC;
	memcpy(a, ta, sizeof(ta));
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> r >> c >> k;

	FOR(i, 3) FOR(j, 3) cin >> a[i][j];

	while (a[r-1][c-1] != k){
		if (time > 100){
			time = -1; break;
		}
		time++;
		if (rowC >= colC){
			solveR();
		}
		else {
			solveC();
		}
	}
	cout << time;

	return 0;
}