#include <iostream>
#include <string>
#include <queue>
#include <algorithm>

using namespace std;

const int dy[4] = {0, -1, 0, 1};
const int dx[4] = {-1, 0, 1, 0};

typedef struct Node{
	int r, c;
	int dist;
	int breakCnt;
}Node;

int N, M, K;
string board[1000];
int visited[1000][1000][11];

int BFS()
{
	queue<Node> Q; Q.push({0, 0, 1, 0});
	visited[0][0][0] = 1;

	while(!Q.empty())
	{
		auto cur = Q.front(); Q.pop();

		if(cur.r == N - 1 && cur.c == M - 1)
			return cur.dist;
        
		bool flag = true;
		for(int i = 0; i < 4; i++)
		{
			int nr = cur.r + dy[i];
			int nc = cur.c + dx[i];
			if(nr < 0 || nr >= N || nc < 0 || nc >= M) continue;
			if(board[nr][nc] == '1')
			{
				if(cur.dist % 2 == 0) // 밤인경우
				{
					if(flag)
					{
						Q.push({cur.r, cur.c, cur.dist + 1, cur.breakCnt});
						flag = false;
					}
					continue;
				}
				else if(cur.breakCnt >= K)
				{
					continue;
				}
			} 
            
            int nCnt = (board[nr][nc] == '1' ? cur.breakCnt + 1 : cur.breakCnt);
			if(visited[nr][nc][nCnt] > 0 && visited[nr][nc][nCnt] <= cur.dist + 1) continue;

			
			Q.push({nr, nc, cur.dist + 1, nCnt});
			visited[nr][nc][nCnt] = cur.dist + 1;
		}
	}
	return -1;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> N >> M >> K;
	for(int i = 0; i < N; i++)
		cin >> board[i];
	
	cout << BFS();
	
	return 0;
}