#include <iostream>
#include <string>
#include <queue>
#include <algorithm>

using namespace std;

const int dy[4] = {-1, 0, 0, 1};
const int dx[4] = {0, -1, 1, 0};

int N;
int R, C;
int curSize = 2;
int cnt = 0;
int ans = 0;
int board[20][20];
int visited[20][20];

int BFS(int r, int c)
{
	fill(&visited[0][0], &visited[19][19] + 1, -1);
	queue<pair<int, int>> Q; Q.push({r, c});
	visited[r][c] = 0;

	vector<pair<int, int>> cand;

	while(!Q.empty())
	{
		auto [curR, curC] = Q.front(); Q.pop();
        
		for(int i = 0; i < 4; i++)
		{
			int nr = curR + dy[i];
			int nc = curC + dx[i];
			if(nr < 0 || nr >= N || nc < 0 || nc >= N) continue;
			if(board[nr][nc] > curSize) continue;
			if(visited[nr][nc] != -1) continue;
			if(!cand.empty() && visited[curR][curC] >= visited[cand[0].first][cand[0].second]) 
				continue;
			
			if(board[nr][nc] < curSize && board[nr][nc] > 0)
			{
				cand.push_back({nr, nc});
			}
			
			Q.push({nr, nc});
			visited[nr][nc] = visited[curR][curC] + 1;
		}
	}

	if(cand.empty())
		return false;
	

	sort(cand.begin(), cand.end());
	R = cand[0].first;
	C = cand[0].second;
	if(++cnt == curSize)
	{
		cnt = 0;
		curSize++;
	}
	board[R][C] = 0;
	ans += visited[R][C];
	return true;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> N;;
	for(int i = 0; i < N; i++) for(int j = 0; j < N; j++)
	{
		cin >> board[i][j];
		if(board[i][j] == 9)
		{
			R = i;
			C = j;
			board[i][j] = 0;
		}
	}
	
	while(BFS(R, C))
	{

	}
	cout << ans;
	
	return 0;
}