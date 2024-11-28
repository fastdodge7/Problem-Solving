#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int dy[4] = {0, -1, 0, 1};
int dx[4] = {-1, 0, 1, 0};

typedef struct Coin{
	bool isDropped() const { return r == -1 && c == -1; }
	int r, c;
}Coin;

string board[20];
int N, M;

Coin move(int dir, Coin cur)
{
	int nr = cur.r + dy[dir];
	int nc = cur.c + dx[dir];

	if(nr < 0 || nr >= N || nc < 0 || nc >= M)
		return {-1, -1};
	
	if(board[nr][nc] == '#') return cur;
	
	return {nr, nc};
}

int DFS(Coin a, Coin b, int depth)
{
	if(depth > 10) return 20;
	int ret = 20;
	for(int dir = 0; dir < 4; dir++)
	{
		Coin newA = move(dir, a);
		Coin newB = move(dir, b);
		if(newA.isDropped() && newB.isDropped()) continue;
		if(newA.isDropped() || newB.isDropped())
		{
			ret = min(depth, ret);
			continue;
		}
		ret = min(ret, DFS(newA, newB, depth + 1));
	}
	return ret;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	
	cin >> N >> M;
	for(int i = 0; i < N; i++)
		cin >> board[i];
	
	vector<Coin> arr;
	for(int i = 0; i < N; i++)
	{
		for(int j = 0; j < M; j++)
		{
			if(board[i][j] == 'o')
				arr.push_back({i, j});
		}
	}

	int ans = DFS(arr[0], arr[1], 1);
	cout << (ans > 10 ? -1 : ans);
	return 0;
}