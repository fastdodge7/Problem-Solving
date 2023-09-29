#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <queue>

using namespace std;

constexpr int INF = 1e9;

int dy[4] = { 0, -1, 0, 1 };
int dx[4] = { -1, 0, 1, 0 };

int board[125][125];
int visited[125][125];

typedef struct Node {
	int r, c;
	int stolen;
}Node;

int N;

int BFS()
{
	fill(&visited[0][0], &visited[124][124] + 1, INF);
	queue<Node> Q; Q.push({ 0, 0, board[0][0] });
	visited[0][0] = board[0][0];

	while (!Q.empty())
	{
		auto cur = Q.front(); Q.pop();
		for (int i = 0; i < 4; i++)
		{
			int nr = cur.r + dy[i];
			int nc = cur.c + dx[i];
			if (nr < 0 || nr >= N || nc < 0 || nc >= N) continue;
			if (visited[nr][nc] <= cur.stolen + board[nr][nc]) continue;
			visited[nr][nc] = cur.stolen + board[nr][nc];
			Q.push({ nr, nc , visited[nr][nc] });
		}
	}
	return visited[N - 1][N - 1];
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int test_case = 1;
	while(1)
	{
		cin >> N;
		if (N == 0) break;
		for (int i = 0; i < N; i++) for (int j = 0; j < N; j++)
			cin >> board[i][j];

		cout << "Problem " << test_case++ << ": " << BFS() << '\n';
	}
	return 0;
}