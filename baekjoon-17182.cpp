#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int N, K;
int matrix[10][10];
int ans = 1e9;

void DFS(int start, int visited, int cost)
{	
	if(visited & (1 << start)) return;

	visited = visited | (1 << start);

	if(visited == (1 << N) - 1)
	{
		ans = min(ans, cost);
		return;
	}

	for(int i = 0; i < N; i++)
	{
		if(i == start) continue;
		DFS(i, visited, cost + matrix[start][i]);
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> N >> K;
	for(int i = 0; i < N; i++) for(int j = 0; j < N; j++)
		cin >> matrix[i][j];
	
	for(int k = 0; k < N; k++)
	{
		for(int i = 0; i < N; i++)
		{
			for(int j = 0; j < N; j++)
				matrix[i][j] = min(matrix[i][j], matrix[i][k] + matrix[k][j]);
		}
	}

	DFS(K, 0, 0);

	cout << ans << '\n';
	return 0;
}