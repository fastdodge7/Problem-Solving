#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <queue>

using namespace std;

int dy[4] = { 0, -1, 0, 1 };
int dx[4] = { -1, 0, 1, 0 };

typedef struct Node {
	int r, c;
	int distance;
}Node;

int N;

int board[100][100];
int visited[100][100];
int marker = 0;

void marking(int r, int c)
{
	if (visited[r][c]) return;

	queue<Node> Q; Q.push({ r, c, 0 });
	visited[r][c] = true;
	marker++;

	while (!Q.empty())
	{
		auto cur = Q.front(); Q.pop();
		board[cur.r][cur.c] = marker;

		for (int i = 0; i < 4; i++)
		{
			int nr = cur.r + dy[i];
			int nc = cur.c + dx[i];
			if (nr < 0 || nr >= N || nc < 0 || nc >= N) continue;
			if (visited[nr][nc]) continue;
			if (board[nr][nc] == 0) continue;
			visited[nr][nc] = true;
			Q.push({ nr, nc, 0 });
		}
	}
}

int BFS(int r, int c, int mark)
{
	queue<Node> Q; Q.push({ r, c, 0 });
	visited[r][c] = 0;

	int ans = 1e9;

	while (!Q.empty())
	{
		auto cur = Q.front(); Q.pop();

		for (int i = 0; i < 4; i++)
		{
			int nr = cur.r + dy[i];
			int nc = cur.c + dx[i];
			if (nr < 0 || nr >= N || nc < 0 || nc >= N) continue;

			int dist = (board[nr][nc] == mark ? cur.distance : cur.distance + 1);
			if (visited[nr][nc] <= dist) continue;

			if (board[nr][nc] != 0 && board[nr][nc] != mark)
			{
				ans = min(ans, cur.distance);
				continue;
			}

			visited[nr][nc] = dist;
			Q.push({ nr, nc, dist });
		}
	}

	return ans;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> N;
	for (int i = 0; i < N; i++) for (int j = 0; j < N; j++)
		cin >> board[i][j];

	for (int i = 0; i < N; i++) for (int j = 0; j < N; j++)
	{
		if (board[i][j] != 0)
			marking(i, j);
	}

	fill(&visited[0][0], &visited[99][99] + 1, 1e9);

	int ans = 1e9;
	for (int i = 0; i < N; i++) for (int j = 0; j < N; j++)
	{
		if (visited[i][j] > 0 && board[i][j] > 0)
			ans = min(ans, BFS(i, j, board[i][j]));
	}

	cout << ans << '\n';

	return 0;
}