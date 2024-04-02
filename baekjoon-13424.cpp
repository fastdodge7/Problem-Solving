#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

constexpr int INF = 1e9 + 7;

int T;
int N, M;
int matrix[101][101];
vector<int> members;

int main() {
	ios::sync_with_stdio(false);
	cout.tie(0); cin.tie(0);
	
	cin >> T;
	for(int test_case = 1; test_case <= T; test_case++)
	{
		fill(&matrix[0][0], &matrix[100][100] + 1, INF);
		members.clear();

		cin >> N >> M;
		for(int i = 0; i < M; i++)
		{
			int a, b, c; cin >> a >> b >> c;
			matrix[a][b] = matrix[b][a] = c;
		}
		int mems; cin >> mems;
		for(int i = 0; i < mems; i++)
		{
			int temp; cin >> temp;
			members.push_back(temp);
		}

		for(int i = 1; i <= N; i++)
			matrix[i][i] = 0;

		for(int k = 1; k <= N; k++)
		{
			for(int i = 1; i <= N; i++)
			{
				for(int j = 1; j <= N; j++)
				{
					matrix[i][j] = min(matrix[i][j], matrix[i][k] + matrix[k][j]);
				}
			}
		}

		int ans = 0;
		int sum = 1e9;
		for(int cand = 1; cand <= N; cand++)
		{
			int temp = 0;
			for(int mem : members)
			{
				temp += matrix[mem][cand];
			}
			if(temp < sum)
			{
				ans = cand;
				sum = temp;
			}
		}

		cout << ans << '\n';
	}
	return 0;
}