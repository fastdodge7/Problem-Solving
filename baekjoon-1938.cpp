#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

constexpr int VERTICAL = 0;
constexpr int HORIZONTAL = 1;
constexpr int INF = 1e9;

int N, M;
int dy[4] = { 0, -1, 0, 1 };
int dx[4] = { -1, 0, 1, 0 };

char board[50][50];
int visited[50][50][2];

bool canMove(int r, int c, int curState)
{
	for (int i = -1; i <= 1; i++)
	{
		int nr = curState == VERTICAL ? r + i : r;
		int nc = curState == HORIZONTAL ? c + i : c;
		if (nr < 0 || nr >= N || nc < 0 || nc >= N) return false;
		if (board[nr][nc] == '1') return false;
	}
	return true;
}

bool canRotate(int r, int c, int curState)
{
	for (int i = -1; i <= 1; i++)
	{
		for (int j = -1; j <= 1; j++)
		{
			int nr = r + i;
			int nc = c + j;
			if (nr < 0 || nr >= N || nc < 0 || nc >= N) return false;
			if (board[nr][nc] == '1') return false;
		}
	}
	return true;
}

void solve(int r, int c, int state, int cnt)
{
	visited[r][c][state] = cnt;

	for (int i = 0; i < 4; i++)
	{
		int nr = r + dy[i];
		int nc = c + dx[i];
		if (!canMove(nr, nc, state)) continue;
		if (visited[nr][nc][state] <= cnt + 1) continue;
		solve(nr, nc, state, cnt + 1);
	}
	if (visited[r][c][state == VERTICAL ? HORIZONTAL : VERTICAL] > cnt + 1)
	{
		if(canRotate(r, c, state))
			solve(r, c, state == VERTICAL ? HORIZONTAL : VERTICAL, cnt + 1);
	}
}


int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	fill(&visited[0][0][0], &visited[49][49][1] + 1, INF);
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		string str; cin >> str;
		for (int j = 0; j < N; j++)
			board[i][j] = str[j];
	}

	bool flag = false;
	int br = 0, bc = 0, bs = -1;
	int er = 0, ec = 0, es = -1;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (board[i][j] == 'B' && bs == -1)
			{
				if (board[i][j + 1] == 'B') {
					br = i; bc = j + 1; bs = HORIZONTAL;
				}
				else if(board[i + 1][j] == 'B') {
					br = i + 1; bc = j; bs = VERTICAL;
				}
			}
			if (board[i][j] == 'E' && es == -1)
			{
				if (board[i][j + 1] == 'E') {
					er = i; ec = j + 1; es = HORIZONTAL;
				}
				else if (board[i + 1][j] == 'E') {
					er = i + 1; ec = j; es = VERTICAL;
				}
			}
		}
	}
	
	solve(br, bc, bs, 0);
	cout << (visited[er][ec][es] == INF ? 0 : visited[er][ec][es]) << '\n';
	return 0;
}