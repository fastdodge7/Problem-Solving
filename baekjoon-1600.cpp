#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <queue>

using namespace std;

constexpr int INF = 1e9;

int dy[12] = { -1, -2, -2, -1, 1, 2, 2, 1, 0, -1, 0, 1 };
int dx[12] = { -2, -1, 1, 2, 2, 1, -1, -2, -1, 0, 1, 0 };

int W, H, K;
int board[200][200];
int dp[200][200][31];

typedef struct Node {
	int r, c;
	int rest;
	int cnt;
}Node;

int BFS()
{
	queue<Node> Q; Q.push({ 0, 0, K, 0 });
	while (!Q.empty())
	{
		auto cur = Q.front(); Q.pop();

		if (cur.r == H - 1 && cur.c == W - 1) return dp[cur.r][cur.c][cur.rest];
		for (int i = 0; i < 12; i++)
		{
			int nr = cur.r + dy[i];
			int nc = cur.c + dx[i];
			if (nr < 0 || nr >= H || nc < 0 || nc >= W) continue;
			if (board[nr][nc] == 1) continue;
			if (i < 8 && cur.rest <= 0) continue;

			int rst = (i < 8) ? cur.rest - 1 : cur.rest;
			if (dp[nr][nc][rst] <= cur.cnt + 1) continue;

			dp[nr][nc][rst] = cur.cnt + 1;
			Q.push({ nr, nc, rst, cur.cnt + 1 });
		}
	}
	return -1;
}


int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> K >> W >> H;

	fill(&dp[0][0][0], &dp[199][199][30] + 1, INF);
	dp[0][0][K] = 0;

	for (int i = 0; i < H; i++) for (int j = 0; j < W; j++)
		cin >> board[i][j];

	cout << BFS() << '\n';

	return 0;
}