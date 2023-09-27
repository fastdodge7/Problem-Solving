#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <queue>

using namespace std;

int N, M;

vector<int> matrix[101];
vector<vector<int>> groups;

int parent[101];

int Find(int a)
{
	if (parent[a] <= 0) return a;
	return parent[a] = Find(parent[a]);
}

void Union(int a, int b)
{
	a = Find(a);
	b = Find(b);

	if (a == b) return;
	parent[b] = a;
}

void initGroups(int start)
{
	bool visited[101] = { false, };
	queue<int> Q; Q.push(start);
	visited[start] = true;

	groups.push_back({});
	vector<int>& newGroup = groups[groups.size() - 1];

	while (!Q.empty())
	{
		int cur = Q.front(); Q.pop();
		newGroup.push_back(cur);
		for (int nxt : matrix[cur])
		{
			if (visited[nxt]) continue;
			visited[nxt] = true;
			Q.push(nxt);
		}
	}
}

int calcMaxTime(int headId)
{
	bool visited[101] = { false, };
	queue<pair<int, int>> Q; Q.push({ headId, 0 });
	visited[headId] = true;

	int ret = 0;
	while (!Q.empty())
	{
		auto cur = Q.front(); Q.pop();
		ret = cur.second;
		for (int nxt : matrix[cur.first])
		{
			if (visited[nxt]) continue;
			visited[nxt] = true;
			Q.push({ nxt, cur.second + 1 });
		}
	}
	return ret;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> N >> M;
	for (int i = 0; i < M; i++)
	{
		int a, b; cin >> a >> b;
		matrix[a].push_back(b);
		matrix[b].push_back(a);
		Union(a, b);
	}

	for (int i = 1; i <= N; i++)
	{
		if (parent[i] <= 0)
			initGroups(i);
	}

	vector<int> ans;
	for (vector<int>& group : groups)
	{
		int head = -1;
		int minMaxTime = 1e9;
		for (int headCand : group)
		{
			int maxTime = calcMaxTime(headCand);
			if (maxTime < minMaxTime)
			{
				head = headCand;
				minMaxTime = maxTime;
			}
		}
		ans.push_back(head);
	}

	sort(ans.begin(), ans.end());

	cout << ans.size() << '\n';
	for (int head : ans)
		cout << head << '\n';

	return 0;
}