#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <deque>
#include <cassert>
#include <queue>
#include <unordered_map>

using namespace std;

int N, M;
int cost[5001];
int cal[5001];
int dp[2][10001];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	while(1)
	{
		cin >> N;
		double temp; cin >> temp;
		M = (temp * 100 + 0.5);

		if(N == M && N == 0) return 0;
		for(int i = 1; i <= N; i++)
		{
			cin >> cal[i];
			double t; cin >> t;
			cost[i] = (t * 100 + 0.5);
		}
		
		for(int i = 1; i <= N; i++)
		{
			for(int m = 1; m <= M; m++)
			{
				int r = i % 2 == 1 ? 1 : 0;

				dp[r][m] = max(dp[r][m - 1], dp[(r - 1) * -1][m]);
				if(m >= cost[i])
				{
					dp[r][m] = max(dp[r][m], dp[(r - 1) * -1][m - cost[i]] + cal[i]);
					dp[r][m] = max(dp[r][m], dp[r][m - cost[i]] + cal[i]);
				}
			}
		}
		cout << max(dp[0][M], dp[1][M]) << '\n';
		fill(&dp[0][0], &dp[1][10000] + 1, 0);
	}
	
	return 0;
}