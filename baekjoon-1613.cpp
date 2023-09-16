#include <algorithm>
#include <iostream>

using namespace std;

int N, M;
int adj[401][401];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	fill(&adj[0][0], &adj[400][400] + 1, 1e9);
	
	cin >> N >> M;
	for (int i = 0; i < M; i++)
	{
		int a, b; cin >> a >> b;
		adj[a][b] = 1;
	}


	for (int k = 1; k <= N; k++)
	{
		for (int i = 1; i <= N; i++)
		{
			for (int j = 1; j <= N; j++)
			{
				adj[i][j] = min(adj[i][j], adj[i][k] + adj[k][j]);
			}
		}
	}

	int s; cin >> s;
	for (int i = 0; i < s; i++)
	{
		int a, b; cin >> a >> b;
		bool resA = adj[a][b] < 1e9;
		bool resB = adj[b][a] < 1e9;
		if (resA) cout << -1 << '\n';
		else if (resB) cout << 1 << '\n';
		else cout << 0 << '\n';
	}

	return 0;
}