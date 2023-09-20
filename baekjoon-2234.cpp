#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <queue>

using namespace std;

int dy[4] = { 0, -1, 0, 1 };
int dx[4] = { -1, 0, 1, 0 };
int bits[4] = { 1, 2, 4, 8 };

int N, M;
int board[50][50];
int visited[50][50];

int ans[3];

typedef struct Node {
	int r, c;
}Node;

int cnt[2501];

void BFS(int start, int end)
{
	if (visited[start][end]) return;
	ans[0]++;
	queue<Node> Q; Q.push({ start, end });
	visited[start][end] = ans[0];
	int cnt1 = 1;
	while (!Q.empty())
	{
		auto cur = Q.front(); Q.pop();

		for (int i = 0; i < 4; i++)
		{
			int nr = cur.r + dy[i];
			int nc = cur.c + dx[i];
			if (nr < 0 || nr >= N || nc < 0 || nc >= M) continue;
			if ((board[cur.r][cur.c] & bits[i]) != 0) continue;
			if (visited[nr][nc]) continue;
			visited[nr][nc] = ans[0];
			Q.push({ nr, nc });
			cnt1++;
		}
	}
	cnt[ans[0]] = cnt1;
	ans[1] = max(ans[1], cnt1);
}

void merge()
{
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			for (int k = 0; k < 4; k++)
			{
				int nr = i + dy[k];
				int nc = j + dx[k];
				if (nr < 0 || nr >= N || nc < 0 || nc >= M) continue;
				if (visited[i][j] != visited[nr][nc])
					ans[2] = max(ans[2], cnt[visited[i][j]] + cnt[visited[nr][nc]]);
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> M >> N;
	for (int i = 0; i < N; i++) for (int j = 0; j < M; j++)
		cin >> board[i][j];

	for (int i = 0; i < N; i++) for (int j = 0; j < M; j++)
		BFS(i, j);

	merge();

	for(int i = 0; i < 3; i++)
		cout << ans[i] << '\n';

	return 0;
}