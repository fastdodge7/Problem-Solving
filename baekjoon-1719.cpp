#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <queue>

using namespace std;

int N, M;
int matrix[201][201];
int ans[201][201];


int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	fill(&matrix[0][0], &matrix[200][200] + 1, 1e9);

	cin >> N >> M;
	for (int i = 0; i < M; i++)
	{
		int a, b, c; cin >> a >> b >> c;
		matrix[a][b] = matrix[b][a] = c;
		ans[a][b] = b; ans[b][a] = a;
	}

	for (int k = 1; k <= N; k++)
	{
		for (int i = 1; i <= N; i++)
		{
			for (int j = 1; j <= N; j++)
			{
				if (i == j) continue;
				if (matrix[i][j] > matrix[i][k] + matrix[k][j])
				{
					matrix[i][j] = matrix[i][k] + matrix[k][j];
					ans[i][j] = ans[i][k];
				}
			}
		}
	}

	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			if (ans[i][j] == 0)
				cout << "- ";
			else
				cout << ans[i][j] << ' ';
		}
		cout << '\n';
	}

	return 0;
}