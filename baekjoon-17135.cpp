#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <queue>
#include <cmath>
#include <cstring>

using namespace std;

int dy[4] = {0, -1, 0};
int dx[4] = {-1, 0, 1};

int N, M, D;

int data[16][16];
int board[16][16];
int visited[16][16];

typedef struct Node{
	int r, c;
	int dist;
}Node;

pair<int, int> BFS(int r, int c)
{
	fill(&visited[0][0], &visited[N][M] + 1, false);
	queue<Node> Q; Q.push({r - 1, c, 1});
	visited[r][c] = true;
	
	while(!Q.empty())
	{
		auto cur = Q.front(); Q.pop();
		if(board[cur.r][cur.c] == 1)
			return {cur.r, cur.c};
			
		for(int i = 0; i < 3; i++)
		{
			int nr = cur.r + dy[i];
			int nc = cur.c + dx[i];
			if(nr < 0 || nr >= N || nc < 0 || nc >= M) continue;
			if(visited[nr][nc]) continue;
			if(cur.dist >= D) continue;

			visited[nr][nc] = true;
			Q.push({nr, nc, cur.dist + 1});
			
		}
	}

	return {-1, -1};
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> N >> M >> D;
	for(int i = 0; i < N; i++) for(int j = 0; j < M; j++)
		cin >> data[i][j];

	
	int ans = 0;
	for(int first = 0; first < M - 2; first++)
	{
		for(int second = first + 1; second < M - 1; second++)
		{
			for(int third = second + 1; third < M; third++)
			{
				memcpy(board, data, sizeof(data));
				int temp = 0;
				for(int row = N; row > 0; row--)
				{
					pair<int, int> fst = BFS(row, first);
					pair<int, int> scd = BFS(row, second);
					pair<int, int> thd = BFS(row, third);

					if(fst.first >= 0)
					{
						temp++;
						board[fst.first][fst.second] = 0;
					}

					if(scd.first >= 0 && scd != fst)
					{
						temp++;
						board[scd.first][scd.second] = 0;
					}

					if(thd.first >= 0 && thd != fst && thd != scd)
					{
						temp++;
						board[thd.first][thd.second] = 0;
					}
				}
				ans = max(temp, ans);
			}
		}
	}

	cout << ans;
	
	return 0;
}
