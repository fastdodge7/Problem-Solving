#include <iostream>
#include <algorithm>

using namespace std;

constexpr long long MOD = 1e9;

int N;
long long dp[2];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> N;

	long long ans = (N == 2 ? 1 : 0);
	dp[1] = 1;
	for(int i = 3; i <= N; i++)
	{
		ans = ((i - 1) * (dp[1] + dp[0])) % MOD;
		dp[0] = dp[1];
		dp[1] = ans;
	}

	cout << ans;
	return 0;
}