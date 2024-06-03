#include <iostream>
#include <algorithm>
#include <queue>
#include <string>

using namespace std;

typedef struct Node
{
	int r, c;
	int dist;
	bool operator<(const Node& other) const {
		if(r == other.r && c == other.c)
			return dist < other.dist;
		if(r == other.r)
			return c < other.c;
		return r < other.r;
	}
}Node;

int N, M;

int dy[4] = {0, -1, 0, 1};
int dx[4] = {-1, 0, 1, 0};

bool visited[50][50];
int board[50][50];
vector<pair<int, int>> chicken;
vector<int> cand;
vector<vector<Node>> arr;

int ans = 1e9;

void BFS(int r, int c, int chickenNum)
{
	fill(&visited[0][0], &visited[49][49] + 1, false);
	queue<Node> Q; Q.push({r, c});
	visited[r][c] = true;
	while(!Q.empty())
	{
		auto cur = Q.front(); Q.pop();
		for(int i = 0; i < 4; i++)
		{
			int nr = cur.r + dy[i];
			int nc = cur.c + dx[i];
			if(nr < 0 || nr >= N || nc < 0 || nc >= N) continue;
			if(visited[nr][nc]) continue;
			
			if(board[nr][nc] == 1)
			{
				arr[chickenNum].push_back({nr, nc, cur.dist + 1});
			}
				
			visited[nr][nc] = true;
			Q.push({nr, nc, cur.dist + 1});
		}
	}
}

void solve(int depth, int lastSelected)
{
	if(depth == 0)
	{
		int temp = 0;
		for(int col = 0; col < arr[0].size(); col++)
		{
			int asd = 1e9;
			for(int row = 0; row < cand.size(); row++)
			{
				asd = min(asd, arr[cand[row]][col].dist);
			}
			temp += asd;
		}
		ans = min(ans, temp);
		return;
	}

	for(int i = lastSelected + 1; i <= chicken.size() - depth; i++)
	{
		cand.push_back(i);
		solve(depth - 1, i);
		cand.pop_back();
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> N >> M;
	for(int i = 0; i < N; i++) for(int j = 0; j < N; j++)
	{
		cin >> board[i][j];
		if(board[i][j] == 2)
		{
			arr.push_back({});
			chicken.push_back({i, j});

		}
	}

	int idx = 0;
	for(int i = 0; i < N; i++) for(int j = 0; j < N; j++)
	{
		if(board[i][j] == 2)
		{
			BFS(i, j, idx);
			sort(arr[idx].begin(), arr[idx].end());
			idx++;
		}
	}
		
	solve(M, -1);

	cout << ans << '\n';
	return 0;
}