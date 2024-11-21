#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

constexpr int MAX_N = 11;

int N, M;
vector<pair<int, int>> matrix[MAX_N];
int dist[MAX_N];

void dijkstra()
{
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	fill(dist, dist + MAX_N, 1e9);
	dist[1] = 0;
	pq.push({0, 1});

	while(!pq.empty())
	{
		auto [cost, cur] = pq.top(); pq.pop();

		if(dist[cur] < cost) continue;

		for(auto [next, edge] : matrix[cur])
		{
			int newDist = cost + edge;
			if(dist[next] <= newDist) continue;
			pq.push({newDist, next});
			dist[next] = newDist;
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	
	cin >> N >> M;
	for(int i = 0; i < M; i++)
	{
		int a, b, c; cin >> a >> b >> c;
		matrix[a].push_back({b, c});
		matrix[b].push_back({a, c});
	}

	dijkstra();

	cout << dist[N];
	return 0;
}