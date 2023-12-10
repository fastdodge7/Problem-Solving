#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, M;

int dy[4] = { 0, -1, 0, 1 };
int dx[4] = { -1, 0, 1, 0 };

int arr[500][500];
bool visited[500][500];
int ans = 0;

void DFS(int r, int c, int depth, int acc) 
{
	if (depth == 4) {
		ans = max(ans, acc + arr[r][c]);
		return;
	}

	visited[r][c] = true;

	for (int i = 0; i < 4; i++)
	{
		int ny = r + dy[i];
		int nx = c + dx[i];
		if (ny < 0 || ny >= N || nx < 0 || nx >= M) continue;
		if (visited[ny][nx]) continue;
		DFS(ny, nx, depth + 1, acc + arr[r][c]);
	}

	visited[r][c] = false;
}

void checkT(int r, int c)
{
	for (int rot = 0; rot < 4; rot++)
	{
		int temp = arr[r][c];
		for (int i = 0; i < 4; i++)
		{
			if (rot == i) continue;
			int nr = r + dy[i];
			int nc = c + dx[i];
			if (nr < 0 || nr >= N || nc < 0 || nc >= M)
				break;
			temp += arr[nr][nc];
		}
		ans = max(temp, ans);
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> N >> M;
	for (int i = 0; i < N; i++) for(int j = 0; j < M; j++)
		cin >> arr[i][j];

	for (int i = 0; i < N; i++) for (int j = 0; j < M; j++)
		DFS(i, j, 1, 0);
	for (int i = 0; i < N; i++) for (int j = 0; j < M; j++)
		checkT(i, j);

	cout << ans;
	return 0;
}