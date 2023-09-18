#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <queue>

using namespace std;

int N, M;
vector<pair<int ,int>> matrix[10001];
int visited[10001];

bool BFS(int start, int target, int lim)
{
	fill(visited, visited + 10001, 0);
	queue<pair<int, int>> Q; Q.push({ start, 1e9 });
	visited[start] = 1e9;
	while (!Q.empty())
	{
		auto cur = Q.front(); Q.pop();

		for (auto next : matrix[cur.first])
		{
			int limit = min(cur.second, next.second);
			if (limit < lim) continue;
			if (next.first == target) return true;
			if (!visited[next.first])
			{
				visited[next.first] = 1;
				Q.push({ next.first, limit });
			}
		}
	}
	return false;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> N >> M;
	for (int i = 0; i < M; i++)
	{
		int a, b, c; cin >> a >> b >> c;
		matrix[a].push_back({ b, c });
		matrix[b].push_back({ a, c });
	}
	int start, end; cin >> start >> end;


	int left = 0; int right = 1e9;
	while (left <= right)
	{
		int mid = (left + right) / 2;
		if (BFS(start, end, mid))
			left = mid + 1;
		else
			right = mid - 1;
	}


	cout << right << '\n';

	return 0;
}