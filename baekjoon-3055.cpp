#include <iostream>
#include <string>
#include <queue>
#include <algorithm>
#include <cassert>

using namespace std;

typedef struct Node{
	int r, c, cnt;
}Node;

int dy[4] = {0, -1, 0, 1};
int dx[4] = {-1, 0, 1, 0};

int R, C;
int strR, strC;
int dstR, dstC;
string board[50];
int visited[50][50];
bool vis[50][50];


void waterBFS()
{
	fill(&visited[0][0], &visited[49][49] + 1, 1e9);
	queue<Node> Q;
	for(int i = 0; i < R; i++)
	{
		for(int j = 0; j < C; j++)
		{
			if(board[i][j] == '*')
			{
				Q.push({i, j, 0});
				visited[i][j] = 0;
			}
		}
	}
	
	while(!Q.empty())
	{
		auto cur = Q.front(); Q.pop();
		for(int i = 0; i < 4; i++)
		{
			int nr = cur.r + dy[i];
			int nc = cur.c + dx[i];
			if(nr < 0 || nr >= R || nc < 0 || nc >= C) continue;
			if(visited[nr][nc] <= cur.cnt + 1) continue;
			if(board[nr][nc] != '.') continue;
			
			Q.push({nr, nc, cur.cnt + 1});
			visited[nr][nc] = cur.cnt + 1;
		}
	}
}

int BFS(int r, int c)
{
	queue<Node> Q; Q.push({r, c, 0});
    vis[r][c] = true;
	while(!Q.empty())
	{
		auto cur = Q.front(); Q.pop();
        
        if(Q.size() > 3000) return -1;
		if(cur.r == dstR && cur.c == dstC)
			return cur.cnt;
		for(int i = 0; i < 4; i++)
		{
			int nr = cur.r + dy[i];
			int nc = cur.c + dx[i];
			if(nr < 0 || nr >= R || nc < 0 || nc >= C) continue;
			if(visited[nr][nc] <= cur.cnt + 1) continue;
            if(vis[nr][nc]) continue;
			if(board[nr][nc] == 'X') continue;
			
			Q.push({nr, nc, cur.cnt + 1});
            vis[nr][nc] = true;
		}
	}
	return -1;
}
int main() {
	// your code goes here
	
	cin >> R >> C;
	for(int i = 0; i <R;i++)
		cin >> board[i];
	for(int i = 0; i < R; i++) for(int j = 0; j < C; j++)
	{
		if(board[i][j] == 'S')
		{
			strR = i;
			strC = j;
		}
		if(board[i][j] == 'D')
		{
			dstR = i;
			dstC = j;
		}
	}
	
	waterBFS();
	int ret = BFS(strR, strC);
	if(ret == -1)
		cout << "KAKTUS";
	else
		cout << ret;
	return 0;
}