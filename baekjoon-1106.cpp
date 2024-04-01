#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <queue>

using namespace std;

int C, N;
int dp[1001];
pair<int, int> arr[20];

int solve(int cur)
{
	if(cur <= 0) return 0;
	
	for(int i = 0; i < N; i++)
	{
		if(cur - arr[i].first >= 0)
			dp[cur] = min(dp[cur], solve(cur - arr[i].second) + arr[i].first);
	}

	return dp[cur];
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	fill(dp, dp + 1001, 1e9);

	cin >> C >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> arr[i].first >> arr[i].second;
	}

	dp[0] = 0;
	for(int i = 1; i <= C; i++)
	{
		for(int j = 0; j < N; j++)
		{
			dp[i] = min(dp[i], dp[max(0, i - arr[j].second)] + arr[j].first);
		}
	}

	cout << dp[C];



	return 0;
}