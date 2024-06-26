#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int N, P, K;
vector<pair<int, int>> matrix[1000];
int visited[1000][1000];
bool reachable = false;

typedef struct Node{
	int nodeNum;
	int maxCost;
	int skipCnt;
}Node;

bool check(int limitCost)
{
	fill(&visited[0][0], &visited[999][999] + 1, 1e9);
	queue<Node> Q; Q.push({0, 0, 0});
	visited[0][0] = 0;

	while(!Q.empty())
	{
		auto cur = Q.front(); Q.pop();
		for(auto [next, cost] : matrix[cur.nodeNum])
		{
			if(cost > limitCost)
			{
				if(K < cur.skipCnt + 1) continue;
				if(visited[next][cur.skipCnt + 1] <= cur.maxCost) continue;

				Q.push({next, cur.maxCost, cur.skipCnt + 1});
				visited[next][cur.skipCnt + 1] = cur.maxCost;
			}
			else
			{
				if(visited[next][cur.skipCnt] <= max(cur.maxCost, cost)) continue;
				Q.push({next, max(cur.maxCost, cost), cur.skipCnt});
				visited[next][cur.skipCnt] = cur.maxCost;
			}
		}
	}

	for(int i = 0; i <= K; i++)
	{
		if(visited[N - 1][i] <= limitCost)
			return true;
	}
	return false;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> N >> P >> K;
	for(int i = 0; i < P; i++)
	{
		int a, b, c; cin >> a >>b >> c;
		a--; b--;
		matrix[a].push_back({b, c});
		matrix[b].push_back({a, c});
	}

	int left = -1, right = 1e6 + 1;
	while(left + 1 < right)
	{
		int mid = (left + right) / 2;
		if(check(mid))
		{
			right = mid;
			reachable = true;
		}
		else
			left = mid;
	}

	cout << (reachable ? right : -1) << '\n';
	return 0;
}