#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int N, M;
int indegree[1001];
int ans[1001];
vector<int> matrix[1001];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> N >> M;
	for(int i = 0; i < M; i++)
	{
		int a, b; cin >> a >> b;
		matrix[a].push_back(b);
		indegree[b]++;
	}

	queue<int> Q;
	for(int i = 1; i <= N; i++)
	{
		if(indegree[i] == 0)
			Q.push(i);
	}

	while(!Q.empty())
	{
		int cur = Q.front(); Q.pop();
		for(int next : matrix[cur])
		{
			if(--indegree[next] == 0)
			{
				Q.push(next);
				ans[next] = max(ans[next], ans[cur] + 1);
			}
		}
	}

	for(int i = 1; i <= N; i++)
	{
		cout << ans[i] + 1 << ' ';
	}
	return 0;
}