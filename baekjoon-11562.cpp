#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int N, M, K;
int matrix[251][251];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	fill(&matrix[0][0], &matrix[250][250] + 1, 1e9);

	cin >> N >> M;
	for(int i = 0; i < M; i++)
	{
		int u, v, b; cin >> u >> v >> b;
		matrix[u][v] = 0;
		matrix[v][u] = (b == 0 ? 1 : 0);
	}

	for(int k = 1; k <= N; k++)
	{
		for(int i = 1; i <= N; i++)
		{
			for(int j = 1; j <= N; j++)
			{
				if(i == j)
				{
					matrix[i][i] = 0;
					continue;
				}
				if(matrix[i][k] + matrix[k][j] < matrix[i][j])
					matrix[i][j] = matrix[i][k] + matrix[k][j];
			}
		}
	}

	cin >> K;
	for(int i = 0; i < K; i++)
	{
		int a, b; cin >> a >> b;
		cout << matrix[a][b] << '\n';
	}

	return 0;
}