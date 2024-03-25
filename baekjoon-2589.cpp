#include <iostream>
#include <queue>
#include <string>
#include <algorithm>

using namespace std;

int dy[4] = {0, -1, 0, 1};
int dx[4] = {-1, 0, 1, 0};

typedef struct Node{
	int r, c;
	int cnt;
}Node;

int N, M;
string board[50];
bool visited[50][50];

int BFS(int r, int c)
{
	if(board[r][c] == 'W')
		return 0;
	
	fill(&visited[0][0], &visited[49][49] + 1, false);
	queue<Node> Q; Q.push({r, c, 0});
	visited[r][c] = true;
	
	int ret = 0;
	while(!Q.empty())
	{
		auto cur = Q.front(); Q.pop();
		ret = max(ret, cur.cnt);
		for(int i = 0; i < 4; i++)
		{
			int nr = cur.r + dy[i];
			int nc = cur.c + dx[i];
			if(nr < 0 || nr >= N || nc < 0 || nc >= M) continue;
			if(board[nr][nc] == 'W') continue;
			if(visited[nr][nc]) continue;
			
			visited[nr][nc] = true;
			Q.push({nr, nc, cur.cnt + 1});
		}
	}
	return ret;
}

int main() {
	ios::sync_with_stdio(false);
	cout.tie(0); cin.tie(0);
	
	cin >> N >> M;
	for(int i = 0; i < N; i++)
		cin >> board[i];
	
	int ans = 0;
	for(int i = 0; i < N; i++) for(int j = 0; j < M; j++)
		ans = max(ans, BFS(i, j));
		
	cout << ans << '\n';
	return 0;
}