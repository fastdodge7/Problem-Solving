#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
using namespace std;

int N, M;
vector<pair<int, int>> matrix[1001];
bool visited[1001];

int BFS(int start, int target)
{
	fill(visited, visited + 1001, false);
	visited[start] = true;
	queue<pair<int, int>> Q; Q.push({start, 0});
	
	while(!Q.empty())
	{
		pair<int, int> cur = Q.front(); Q.pop();
		if(cur.first == target) return cur.second;
		for(auto p : matrix[cur.first])
		{
			if(visited[p.first]) continue;
			visited[p.first] = true;
			Q.push({p.first, cur.second + p.second});
		}
	}
}

int main() {
	// your code goes here
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	
	cin >> N >> M;
	for(int i = 0; i < N - 1; i++)
	{
		int a, b, c; cin >> a >> b >> c;
		matrix[a].push_back({b, c});
		matrix[b].push_back({a, c});
	}
	for(int i = 0; i < M; i++)
	{
		int a, b;cin >> a >> b;
		cout << BFS(a, b) << '\n';
	}
	
	return 0;
}