#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <queue>

using namespace std;

int N, M;
int dy[4] = { 0, -1, 0, 1 };
int dx[4] = { -1, 0, 1, 0 };
char map[100][100];
int visited[100][100][4]; //[r][c][dir]에 도달하는 최소 방향전환 횟수

typedef struct Node {
	int r, c;
	int dir;
	int cnt;
};

void BFS(int startR, int startC)
{
	queue<Node> Q; 
	for (int i = 0; i < 4; i++)
	{
		visited[startR][startC][i] = 0;
		Q.push({ startR, startC, i, 0 });
	}

	while (!Q.empty())
	{
		auto cur = Q.front(); Q.pop();

		for (int i = -1; i < 2; i++)
		{
			if (i == 0) continue;
			int newDir = (cur.dir + 4 + i) % 4;
			if (visited[cur.r][cur.c][newDir] > cur.cnt + 1)
			{
				visited[cur.r][cur.c][newDir] = cur.cnt + 1;
				Q.push({ cur.r, cur.c, newDir, cur.cnt + 1 });
			}
		}

		int nr = cur.r + dy[cur.dir];
		int nc = cur.c + dx[cur.dir];
		if (nr < 0 || nr >= N || nc < 0 || nc >= M) continue;
		if (map[nr][nc] == '*') continue;
		if (visited[nr][nc][cur.dir] > cur.cnt)
		{
			visited[nr][nc][cur.dir] = cur.cnt;
			Q.push({ nr, nc, cur.dir, cur.cnt });
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	fill(&visited[0][0][3], &visited[99][99][3] + 1, 1e9);

	cin >> M >> N;
	vector<pair<int, int>> endPoint;
	for (int i = 0; i < N; i++)
	{
		string str; cin >> str;
		for (int j = 0; j < M; j++)
		{
			map[i][j] = str[j];
			if (map[i][j] == 'C')
				endPoint.push_back({ i, j });
		}
	}

	BFS(endPoint[0].first, endPoint[0].second);
	
	int ans = 1e9;
	for (int i = 0; i < 4; i++)
		ans = min(ans, visited[endPoint[1].first][endPoint[1].second][i]);

	cout << ans << '\n';
	return 0;
}