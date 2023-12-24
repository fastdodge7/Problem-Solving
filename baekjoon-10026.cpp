#include <iostream>
#include <algorithm>
#include <queue>
#include <string>

using namespace std;

int N;

int dy[4] = {0, -1, 0, 1};
int dx[4] = {-1, 0, 1, 0};

bool visited[100][100];
string board[100];

int ans = 0;

bool isSameRegion(int r1, int c1, int r2, int c2, bool isColorBlind)
{
	if(isColorBlind)
	{
		int color1 = board[r1][c1];
		int color2 = board[r2][c2];
		if((color1 == 'G' || color1 == 'R') && (color2 == 'G' || color2 == 'R'))
			return true;
	}
	return board[r1][c1] == board[r2][c2];
}

void BFS(int r, int c, bool isColorBlind)
{
	if(visited[r][c]) return;
	
	ans++;
	queue<pair<int, int>> Q; Q.push({r, c});
	visited[r][c] = true;
	while(!Q.empty())
	{
		auto cur = Q.front(); Q.pop();
		for(int i = 0; i < 4; i++)
		{
			int nr = cur.first + dy[i];
			int nc = cur.second + dx[i];
			if(nr < 0 || nr >= N || nc < 0 || nc >= N) continue;
			if(visited[nr][nc]) continue;
			
			if(isSameRegion(nr, nc, cur.first, cur.second, isColorBlind))
			{
				visited[nr][nc] = true;
				Q.push({nr, nc});
			}
		}
	}
}

int main() {
	// your code goes here
	cin >> N;
	for(int i = 0; i < N; i++)
		cin >> board[i];
		
	for(int i = 0; i < N; i++)
	{
		for(int j = 0; j < N; j++)
			BFS(i, j, false);
	}
	cout << ans << ' ';
	fill(&visited[0][0], &visited[99][99] + 1, false);
	ans = 0;
	for(int i = 0; i < N; i++)
	{
		for(int j = 0; j < N; j++)
			BFS(i, j, true);
	}
	cout << ans << ' ';
	return 0;
}