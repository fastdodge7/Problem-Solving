#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <unordered_set>
#include <cassert>

using namespace std;

constexpr int MAX_R = 50, MAX_C = 50;

constexpr int dy[4] = {0, -1, 0, 1};
constexpr int dx[4] = {-1, 0, 1, 0};

constexpr int RED = 7;
constexpr int GREEN = 8;
constexpr int FLOWER = 999;

int N, M, R, G;
int board[MAX_R][MAX_C];
int visited[MAX_R][MAX_C];
int temp[MAX_R][MAX_C];
vector<pair<int, int>> arr;
vector<int> perm;

void printVisit()
{
	cout << "=====================================\n";
	for(int i = 0; i < N; i++)
	{
		for(int j = 0; j < M; j++)
			cout << visited[i][j] << ' ';
		cout << '\n';
	}
}

int BFS()
{
	fill(&visited[0][0], &visited[MAX_R - 1][MAX_C - 1] + 1, 0);
	fill(&temp[0][0], &temp[MAX_R - 1][MAX_C - 1] + 1, 0);
	
	queue<tuple<int, int, int, int>> Q;
	int ans = 0;
	for(int i = 0; i < arr.size(); i++)
	{
		if(perm[i] == 1)
		{
			Q.push({arr[i].first, arr[i].second, 1, 7});
			visited[arr[i].first][arr[i].second] = 1;
			temp[arr[i].first][arr[i].second] = RED;
		}
		if(perm[i] == 2)
		{
			Q.push({arr[i].first, arr[i].second, 1, 8});
			visited[arr[i].first][arr[i].second] = 1;
			temp[arr[i].first][arr[i].second] = GREEN;
		}
	}

	while(!Q.empty())
	{
		auto [r, c, dist, color] = Q.front(); Q.pop();
		if(visited[r][c] == FLOWER) continue;

		for(int i = 0; i < 4; i++)
		{
			int nr = r + dy[i];
			int nc = c + dx[i];
			if(nr < 0 || nr >= N || nc < 0 || nc >= M) continue;
			if(board[nr][nc] == 0) continue;
			if(visited[nr][nc] == FLOWER) continue;
			if(temp[nr][nc] == color) continue;
			if(visited[nr][nc] == 0)
			{
				visited[nr][nc] = dist + 1;
				temp[nr][nc] = color;
				Q.push({nr, nc, dist + 1, color});
			}
			else if(visited[nr][nc] == dist + 1 && temp[nr][nc] != color)
			{
				visited[nr][nc] = FLOWER;
				ans++;
			}
		}
	}

	

	return ans;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	
	cin >> N >> M >> G >> R;
	for(int i = 0; i < N; i++) for(int j = 0; j < M; j++)
	{
		cin >> board[i][j];
		if(board[i][j] == 2)
			arr.push_back({i, j});
	}

	for(int i = 0; i < arr.size() - (R + G); i++) perm.push_back(0);
	for(int i = 0; i < R; i++) perm.push_back(1);
	for(int i = 0; i < G; i++) perm.push_back(2);

	int ans = 0;	
	do
	{
		ans = max(ans, BFS());
	}while(next_permutation(perm.begin(), perm.end()));

	cout << ans;
	return 0;
}