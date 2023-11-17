#include <algorithm>
#include <string>
#include <queue>
#include <iostream>

using namespace std;

int dy[4] = {0, -1, 0, 1};
int dx[4] = {-1, 0, 1, 0};

int N, M;
char arr[100][100];
int visited[100][100];

typedef struct Node{
	int r, c;
}Node;

int BFS()
{
	fill(&visited[0][0], &visited[99][99] + 1, 1e9);
	queue<Node> Q;
	Q.push({0, 0});
	visited[0][0] = 0;
	
	while (!Q.empty())
	{
		Node cur = Q.front(); Q.pop();
		
		for(int i = 0; i < 4; i++)
		{
			int nr = cur.r + dy[i];
			int nc = cur.c + dx[i];
			if(nr < 0 || nr >= N || nc < 0 || nc >= M)
				continue;
			if(visited[cur.r][cur.c] + (arr[nr][nc] == '1' ? 1 : 0) >= visited[nr][nc])
				continue;
			visited[nr][nc] = visited[cur.r][cur.c] + (arr[nr][nc] == '1' ? 1 : 0);
			Q.push({nr, nc});
		}
	}
	return visited[N - 1][M - 1];
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> M >> N;
	for(int i = 0; i < N; i++)
	{
		string str; cin >> str;
		for(int j = 0; j < str.size(); j++)
			arr[i][j] = str[j];
	}

	cout << BFS();
	return 0;
}