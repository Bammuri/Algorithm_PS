#include<cstdio>
#include<queue>
using namespace std;
int C, B;

int main() {
	scanf_s("%d%d", &C, &B);

	int time = 0;
	bool visit[200001][2];
	queue<pair<int, int> >queue;

	memset(visit, 0, sizeof(visit));
	queue.push(make_pair(B,0));


	while (1) {

		C += time;

		if (C > 200000) {
			printf("-1");
			return 0;
		}

		if (visit[C][time % 2]) {
			printf("%d", time);
			return 0;
		}
			
		
		for (int i = 0, size = queue.size(); i < size; i++) {
			int currentPosition = queue.front().first;
			int newTime = (queue.front().second + 1) % 2;
			int newPosition;

			queue.pop();

			newPosition = currentPosition - 1;
			if (newPosition >= 0 && !visit[newPosition][newTime]) {
				visit[newPosition][newTime] = true;
				queue.push(make_pair(newPosition, newTime));
			}

			newPosition = currentPosition + 1;
			if (newPosition < 200001 && !visit[newPosition][newTime]) {
				visit[newPosition][newTime] = true;
				queue.push(make_pair(newPosition, newTime));
			}

			newPosition = currentPosition * 2;
			if (newPosition < 200001 && !visit[newPosition][newTime]) {
				visit[newPosition][newTime] = true;
				queue.push(make_pair(newPosition, newTime));
			}
		}
		time++;
	}

	printf("-1");
	return 0;
}