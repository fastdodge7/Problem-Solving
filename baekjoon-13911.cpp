#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int V, E;
int dist[10001][2];
vector<pair<int, int>> matrix[10001];
int M, MLimit, S, SLimit;
vector<int> mcdonald, starbucks;

void dijkstra(const vector<int>& initList, int idx)
{
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	for(int m : initList)
	{
		pq.push({0, m});
		dist[m][idx] = 0;
	}
	
	while(!pq.empty())
	{
		const auto[dst, vertex] = pq.top(); pq.pop();
		if(dist[vertex][idx] < dst) continue;
		for(const auto& edge : matrix[vertex])
		{
			int newDist = dst + edge.second;
			if(dist[edge.first][idx] <= newDist) continue;
			pq.push({newDist, edge.first});
			dist[edge.first][idx] = newDist;
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	fill(&dist[0][0], &dist[10000][1] + 1, 1e9);
	cin >> V >> E;
	for(int i = 0; i < E; i++)
	{
		int u, v, w; cin >> u >> v >> w;
		matrix[u].push_back({v, w});
		matrix[v].push_back({u, w});
	}
	cin >> M >> MLimit;
	for(int i = 0; i < M; i++)
	{
		int tar; cin >> tar;
		mcdonald.push_back(tar);
	}
	cin >> S >> SLimit;
	for(int i = 0; i < S; i++)
	{
		int tar; cin >> tar;
		starbucks.push_back(tar);
	}

	dijkstra(mcdonald, 0);
	dijkstra(starbucks, 1);

	int ans = 1e9;
	for(int i = 1; i <= V; i++)
	{
		if(dist[i][0] == 0 || dist[i][1] == 0) continue;
		if(dist[i][0] > MLimit || dist[i][1] > SLimit) continue;
		ans = min(ans, dist[i][0] + dist[i][1]);
	}
	
	cout << (ans == (int)1e9 ? -1 : ans);
	return 0;
}