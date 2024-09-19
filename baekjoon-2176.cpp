#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <queue>
#include <cmath>

using namespace std;

constexpr int INF = 2e9;

int N, M;

vector<pair<int, int>> matrix[1001];
int distFromDest[1001];
int dp[1001];
bool isInQueue[1001];

void calcDistFromDest()
{
	fill(distFromDest, distFromDest + 1001, INF);
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	pq.push({0, 2});
	distFromDest[2] = 0;

	while(!pq.empty())
	{
		auto [cost, cur] = pq.top(); pq.pop();
		if(distFromDest[cur] < cost) continue;

		for(auto [next, edgeCost] : matrix[cur])
		{
			int newCost = cost + edgeCost;
			if(distFromDest[next] <= newCost) continue;
			pq.push({newCost, next});
			distFromDest[next] = newCost;
		}
	}
}

void countRoutes()
{
	priority_queue<pair<int, int>> pq;
	pq.push({distFromDest[1], 1});
	dp[1] = 1;
	isInQueue[1] = true;

	while(!pq.empty())
	{
		auto [cost, cur] = pq.top(); pq.pop();

		for(auto [next, edgeCost] : matrix[cur])
		{
			if(distFromDest[next] >= cost) continue;

			if(isInQueue[next] == false)
			{
				pq.push({distFromDest[next], next});
				isInQueue[next] = true;
			}
			dp[next] += dp[cur];
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> N >> M;
	for(int i = 0; i < M; i++)
	{
		int a, b, c; cin >> a >> b >> c;
		matrix[a].push_back({b, c});
		matrix[b].push_back({a, c});
	}

	calcDistFromDest();
	countRoutes();

	cout << dp[2];

	return 0;
}