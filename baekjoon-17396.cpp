#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int N, M; 
bool hasSight[100001];
vector<pair<int, int>> matrix[100001];
long long dist[100001];

void dijkstra()
{
	fill(dist, dist + N, (long long)1e16);
	priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;
	pq.push({0, 0});
	dist[0] = 0;

	while(!pq.empty())
	{
		auto [cost, cur] = pq.top(); pq.pop();
		if(dist[cur] < cost) continue;

		for(auto [next, edgeCost] : matrix[cur])
		{
			long long newCost = cost + edgeCost;
			if(dist[next] <= newCost) continue;
			pq.push({newCost, next});
			dist[next] = newCost;
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> N >> M;
	for(int i = 0; i < N; i++)
		cin >> hasSight[i];
	hasSight[N - 1] = false;
	
	for(int i = 0; i < M; i++)
	{
		int a, b, c; cin >> a >> b >> c;
		if(hasSight[a] || hasSight[b]) continue;
		matrix[a].push_back({b, c});
		matrix[b].push_back({a, c});
	}

	dijkstra();

	cout << (dist[N - 1] == (long long)1e16 ? -1 : dist[N - 1]);
	return 0;
}