#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int N, M;
int dist[1001];
int before[1001];
vector<pair<int, int>> matrix[1001];

vector<pair<int, int>> extractRoute()
{
	vector<pair<int, int>> route;
	int cur = N;
	while(before[cur] > 0)
	{
		route.push_back({cur, before[cur]});
		cur = before[cur];
	}
	return route;
}

int dijkstra(const pair<int, int>& restrictedRoad)
{
	fill(&dist[0], &dist[N] + 1, 1e9);
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pQ; 
	pQ.push({0, 1});
	dist[1] = 0;

	while(!pQ.empty())
	{
		auto [cost, node] = pQ.top(); pQ.pop();

		if(cost > dist[node]) continue;

		if(node == N) return dist[node];

		for(const auto&[nextNode, edgeCost] : matrix[node])
		{
			if(restrictedRoad == make_pair(node, nextNode) || restrictedRoad == make_pair(nextNode, node) ) continue;
			if(dist[nextNode] <= cost + edgeCost) continue;
			
			dist[nextNode] = cost + edgeCost;
			pQ.push({dist[nextNode], nextNode});
			before[nextNode] = node;
		}
	}

	return 1e9;
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

	int minCost = dijkstra({0, 0});

	vector<pair<int, int>> route = extractRoute();

	int afterRestrict = -1;
	for(const auto& road : route)
	{
		afterRestrict = max(afterRestrict, dijkstra(road));
	}

	cout << (afterRestrict == 1e9 ? -1 : afterRestrict - minCost);

	return 0;
}