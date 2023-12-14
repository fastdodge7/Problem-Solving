#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int dy[4] = { 0, -1, 0, 1 };
int dx[4] = { -1, 0, 1, 0 };

int N, M;
int board[100][100];
bool visited[100][100];

vector<pair<int, int>> elim;
int cnt = 0;
int t = 0;
int ans = 0;

void BFS(int r, int c)
{
	if (visited[r][c]) return;
	queue<pair<int, int>> Q; Q.push({ r, c });
	visited[r][c] = true;

	while (!Q.empty())
	{
		auto cur = Q.front(); Q.pop();
		for (int i = 0; i < 4; i++)
		{
			int nr = cur.first + dy[i];
			int nc = cur.second + dx[i];
			if (nr < 0 || nr >= N || nc < 0 || nc >= M) continue;
			if (visited[nr][nc]) continue;

			visited[nr][nc] = true;
			if (board[nr][nc] == 1)
				elim.push_back({ nr, nc });
			else
				Q.push({ nr, nc });
		}
	}
}

void step()
{
	for (int i = 0; i < N; i++)
	{
		BFS(0, i);
		BFS(N - 1, i);
		BFS(i, 0);
		BFS(i, M - 1);
	}
	for (auto& pt : elim)
		board[pt.first][pt.second] = 0;

	ans = cnt;
	cnt = cnt - elim.size();
	t++;
	elim.clear();
	fill(&visited[0][0], &visited[N - 1][M - 1] + 1, false);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> N >> M;

	for (int i = 0; i < N; i++) for (int j = 0; j < M; j++)
	{
		cin >> board[i][j];
		cnt = (board[i][j] == 1) ? cnt + 1 : cnt;
	}

	while (cnt > 0)
		step();

	cout << t << '\n' << ans;
	return 0;
}