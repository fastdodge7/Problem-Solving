#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int dy[4] = { 0, -1, 0, 1 };
int dx[4] = { -1, 0, 1, 0 };

char arr[20][20];
bool visited['Z' - 'A' + 1];
int N, M;

int ans = 0;

void DFS(int r, int c, char last, int depth)
{
	visited[arr[r][c] - 'A'] = true;
	ans = max(ans, depth);

	for (int i = 0; i < 4; i++)
	{
		int nr = r + dy[i];
		int nc = c + dx[i];
		if (nr < 0 || nr >= N || nc < 0 || nc >= M) continue;
		if (visited[arr[nr][nc] - 'A']) continue;
		if (arr[nr][nc] == last) continue;
		DFS(nr, nc, arr[nr][nc], depth + 1);
	}

	visited[arr[r][c] - 'A'] = false;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> N >> M;
	for (int i = 0; i < N; i++)
	{
		string str; cin >> str;
		for (int j = 0; j < M; j++)
			arr[i][j] = str[j];
	}
	DFS(0, 0, '.', 1);
	cout << ans;
	return 0;
}