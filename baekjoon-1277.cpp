#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <queue>

using namespace std;

int N, W;
double lim;
int position[1001][2];
double dist[1001];
double matrix[1001][1001];

void dijkstra()
{
	priority_queue<pair<double, int>, vector<pair<double, int>>, greater<pair<double, int>>> pq;
	fill(dist, dist + 1001, (double)1e9);
	dist[1] = 0.0;
	pq.push({ 0.0, 1 });
	while (!pq.empty())
	{
		auto cur = pq.top(); pq.pop();
		int curNode = cur.second;
		double cost = cur.first;

		if (cost > dist[curNode]) continue;
		for (int next = 1; next <= N; next++)
		{
			if (curNode == next) continue;
			double newCost = cost + matrix[curNode][next];
			if (dist[next] <= newCost) continue;
			dist[next] = newCost;
			pq.push({ newCost, next });
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> N >> W >> lim;
	for (int i = 1; i <= N; i++)
		cin >> position[i][1] >> position[i][0];

	fill(&matrix[1][1], &matrix[1000][1000] + 1, (double)1e9);
	for (int i = 1; i < N; i++)
	{
		for (int j = i + 1; j <= N; j++)
		{
			long long dy = abs(position[i][0] - position[j][0]);
			long long dx = abs(position[i][1] - position[j][1]);
			double dst = sqrt(dy * dy + dx * dx);
			if (dst > lim) continue;
			matrix[i][j] = matrix[j][i] = dst;
		}
	}

	for (int i = 0; i < W; i++)
	{
		int a, b; cin >> a >> b;
		matrix[a][b] = matrix[b][a] = 0;
	}
	dijkstra();
	cout << (int)(dist[N] * 1000) << '\n';
	return 0;
}