#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>

using namespace std;

constexpr int dy[4] = {-1, 0, 1, 0};
constexpr int dx[4] = {0, -1, 0, 1};

int N;
int visited[50][50];
string board[50];

typedef struct Node{
	int r, c;
}Node;

void BFS()
{
	queue<Node> Q; Q.push({0, 0});
	visited[0][0] = 0;

	while(!Q.empty())
	{
		Node cur = Q.front(); Q.pop();

		for(int i = 0; i < 4; i++)
		{
			int nr = cur.r + dy[i];
			int nc = cur.c + dx[i];
			if(nr < 0 || nr >= N || nc < 0 || nc >= N) continue;

			int cost = (board[nr][nc] == '1' ? visited[cur.r][cur.c] : visited[cur.r][cur.c] + 1);
			if(visited[nr][nc] <= cost) continue;

			visited[nr][nc] = cost;
			Q.push({nr, nc});
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	fill(&visited[0][0], &visited[49][49] + 1, 1e9);

	cin >> N;
	for(int i = 0; i < N; i++)
		cin >> board[i];

	BFS();

	cout << visited[N - 1][N - 1];
	return 0;
}