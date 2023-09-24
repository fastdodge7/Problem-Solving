#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <queue>

using namespace std;

int N, M;
int board[21][21];
int checker[21][21];
int arr[5];

int ans = 1e9;

void drawBoarderline(int y, int x, int d1, int d2)
{
	for (int i = 0; i <= d1; i++)
	{
		for (int j = 0; j <= d2; j++)
		{
			if (i != d1 && j != d2) {
				checker[y - i + j][x + i + j + 1] = 5;
				arr[4] += board[y - i + j][x + i + j + 1];
			}
			checker[y - i + j][x + i + j] = 5;
			arr[4] += board[y - i + j][x + i + j];
		}
	}
}

void check(int y, int x, int d1, int d2)
{
	for (int r = 1; r <= N; r++)
	{
		for (int c = 1; c <= N; c++)
		{
			if (1 <= c && c <= x + d1 && 1 <= r && r < y)
			{
				if (checker[r][c] != 0) continue;
				arr[0] += board[r][c];
				checker[r][c] = 1;
			}
			else if (x + d1 < c && c <= N && 1 <= r && r <= y - d1 + d2)
			{
				if (checker[r][c] != 0) continue;
				arr[1] += board[r][c];
				checker[r][c] = 2;
			}
			else if (1 <= c && c < x + d2 && y <= r && r <= N)
			{
				if (checker[r][c] != 0) continue;
				arr[2] += board[r][c];
				checker[r][c] = 3;
			}
			else if (x + d2 <= c && c <= N && y - d1 + d2 < r && r <= N)
			{
				if (checker[r][c] != 0) continue;
				arr[3] += board[r][c];
				checker[r][c] = 4;
			}
		}
	}
	int maxVal = 0;
	int minVal = 1e9;
	for (int i = 0; i < 5; i++)
	{
		maxVal = max(arr[i], maxVal);
		minVal = min(arr[i], minVal);
	}
	ans = min(ans, maxVal - minVal);
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> N;
	for (int i = 1; i <= N; i++) for (int j = 1; j <= N; j++)
		cin >> board[i][j];

	for (int y = 1; y <= N; y++)
	{
		for (int x = 1; x <= N; x++)
		{
			int d1Max = min(y - 1, N - x);
			int d2Max = min(N - y, N - x);
			for (int d1 = 1; d1 <= d1Max; d1++)
			{
				for (int d2 = 1; d2 <= d2Max; d2++)
				{
					if (y - d1 + d2 > N || x + d1 + d2 > N) break;
					fill(arr, arr + 5, 0);
					fill(&checker[0][0], &checker[20][20] + 1, 0);

					drawBoarderline(y, x, d1, d2);
					check(y, x, d1, d2);
				}
			}
		}
	}

	cout << ans << '\n';
	return 0;
}