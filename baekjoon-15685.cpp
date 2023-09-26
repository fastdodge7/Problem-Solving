#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <queue>

using namespace std;

int N, M;
int dy[4] = { 0, -1, 0, 1 };
int dx[4] = { 1, 0, -1, 0 };
int board[101][101];
int check[101][101];

int ans = 1e9;

void drawLine(int x, int y, int dir, int gen)
{
	vector<int> vec = { dir };
	int curX = x, curY = y;
	for (int g = 0; g < gen; g++)
	{
		for (int i = vec.size() - 1; i >= 0; i--)
			vec.push_back((vec[i] + 1) % 4);
	}
	check[curY][curX] = 1;
	for (int i = 0; i < vec.size(); i++)
	{
		curY += dy[vec[i]];
		curX += dx[vec[i]];
		check[curY][curX] = 1;
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> N;
	for (int i = 0; i < N; i++)
	{
		int x, y, dir, gen; cin >> x >> y >> dir >> gen;
		drawLine(x, y, dir, gen);
	}

	int ans = 0;
	for (int i = 0; i < 100; i++)
	{
		for (int j = 0; j < 100; j++)
		{
			if (check[i][j] && check[i + 1][j] && check[i][j + 1] && check[i + 1][j + 1])
				ans++;
		}
	}
	
	cout << ans << '\n';
	return 0;
}