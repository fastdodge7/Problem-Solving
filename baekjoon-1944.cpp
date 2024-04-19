#include <iostream>
#include <string>
#include <queue>
#include <algorithm>

using namespace std;

constexpr int WALL = 999;
constexpr int START = 251;

int dy[4] = {0, -1, 0, 1};
int dx[4] = {-1, 0, 1, 0};

typedef struct Node{
	int r, c;
	int dist;
}Node;

typedef struct Edge{
	int a, b;
	int dist;

	bool operator<(const Edge& other) const {
		return dist < other.dist;
	}
}Edge;

int N, M;

int map[50][50];
int visited[50][50];

int parent[252];
vector<Edge> arr;

int Find(int a)
{
	if(parent[a] == 0)
		return a;
	return parent[a] = Find(parent[a]);
}

void Union(int a, int b)
{
	a = Find(a);
	b = Find(b);

	if(a == b) return;
	parent[b] = a;
}

void BFS(int r, int c, int nodeNum)
{
	fill(&visited[0][0], &visited[49][49] + 1, 0);
	queue<Node> Q; Q.push({r, c, 0});
	visited[r][c] = 0;

	while(!Q.empty())
	{
		auto cur = Q.front(); Q.pop();
		for(int i = 0; i < 4; i++)
		{
			int nr = cur.r + dy[i];
			int nc = cur.c + dx[i];
			if(nr < 0 || nr >= N || nc < 0 || nc >= N) continue;
			if(map[nr][nc] == WALL) continue;
			
			if(visited[nr][nc] > 0) continue;

			if(map[nr][nc] > 0)
			{
				visited[nr][nc] = cur.dist + 1;
				arr.push_back({nodeNum, map[nr][nc], cur.dist + 1});
				Q.push({nr, nc, visited[nr][nc]});
				continue;
			}
			
			visited[nr][nc] = cur.dist + 1;
			Q.push({nr, nc, visited[nr][nc]});
		}
	}
}

int findMST()
{
	sort(arr.begin(), arr.end());

	int ans = 0;
	int cnt = 0;
	for(int i = 0; i < arr.size(); i++)
	{
		if(Find(arr[i].a) == Find(arr[i].b)) continue;
		ans += arr[i].dist;
		Union(arr[i].a, arr[i].b);
		cnt++;
	}

	if(cnt < M)	return -1;
	return ans;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	pair<int, int> startPos;
	cin >> N >> M;
	int cnt = 1;
	for(int i = 0; i < N; i++)
	{
		string temp; cin >> temp;
		for(int j = 0; j < N; j++)
		{
			if(temp[j] == '1')
				map[i][j] = WALL;
			if(temp[j] == 'S')
			{
				startPos = {i, j};
				map[i][j] = START;
			}
			if(temp[j] == 'K')
				map[i][j] = cnt++;
		}
	}

	for(int i = 0; i < N; i++) for(int j = 0; j < N; j++)
	{
		if(map[i][j] != WALL && map[i][j] > 0)
			BFS(i, j, map[i][j]);
	}

	cout << findMST() << '\n';
	
	return 0;
}