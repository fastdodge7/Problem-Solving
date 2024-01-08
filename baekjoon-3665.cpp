#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <string>

using namespace std;

int T;
int N, M;
int indegree[501];
int preRank[501];
int matrix[501][501];

vector<int> topologySort()
{
	queue<pair<int, int>> Q;
	for (int i = N; i > 0; i--)
	{
		if (indegree[i] == 0)
			Q.push({ i, N });
	}
	vector<int> rankList;
	while (!Q.empty())
	{
		auto cur = Q.front(); Q.pop();
		rankList.push_back(cur.first);

		for (int i = 1; i <= N; i++)
		{
			if (matrix[cur.first][i] == 1)
			{
				if (--indegree[i] == 0)
					Q.push({ i, cur.second - 1 });
			}
		}
	}
	reverse(rankList.begin(), rankList.end());
	return rankList;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> T;
	for (int test_case = 1; test_case <= T; test_case++)
	{
		cin >> N;
		for (int i = 1; i <= N; i++)
			cin >> preRank[i];

		for (int i = N; i > 0; i--) for (int j = i - 1; j > 0; j--)
			matrix[preRank[i]][preRank[j]] = 1;
				

		cin >> M;
		for (int i = 0; i < M; i++)
		{
			int a, b; cin >> a >> b;
			swap(matrix[a][b], matrix[b][a]);
		}

		for (int i = 1; i <= N; i++) for (int j = 1; j <= N; j++)
		{
			if (matrix[i][j] == 1)
				indegree[j] += 1;
		}

		vector<int> ans = topologySort();
		
		if (ans.size() != N)
			cout << "IMPOSSIBLE\n";
		else
		{
			for (int i = 0; i < ans.size(); i++)
				cout << ans[i] << ' ';
			cout << '\n';
		}

		fill(&matrix[0][0], &matrix[500][500] + 1, 0);
		fill(indegree, indegree + 501, 0);
	}
	return 0;
}