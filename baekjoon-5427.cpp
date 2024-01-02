#include <iostream>
#include <vector>
#include <string>
#include <queue>

using namespace std;

typedef struct Node {
	int r, c;
	int t;
}Node;

int dy[4] = { 0, -1, 0, 1 };
int dx[4] = { -1, 0, 1, 0 };

int T;
int N, M;
string arr[1000];
int timer[1000][1000];
bool visited[1000][1000];

void fireSpread()
{
	queue<Node> fireQ;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			if (arr[i][j] == '*')
			{
				fireQ.push({ i, j, 1 });
				timer[i][j] = 1;
			}
		}
	}
	while (!fireQ.empty())
	{
		Node cur = fireQ.front(); fireQ.pop();
		for (int i = 0; i < 4; i++)
		{
			int nr = cur.r + dy[i];
			int nc = cur.c + dx[i];
			if (nr < 0 || nr >= N || nc < 0 || nc >= M) continue;
			if (timer[nr][nc] != 2e9) continue;
			if (arr[nr][nc] == '#') continue;
			timer[nr][nc] = cur.t + 1;
			fireQ.push({ nr, nc, cur.t + 1 });
		}
	}
}

int BFS()
{
	queue<Node> Q;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			if (arr[i][j] == '@')
			{
				Q.push({ i, j, 1 });
				visited[i][j] = true;
				break;
			}
		}
	}

	while (!Q.empty())
	{
		Node cur = Q.front(); Q.pop();
		if (cur.r == 0 || cur.r == N - 1 || cur.c == 0 || cur.c == M - 1)
			return cur.t;
		for (int i = 0; i < 4; i++)
		{
			int nr = cur.r + dy[i];
			int nc = cur.c + dx[i];
			if (nr < 0 || nr >= N || nc < 0 || nc >= M) continue;
			if (visited[nr][nc]) continue;
			if (arr[nr][nc] == '#') continue;
			if (timer[nr][nc] <= cur.t + 1) continue;
			visited[nr][nc] = true;
			Q.push({ nr, nc, cur.t + 1 });
		}
	}
	return -1;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> T;
	for (int test_case = 1; test_case <= T; test_case++)
	{
		
		cin >> M >> N;
		fill(&timer[0][0], &timer[999][999] + 1, 2e9);
		for (int i = 0; i < N; i++)
			cin >> arr[i];
		fireSpread();
		int res = BFS();
		if (res == -1)
			cout << "IMPOSSIBLE\n";
		else
			cout << res << '\n';
		fill(&visited[0][0], &visited[999][999] + 1, false);
	}
	return 0;
}