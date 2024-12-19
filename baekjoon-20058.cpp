#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <deque>
#include <cassert>

using namespace std;

constexpr int dy[4] = {0, 1, 0, -1};
constexpr int dx[4] = {-1, 0, 1, 0};

int L, Q;
int board[1 << 6][1 << 6];
int test[8][8];
bool visited[1 << 6][1 << 6];

void print()
{
	cout << "========================================\n";
	for(int i = 0; i < (1 << L); i++) 
	{
		for(int j = 0; j < (1 << L); j++)
			cout << board[i][j] << ' ';
		cout << '\n';
	}
}

void rotateBlockEdge(int r, int c, int size)
{
	if(size < 1) return;

	deque<int> dq;
	for(int i = c; i < c + size - 1; i++)
		dq.push_back(board[r][i]);
	for(int i = r; i < r + size - 1; i++)
		dq.push_back(board[i][c + size - 1]);
	for(int i = c + size - 1; i > c; i--)
		dq.push_back(board[r + size - 1][i]);
	for(int i = r + size - 1; i > r; i--)
		dq.push_back(board[i][c]);

	for(int i = 0; i < size - 1; i++)
	{
		dq.push_front(dq.back());
		dq.pop_back();
	}

	for(int i = c; i < c + size - 1; i++)
	{
		board[r][i] = dq.front();
		dq.pop_front();
	}
	for(int i = r; i < r + size - 1; i++)
	{
		board[i][c + size - 1] = dq.front();
		dq.pop_front();
	}
	for(int i = c + size - 1; i > c; i--)
	{
		board[r + size - 1][i] = dq.front();
		dq.pop_front();
	}
	for(int i = r + size - 1; i > r; i--)
	{
		board[i][c] = dq.front();
		dq.pop_front();
	}

	rotateBlockEdge(r + 1, c + 1, size - 2);
}

void rotate(int level)
{
	for(int r = 1; r < (1 << L); r += (1 << level))
	{
		for(int c = 1; c < (1 << L); c += (1 << level))
		{
			rotateBlockEdge(r - 1, c - 1, (1 << level));
			//print();
		}
	}
}

void meltDown()
{
	for(int r = 0; r < (1 << L); r++)
	{
		for(int c = 0; c < (1 << L); c++)
		{
			if(board[r][c] == 0) continue;
			int cnt = 0;
			for(int d = 0; d < 4; d++)
			{
				int nr = r + dy[d];
				int nc = c + dx[d];
				if(nr < 0 || nr >= (1 << L) || nc < 0 | nc >= (1 << L)) continue;
				if(board[nr][nc] > 0) cnt++;
			}
			if(cnt < 3)
				visited[r][c] = true;
		}
	}

	for(int r = 0; r < (1 << L); r++)
	{
		for(int c = 0; c < (1 << L); c++)
		{
			if(visited[r][c])
				board[r][c]--;
		}
	}

	fill(&visited[0][0], &visited[(1 << 6) - 1][(1 << 6) - 1] + 1, false);
}

int BFS(int r, int c)
{
	if(visited[r][c]) return 0;
	if(board[r][c] <= 0) return 0;

	queue<pair<int, int>> Q;
	Q.push({r, c});
	visited[r][c] = true;

	int ret = 1;

	while(!Q.empty())
	{
		auto [a, b] = Q.front(); Q.pop();

		for(int i = 0; i < 4; i++)
		{
			int nr = a + dy[i];
			int nc = b + dx[i];
			if(nr < 0 || nr >= (1 << L) || nc < 0 || nc >= (1 << L)) continue;
			if(visited[nr][nc]) continue;
			if(board[nr][nc] <= 0) continue;

			visited[nr][nc] = true;
			ret++;
			Q.push({nr, nc});
		}
	}

	return ret;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	
	cin >> L >> Q;
	for(int i = 0; i < (1 << L); i++) for(int j = 0; j < (1 << L); j++)
		cin >> board[i][j];

	for(int i = 0; i < Q; i++)
	{
		int lev; cin >> lev;

		rotate(lev);
		meltDown();
	}

	int ans = 0;
	int land = 0;
	for(int i = 0; i < (1 << L); i++) for(int j = 0; j < (1 << L); j++)
	{
		land = max(land, BFS(i, j));
		ans += board[i][j];
	}

	cout << ans << '\n' << land << '\n';
	return 0;
}