#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <unordered_set>
#include <cassert>

using namespace std;

constexpr int dy[4] = {0, -1, 0, 1};
constexpr int dx[4] = {-1, 0, 1, 0};

int N, M, T;
int board[100][100];
int dist[100][100];
pair<int, int> superUltraEmperorSword;

void BFS()
{
	queue<tuple<int, int, int>> Q;
	fill(&dist[0][0], &dist[99][99] + 1, 1e9);
	Q.push({0, 0, 1});
	dist[0][0] = 1;

	while(!Q.empty())
	{
		auto [r, c, dst] = Q.front(); Q.pop();

		for(int i = 0; i < 4; i++)
		{
			int nr = r + dy[i];
			int nc = c + dx[i];
			if(nr < 0 || nr >= N || nc < 0 || nc >= M) continue;
			if(board[nr][nc] == 1) continue;
			if(dist[nr][nc] <= dst + 1) continue;
			
			dist[nr][nc] = dst + 1;
			Q.push({nr, nc, dst + 1});
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	
	cin >> N >> M >> T;
	for(int i = 0; i < N; i++) for(int j = 0; j < M; j++)
	{
		cin >> board[i][j];
		if(board[i][j] == 2)
			superUltraEmperorSword = {i, j};
	}

	BFS();

	auto [sr, sc] = superUltraEmperorSword;
	int ans = min(dist[N - 1][M - 1], dist[sr][sc] + (M - 1 - sc) + (N - 1 - sr)) - 1;

	if(ans > T) cout << "Fail";
	else cout << ans;
	return 0;
}