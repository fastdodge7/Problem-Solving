#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <deque>
#include <cassert>
#include <queue>

using namespace std;

constexpr int BLACK = 0;
constexpr int GRAY = 1;
constexpr int WHITE = 2;

int N, M, K;
vector<int> initTargets;
int visited[200001];
vector<int> matrix[200001];
int deleted[200001];


// 중복간선 처리만 잘 하면 된다!
int BFS()
{
	queue<pair<int, int>> Q;
	for(int tar : initTargets)
	{
		Q.push({tar, 1});
		deleted[tar] = 1;
	}

	int ret = 1;
	while(!Q.empty())
	{
		auto [node, dist] = Q.front(); Q.pop();
		ret = dist;
		for(int next : matrix[node])
		{
			if(deleted[next] > 0) continue;
			deleted[next] = dist + 1;
			Q.push({next, dist + 1});
		}
	}

	return ret;
}

bool DFS(int parent, int cur, const int t)
{
	if(visited[cur] != BLACK) return false;
	if(deleted[cur] <= t) return false;
	visited[cur] = GRAY;

	bool ret = false;
	int parentCount = 0;
	for(int next : matrix[cur])
	{
		if(next == parent && parentCount == 0)
		{
			parentCount++;
			continue;
		} 
		if(next == parent && parentCount == 1)
			return true;
		if(deleted[next] <= t) continue;
		if(visited[next] == WHITE) continue;
		if(visited[next] == GRAY) return true;

		if(DFS(cur, next, t) == true) return true; 
	}
	visited[cur] = WHITE;
	return false;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> N >> M >> K;
	for(int i = 0; i < M; i++)
	{
		int a, b; cin >> a >> b;
		matrix[a].push_back(b);
		matrix[b].push_back(a);
	}
	for(int i = 0; i < K; i++)
	{
		int a; cin >> a;
		initTargets.push_back(a);
	}

	int left = 0, right = BFS() + 1;
	while(left + 1 < right)
	{
		fill(visited, visited + 200001, BLACK);
		int mid = (left + right) / 2;
		bool flag = false;
		for(int i = 1; i <= N; i++)
		{
			if(DFS(0, i, mid))
			{
				//cout << "CYCLE EXIST!!" << " MID : " << mid << '\n';
				flag = true;
				break;
			}
		}
		if(flag)
			left = mid;
		else
			right = mid;
	}

	cout << right;
	return 0;
}