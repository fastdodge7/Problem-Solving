#include <iostream>
#include <algorithm>
using namespace std;

constexpr int INF = 1e9+7;

int N, M;
int matrix[101][101];

int main() {
	ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
	
	cin >> N >> M;
	fill(&matrix[0][0], &matrix[100][100] + 1, INF);
	for(int i = 0; i < M; i++)
	{
		int a, b, c;
		cin >> a >> b >>c;
		matrix[a][b]= min(matrix[a][b], c);
	}
	
	for(int k = 1; k <= N; k++)
	{
		for(int i = 1; i <= N; i++)
		{
			for(int j = 1; j <= N; j++)
			{
				if(i == j) continue;
				matrix[i][j] = min(matrix[i][j], matrix[i][k] + matrix[k][j]);
			}
		}
	}
	
	for(int i = 1; i <= N; i++)
	{
		for(int j = 1; j <= N; j++)
			cout << (matrix[i][j] == INF ? 0 : matrix[i][j]) << ' ';
		cout << '\n';
	}
	
	return 0;
}