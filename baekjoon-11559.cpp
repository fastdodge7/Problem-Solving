#include <algorithm>
#include <string>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

constexpr int dy[4] = {0, -1, 0, 1};
constexpr int dx[4] = {-1, 0, 1, 0};

string board[12];
bool visited[12][6];

int BFS(int r, int c)
{
	if(visited[r][c]) return 0;
	if(board[r][c] == '.') return 0;

	queue<pair<int, int>> Q; Q.push({r, c});
	visited[r][c] = true;
	char color = board[r][c];
	vector<pair<int, int>> arr;

	int ret = 0;
	while(!Q.empty())
	{
		auto [curR, curC] = Q.front(); Q.pop();
		arr.push_back({curR, curC});
		ret++;

		for(int i = 0; i < 4; i++)
		{
			int nr = curR + dy[i];
			int nc = curC + dx[i];
			if(nr < 0 || nr >= 12 || nc < 0 || nc >= 6) continue;
			if(board[nr][nc] == '.') continue;
			if(visited[nr][nc]) continue;
			if(color != board[nr][nc]) continue;

			visited[nr][nc] = true;
			Q.push({nr, nc});
		}
	}

	if(ret >= 4)
	{
		for(auto [cr, cc] : arr)
			board[cr][cc] = '.';
	}

	return ret;
}

bool step()
{
	int cnt = 0;
	fill(&visited[0][0], &visited[11][5] + 1, false);
	for(int i = 0; i < 12; i++)
	{
		for(int j = 0; j < 6; j++)
		{
			if(BFS(i, j) >= 4)
				cnt++;
		}
	}

	for(int j = 0; j < 6; j++)
	{
		int first = 11;
		for(int i = 11; i >= 0; i--)
		{
			if(board[i][j] == '.')
			{
				first = i;
				break;
			}
		}

		for(int i = first; i >= 0; i--)
		{
			if(board[i][j] != '.')
			{
				swap(board[i][j], board[first][j]);
				first--;
			}
		}
	}

	return cnt > 0;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	for(int i = 0; i < 12; i++)	
		cin >> board[i];
	int ans = 0;
	while(step())
	{
		ans++;
	}

	cout << ans;
	
	return 0;
}