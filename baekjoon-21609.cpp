#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

constexpr int BLACK = -1;
constexpr int RAINBOW = 0;
constexpr int EMPTY = -4;

constexpr int dy[4] = {0, -1, 0, 1};
constexpr int dx[4] = {-1, 0, 1, 0};

int N, M;
int board[20][20];
int buffer[20][20];
bool visited[20][20];

pair<int, int> countBlockElem(int r, int c, int block)
{
	if(visited[r][c] || board[r][c] == EMPTY || board[r][c] == BLACK || board[r][c] == RAINBOW) 
		return {0, 0};
	queue<pair<int, int>> Q; Q.push({r, c});
	queue<pair<int, int>> rainbows;
	visited[r][c] = true;

	int ret = 0;
	int rain = 0;
	while(!Q.empty())
	{
		auto cur = Q.front(); Q.pop();
		ret++;
		if(board[cur.first][cur.second] == RAINBOW)
			rain++;

		for(int i = 0; i < 4; i++)
		{
			int nr = cur.first + dy[i];
			int nc = cur.second + dx[i];

			if(nr < 0 || nr >= N || nc < 0 || nc >= N) continue;
			if(visited[nr][nc]) continue;
			if(board[nr][nc] != block && board[nr][nc] != RAINBOW) continue;

			if(board[nr][nc] == RAINBOW)
				rainbows.push({nr, nc});
			Q.push({nr, nc});
			visited[nr][nc] = true;
		}
	}

	while(!rainbows.empty())
	{
		auto cur = rainbows.front(); rainbows.pop();
		visited[cur.first][cur.second] = false;
	}
	return {ret, rain};
}

int deleteBlock(int r, int c, int block)
{
	queue<pair<int, int>> Q; Q.push({r, c});
	visited[r][c] = true;
	int ret = 0;

	while(!Q.empty())
	{
		auto cur = Q.front(); Q.pop();
		board[cur.first][cur.second] = EMPTY;
		ret++;

		for(int i = 0; i < 4; i++)
		{
			int nr = cur.first + dy[i];
			int nc = cur.second + dx[i];

			if(nr < 0 || nr >= N || nc < 0 || nc >= N) continue;
			if(visited[nr][nc]) continue;
			if(board[nr][nc] != block && board[nr][nc] != RAINBOW) continue;

			Q.push({nr, nc});
			visited[nr][nc] = true;
		}
	}

	return ret * ret;
}

void rotate()
{
	for(int i = 0; i < N; i++) for(int j = 0; j < N; j++)
	{
		buffer[(N - 1) - j][i] = board[i][j];
	}
	for(int i = 0; i < N; i++) for(int j = 0; j < N; j++)
	{
		board[i][j] = buffer[i][j];
	}
}

void applyGravity()
{
	for(int j = 0; j < N; j++)
	{
		for(int i = N - 1 - 1; i >= 0; i--)
		{
			if(board[i][j] == BLACK || board[i][j] == EMPTY) continue;
			int dest = i;
			for(int k = i + 1; k < N; k++)
			{
				if(board[k][j] != EMPTY)
				{
					dest = k - 1;
					break;
				}
				dest = k;
			}
			if(dest != i)
			{
				board[dest][j] = board[i][j];
				board[i][j] = EMPTY;
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> N >> M;
	for(int i = 0; i < N; i++) for(int j = 0; j < N; j++)
		cin >> board[i][j];


	int r = 0; int c = 0;
	int ans = 0;
	while(1)
	{
		pair<int, int> cand = {0, 0};
		for(int i = 0; i < N; i++)
		{
			for(int j = 0; j < N; j++)
			{
				auto temp = countBlockElem(i, j, board[i][j]);
				if(cand <= temp)
				{
					cand = temp;
					r = i; 
					c = j;
				}
			}
		}
		if(cand.first <= 1) break;

		fill(&visited[0][0], &visited[19][19] + 1, false);
		ans += deleteBlock(r, c, board[r][c]);

		fill(&visited[0][0], &visited[19][19] + 1, false);
		
		applyGravity();
		rotate();
		applyGravity();
	}

	cout << ans;
	return 0;
}