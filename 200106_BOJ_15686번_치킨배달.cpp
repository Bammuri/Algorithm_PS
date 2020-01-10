#include <iostream>
#include <vector>

#define FOR(i,n) for(int i=0;i<n;i++)
using namespace std;

int N, M, answer = 1987654321;
int map[51][51];
int remap[51][51];
int check[13];
int chSize = 0;

struct lo {
	int x, y;
};

vector <lo> ch;
vector<lo> ho;
vector <lo> choose;

void go() {
	int sum = 0, lomin;
	//cout << "start\n";
	for (auto hpa : ho) {
		lomin = 1000;
		for (auto pa : choose) {
			int re = abs(hpa.x - pa.x) + abs(hpa.y - pa.y);
			if (lomin > re ) {
				lomin = re;
			}
			
		}
		//cout << lomin << "\n";
		sum += lomin;
	}
	if (answer > sum)
		answer = sum;

}

void dfs(int d,int idx) {
	if (d == M) {

		go();
		return;
	}

	for (int i = idx; i < chSize; i++) {
	
		//cout << "i" << i <<"sh"<<chSize<< "\n";

		choose.push_back({ ch[i].x,ch[i].y });
		dfs(d + 1,i+1);
		choose.pop_back();


	}

}

int main() {
	cin >> N >> M;
	
	FOR(i, N) {
		FOR(j, N) {
			cin >> map[i][j];

			if (map[i][j] == 2)
				ch.push_back({ i,j });
			else if(map[i][j] == 1)
				ho.push_back({ i,j });
		}
	}
	chSize = ch.size();

	dfs(0,0);

	cout << answer;



	return 0;
}