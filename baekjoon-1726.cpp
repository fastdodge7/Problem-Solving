#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <queue>

using namespace std;

typedef long long ll;

constexpr int INF = 1e9;

int N, M;
int dy[4] = {0, -1, 0, 1};
int dx[4] = {-1, 0, 1, 0};

int transForm[5] = {-1, 2, 0, 3, 1};

int board[101][101];
int visited[101][101][4];

typedef struct Node{
	bool operator==(const Node& other) const { return r == other.r && c == other.c && dir == other.dir; }
	int r, c;
	int dir;
	int cnt;
}Node;

Node from, to;

int BFS()
{
	queue<Node> Q; Q.push({from.r, from.c, from.dir, 0});
	visited[from.r][from.c][from.dir] = 0;

	while(!Q.empty())
	{
		auto cur = Q.front(); Q.pop();
		if(cur == to) return cur.cnt;

		for(int i = 1; i <= 3; i++)
		{
			int nr = cur.r + i * dy[cur.dir];
			int nc = cur.c + i * dx[cur.dir];

			if(nr < 1 || nr > N || nc < 1 || nc > M) continue;
			if(board[nr][nc] == 1) break;
			if(visited[nr][nc][cur.dir] <= cur.cnt + 1) continue;
			visited[nr][nc][cur.dir] = cur.cnt + 1;
			Q.push({nr, nc, cur.dir, cur.cnt + 1});
		}
		for(int i = -1; i <= 1; i++)
		{
			if(i == 0) continue;
			if(visited[cur.r][cur.c][(cur.dir + 4 + i) % 4] <= cur.cnt + 1) continue;
			visited[cur.r][cur.c][(cur.dir + 4 + i) % 4] = cur.cnt + 1;
			Q.push({cur.r, cur.c, (cur.dir + 4 + i) % 4, cur.cnt + 1});
		}
	}
	return -1;
}


int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	fill(&visited[0][0][0], &visited[100][100][3] + 1, INF);

	cin >> N >> M;
	for(int i = 1; i <= N; i++) for(int j = 1; j <= M; j++)
		cin >> board[i][j];

	cin >> from.r >> from.c;
	int d; cin >> d; from.dir = transForm[d];

	cin >> to.r >> to.c;
	cin >> d; to.dir = transForm[d];

	cout << BFS() << '\n';

	return 0;
}