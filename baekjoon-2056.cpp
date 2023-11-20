#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int N;
int timeCost[10001];
int maxPreRequired[10001];
int visited[10001];
vector<int> matrix[10001];

int BFS()
{
	queue<pair<int, int>> Q;
	for(int i = 1; i <= N; i++)
	{
		if(visited[i] == 0)
			Q.push({i, timeCost[i]});
	}

	int ans = 0;
	while(!Q.empty())
	{
		int cur = Q.front().first; 
		int curTime = Q.front().second; Q.pop();
		ans = max(ans, curTime);
		for(int next : matrix[cur])
		{
			maxPreRequired[next] = max(maxPreRequired[next], curTime);
			if(--visited[next] == 0)
				Q.push({next, maxPreRequired[next] + timeCost[next]});
		}
	}

	return ans;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> N;
	for(int i = 1; i <= N; i++)
	{
		int cost, cnt; cin >> cost >> cnt;
		visited[i] = cnt;
		timeCost[i] = cost;
		for(int j = 0; j < cnt; j++)
		{
			int pre; cin >> pre;
			matrix[pre].push_back(i);
		}
	}
	cout << BFS();
	return 0;
}