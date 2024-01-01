#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int N, M;
int parent[1001];
vector<pair<int, int>> matrix[1001];
int visited[1001];
int beforeNode[1001];
bool isConnected[1001][1001];

void dijkstra()
{
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	fill(visited, visited + 1001, 1e9);
	fill(beforeNode, beforeNode + 1001, 0);
	pq.push({0, 1});
	visited[1] = 0;
	while(!pq.empty())
	{
		auto cur = pq.top(); pq.pop();
		int node = cur.second;
		int cost = cur.first;
		
		if(visited[node] < cost) continue;
		
		for(auto edge : matrix[node])
		{
			int nextNode = edge.second;
			int edgeCost = edge.first;
			if(visited[nextNode] <= edgeCost + cost) continue;
			pq.push({edgeCost + cost, nextNode});
			visited[nextNode] = edgeCost + cost;
			beforeNode[nextNode] = node;
		}
	}
	
	for(int i = 2; i <= N; i++)
		isConnected[i][beforeNode[i]] = true;
}


int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	
	cin >> N >> M;
	for(int i = 0; i < M; i++)
	{
		int a, b, c; cin >> a >> b >> c;
		matrix[a].push_back({c, b});
		matrix[b].push_back({c, a});
	}
	
	dijkstra();
		
	cout << N - 1 << '\n';
	for(int i = 1; i <= N; i++)
	{
		for(int j = 1; j <= N; j++)
		{
			if(isConnected[i][j])
				cout << i << ' ' << j << '\n';
		}
	}
	
	return 0;
}