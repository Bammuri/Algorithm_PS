#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
#include <functional>
#include <cstring>
using namespace std;

#define FOR(i,n) for(int i=0;i<n;++i)

int m[101][101];
int m1[101][101];

struct elem{
	int n, f;
	bool operator <(const elem& o)const {
		if (f == o.f )return n < o.n;
		return f < o.f;
	}
};

void printm(){
	FOR(i, 101){
		FOR(j, 101)cout << m[i][j];
		cout << "\n";
	}
}

int solve(int y, int x, int goal){
	int ans = 0, h = 3, w = 3;
	while (m[y][x] != goal){
		if (++ans > 100)return -1;

		memset(m1, 0, sizeof(m1));
		int ph = h, pw = w;

		if (ph >= pw){
			int tw = 0;
			FOR(i, ph){
				map<int, int, greater<int>> fq;
				vector <elem> v;
				FOR(j, pw)if (m[i][j] != 0)fq[m[i][j]]++;
				map <int, int>::iterator it;
				for (it = fq.begin(); it != fq.end(); it++){
					v.push_back({ (*it).first, (*it).second });
				}
				sort(v.begin(), v.end());
				int k = 0;
				vector <elem>::iterator itv;
				for (itv = v.begin(); itv != v.end(); itv++){
					if (k < 100) m1[i][k++] = (*itv).n;
					if (k < 100) m1[i][k++] = (*itv).f;
				}
				while (k > 0 && m1[i][k - 1] == 0)k--;
				tw = max(tw, min(100, k));
			}
			w = tw;
		}
		else {
			int th = 0;
			FOR(i, pw){
				map<int, int>fq;
				vector <elem> v;
				FOR(j, ph) if (m[j][i] != 0)fq[m[j][i]]++;
				map<int, int>::iterator it;
				for (it = fq.begin(); it != fq.end(); it++){
					v.push_back({ (*it).first, (*it).second });
				}
				sort(v.begin(), v.end());
				vector <elem>::iterator itv;
				int k = 0;
				for (itv = v.begin(); itv != v.end(); itv++){
					if (k < 100) m1[k++][i] = (*itv).n;
					if (k < 100)m1[k++][i] = (*itv).f;
				}
				while (k > 0 && m1[k - 1][i] == 0)k--;
				th = max(th, min(100, k));
			}
			h = th;
		}
		memcpy(m, m1, sizeof(m1));
	}
	return ans;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int r, c, k;
	cin >> r >> c >> k;
	FOR(i, 3) FOR(j, 3) cin >> m[i][j];
	cout << solve(r - 1, c - 1, k);
	
	return 0;
} 