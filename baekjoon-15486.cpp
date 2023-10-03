#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <queue>

using namespace std;

int N;

int dp[1500001];
pair<int, int> arr[1500001];

int solve(int n)
{  
	if (n > N) return 0;
	if (dp[n] > 0) return dp[n];
	if ((arr[n].first - 1) + n > N) return dp[n] = solve(n + 1);

	return dp[n] = max(solve(n + arr[n].first) + arr[n].second, solve(n + 1));
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> N;
	for (int i = 1; i <= N; i++)
		cin >> arr[i].first >> arr[i].second;

	solve(1);

	cout << dp[1] << '\n';
	return 0;
}