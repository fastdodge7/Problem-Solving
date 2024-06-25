#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, M, R;
int itemCnt[101];
int matrix[101][101];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	fill(&matrix[0][0], &matrix[100][100] + 1, 1e9);
	for(int i = 0; i <= N; i++)
		matrix[i][i] = 0;

	cin >> N >> M >> R;
	for(int i = 1; i <= N; i++)
		cin >> itemCnt[i];
	for(int i = 0; i < R; i++)
	{
		int a, b, c; cin >> a >> b >> c;
		matrix[a][b] = matrix[b][a] = c;
	}

	for(int k = 1; k <= N; k++)
	{
		for(int i = 1; i <= N; i++)
		{
			for(int j = 1; j <= N; j++)
			{
				if(matrix[i][k] + matrix[k][j] < matrix[i][j])
					matrix[i][j] = matrix[i][k] + matrix[k][j];
			}
		}
	}

	int ans = 0;
	for(int drop = 1; drop <= N; drop++)
	{
		int cand = 0;
		for(int dest = 1; dest <= N; dest++)
		{
			if(drop == dest || matrix[drop][dest] <= M) 
			{
				cand += itemCnt[dest];
			}
		}
		ans = max(ans, cand);
	}

	cout << ans;
	return 0;
}