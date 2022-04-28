#include <vector>
#include <queue>
#include <unordered_set>
using namespace std;

class Solution {
public:
	int distance(const vector<int>& point1, const vector<int>& point2) {
		return abs(point1[0] - point2[0]) + abs(point1[1] - point2[1]);
	}
	int minCostConnectPoints(const vector<vector<int>>& points) {
		int total = 0;
		
		priority_queue<pair<int, int>> pq;
		pq.push({ 0, 0 });
		
		unordered_set<int> visited;

		while (!pq.empty()) {
			pair<int,int> curr = pq.top();
			pq.pop();
			if (visited.find(curr.second) != visited.end())
				continue;
			total -= curr.first;
			visited.insert(curr.second);
			for (int i = 0; i < points.size(); i++) {
				if (i != curr.second && visited.find(i) == visited.end()) {
					pq.push({ -distance(points[curr.second], points[i]), i });
				}
			}
		}
		return total;
	}
};