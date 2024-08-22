#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <queue>

using namespace std;

typedef struct Node{
	long long nodeId;
	long long cnt;
	long long distance;

	bool operator>(const Node& other) const {
		return distance > other.distance;
	}
}Node;

int N, M, K;
vector<pair<int, int>> matrix[10001];
long long dist[10001][21];

long long dijkstra()
{
	fill(&dist[0][0], &dist[10000][20] + 1, 1e16);
	priority_queue<Node, vector<Node>, greater<Node>> pQ; pQ.push({1, 0, 0});
	dist[1][0] = 0;

	while(!pQ.empty())
	{
		auto [curNode, curCnt, curDist] = pQ.top(); pQ.pop();
		if(curDist > dist[curNode][curCnt]) continue;

		for(auto [next, cost] : matrix[curNode])
		{
			if(curCnt < K)
			{
				if(curDist < dist[next][curCnt + 1])
				{
					dist[next][curCnt + 1] = curDist;
					pQ.push({next, curCnt + 1, dist[next][curCnt + 1]});
				}
			}

			if(curDist + cost >= dist[next][curCnt]) continue;

			dist[next][curCnt] = curDist + cost;
			pQ.push({next, curCnt, dist[next][curCnt]});
		}
	}

	long long ans = 1e16;
	for(int i = 0; i <= K; i++)
		ans = min(ans, dist[N][i]);
	
	return ans;
}


int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> N >> M >> K;
	for(int i = 0; i < M; i++)
	{
		int a, b, c; cin >> a >> b >> c;
		matrix[a].push_back({b, c});
		matrix[b].push_back({a, c});
	}

	cout << dijkstra();

	return 0;
}