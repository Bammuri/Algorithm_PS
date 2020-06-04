//1058 
//1151 AC
#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;

int R, C, N;
char ground[200][201], ground_before[200][201];
int dx[] = { 1, 0, -1, 0 };
int dy[] = { 0, 1, 0, -1 };

typedef struct lo{
	int x, y;
};



vector <vector <lo> > bamvec;

void print_ground()
{
	//cout << "\n";
	for (int i = 0; i < R; i++){
		cout<< ground[i]<<"\n";
	}
}


void bammmm(lo t)
{
	
	int x = t.x;
	int y = t.y;
	ground[x][y] = '.';
	//cout << x << " " << y << "\n";
	for (int i = 0; i < 4; i++)
	{
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (nx >= R || nx < 0 || ny >= C || ny < 0)continue;
		ground[nx][ny] = '.';
	}

}
void set_bam(){
	vector <lo> vec;

	for (int i = 0; i < R; i++){
		for (int j = 0; j < C; j++){
			
			if (ground[i][j] == '.'){
				ground[i][j] = 'O';
				vec.push_back({ i, j });
			}
		}
	}
	bamvec.push_back(vec);
}

void sol()
{
	int time = 1;
	while (time < N)
	{
		if (time % 2){
			set_bam();
		}
		else if (time % 2 == 0)
		{
			//cout << bamvec[0].size();

			for (int i = 0; i < bamvec[0].size(); i++)
			{
				if (ground_before[bamvec[0][i].x][bamvec[0][i].y] == 'O')
					bammmm(bamvec[0][i]);
			}
			memcpy(ground_before, ground, sizeof(ground));
			bamvec.erase(bamvec.begin());
		}
		
		//print_ground();
		time++;
	}

}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> R >> C >> N;
	vector <lo> vec;

	for (int i = 0; i < R; i++){
		for (int j = 0; j < C; j++){
			cin >> ground[i][j];
			if (ground[i][j] == 'O')
				vec.push_back({ i, j });
		}
	}
	memcpy(ground_before, ground, sizeof(ground));
	bamvec.push_back(vec);
	//cout<<bamvec.size();
	sol();
	print_ground();
	return 0;

}