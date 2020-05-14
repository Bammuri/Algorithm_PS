//1218
//1250 초안완성 
//1309 TC AC -> AC , vec_idx<vec.size(), operator 정의, 0 제외 
#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

int r, c, k,sizeR = 3,sizeC = 3 ;
int A[100][100],tmp[100][100];
typedef struct lo{
	int cnt, num;
	bool operator < (const lo &o)const {
		if (cnt == o.cnt)
			return num < o.num;
		return cnt < o.cnt;
	}
};


void calcul(){
	memset(tmp, 0, sizeof(tmp));
	if (sizeR >= sizeC){
		// 행에 대해서 수행
		int mx = 0;
		for (int i = 0; i < sizeR; i++){
			
			map <int, int> m;
			for (int j = 0; j < sizeC; j++)
				if (A[i][j] != 0)
					m[A[i][j]]++;

			vector<lo> vec;
			map <int, int>::iterator iter;

			for (iter = m.begin(); iter != m.end(); iter++)
				vec.push_back({ iter->second, iter->first });
			
			sort(vec.begin(), vec.end());
			int vec_idx = 0;
			int j;
			for (j = 0; j < 100, vec_idx<vec.size();){
				tmp[i][j++] = vec[vec_idx].num;
				tmp[i][j++] = vec[vec_idx].cnt;
				vec_idx++;
			}
			if (mx < j)
				mx = j;
		}
		sizeC = mx;// 행의 크기가 열의 갯수
	}
	else {
		// 열에 대해서 수행
		int mx = 0;
		for (int i = 0; i < sizeC; i++){

			map <int, int> m;
			for (int j = 0; j < sizeR; j++)
				if (A[j][i] != 0)
					m[A[j][i]]++;

			vector<lo> vec;
			map <int, int>::iterator iter = m.begin();

			for (iter = m.begin(); iter != m.end(); iter++)
				vec.push_back({ iter->second, iter->first });

			sort(vec.begin(), vec.end());
			int vec_idx = 0;
			int j;
			for (j = 0; j < 100, vec_idx<vec.size();){
				tmp[j++][i] = vec[vec_idx].num;
				tmp[j++][i] = vec[vec_idx].cnt;
				vec_idx++;
			}
			if (mx < j)
				mx = j;
		}
		sizeR = mx;// 열의 크기가 행의 갯수
	}
	memcpy(A, tmp, sizeof(A));

}


void printA(){
	cout << "\n";
	for (int i = 0; i < sizeR; i++){
		for (int j = 0; j < sizeC; j++){
			cout<< A[i][j]<<" ";
		}
		cout << "\n";
	}
}

int sol()
{
	int ans = 0;

	while (A[r-1][c-1] != k)
	{
		calcul();
		ans++;
		if (ans > 100)return -1;
		//printA();
	}
	return ans;

}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> r >> c >> k;

	for (int i = 0; i < sizeR; i++){
		for (int j = 0; j < sizeC; j++){
			cin >> A[i][j];
		}
	}

	cout<<sol();


	return 0;
}