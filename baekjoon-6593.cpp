#include <iostream>
#include <queue>
#include <tuple>
#include <string>
#include <algorithm>
using namespace std;

constexpr int dy[6] = {0, -1, 0, 1, 0, 0};
constexpr int dx[6] = {-1, 0, 1, 0, 0, 0};
constexpr int dz[6] = {0, 0, 0, 0, -1, 1};

int L, R, C;
tuple<int, int, int> start;
tuple<int, int, int> dest;
char board[30][30][30];
bool visited[30][30][30];

int BFS()
{
	fill(&visited[0][0][0], &visited[29][29][29] + 1, false);
	queue<tuple<int, int, int, int>> Q;
	auto [ls, rs, cs] = start;
	Q.push({ls, rs, cs, 0});
	visited[ls][rs][cs] = true;

	while(!Q.empty())
	{
		auto [l, r, c, cnt] = Q.front(); Q.pop();

		for(int i = 0; i < 6; i++)
		{
			int nl = l + dz[i];
			int nr = r + dy[i];
			int nc = c + dx[i];
			if(nl < 0 || nl >= L || nr < 0 || nr >= R || nc < 0 || nc >= C) continue;
			if(visited[nl][nr][nc]) continue;
			if(board[nl][nr][nc] == '#') continue;

			if(board[nl][nr][nc] == 'E') return cnt + 1;

			Q.push({nl, nr, nc, cnt + 1});
			visited[nl][nr][nc] = true;
		}
	}
	return -1;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	while(1)
	{
		cin >> L >> R >> C;
		if(L == R && R == C && C == 0) break;

		for(int floor = 0; floor < L; floor++)
		{
			for(int i = 0; i < R; i++)
			{
				string str; cin >> str;
				for(int j = 0; j < C; j++)
				{
					board[floor][i][j] = str[j];
					if(str[j] == 'S')
						start = {floor, i, j};
					if(str[j] == 'E')
						dest = {floor, i, j};
				}
			}
		}

		int result = BFS();
		if(result < 0)
			cout << "Trapped!\n";
		else
			cout << "Escaped in " << result << " minute(s).\n";
	}
	
	return 0;
}