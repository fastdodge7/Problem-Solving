#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <queue>

using namespace std;

int dp[2001][2001];

typedef struct Node {
	int number;
	int clipboard;
	int cnt;
}Node;

int BFS(int target)
{
	if (target == 1) return 0;

	queue<Node> Q; Q.push({ 1, 1, 1 });
	dp[1][1] = 1;

	while (!Q.empty())
	{
		auto cur = Q.front(); Q.pop();
		if (cur.number == target) return cur.cnt;

		Node paste = { cur.number + cur.clipboard, cur.clipboard, cur.cnt + 1 };
		if (paste.number > 2000) continue;
		if (dp[paste.number][paste.clipboard] > paste.cnt)
		{
			Q.push(paste);
			dp[paste.number][paste.clipboard] = paste.cnt;
		}

		Node copy = { cur.number, cur.number, cur.cnt + 1 };
		if (copy.number > 2000) continue;
		if (dp[copy.number][copy.clipboard] > copy.cnt)
		{
			Q.push(copy);
			dp[copy.number][copy.clipboard] = copy.cnt;
		}

		Node deletion = { cur.number - 1, cur.clipboard, cur.cnt + 1 };
		if (deletion.number <= 0) continue;
		if (dp[deletion.number][deletion.clipboard] > deletion.cnt)
		{
			Q.push(deletion);
			dp[deletion.number][deletion.clipboard] = deletion.cnt;
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n; cin >> n;

	fill(&dp[1][1], &dp[2000][2000], 1e9);
	cout << BFS(n);

	return 0;
}