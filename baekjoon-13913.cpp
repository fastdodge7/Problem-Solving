#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>

using namespace std;

int N, M;

typedef struct Node
{
	int cur;
	int cnt;
}Node;

int visited[200001];
int ans;
vector<int> ansLog;

void BFS(int start,	int target)
{
	queue<Node> Q; Q.push({ start, 0});
	visited[start] = -100;

	while (!Q.empty())
	{
		Node cur = Q.front(); Q.pop();
		if (cur.cur == target)
		{
			ans = cur.cnt;
			int c = cur.cur;
			while (visited[c] >= 0)
			{
				ansLog.push_back(c);
				c = visited[c];
			}
			ansLog.push_back(start);
			reverse(ansLog.begin(), ansLog.end());
			return;
		}
		if (cur.cur + 1 <= 100000 && visited[cur.cur + 1] == -1)
		{
			visited[cur.cur + 1] = cur.cur;
			Q.push({ cur.cur + 1, cur.cnt + 1});
		}
		if (cur.cur - 1 >= 0 && visited[cur.cur - 1] == -1)
		{
			visited[cur.cur - 1] = cur.cur;
			Q.push({ cur.cur - 1, cur.cnt + 1});
		}
		if (cur.cur * 2 <= 200000 && visited[cur.cur * 2] == -1)
		{
			visited[cur.cur * 2] = cur.cur;
			Q.push({ cur.cur * 2, cur.cnt + 1});
		}
	}

}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	fill(visited, visited + 200001, -1);
	cin >> N >> M;

	BFS(N, M);

	cout << ans << '\n';
	for (int c : ansLog)
		cout << c << ' ';
	return 0;
}