#include <iostream>
#include <string>
#include <vector>

using namespace std;

constexpr int O = 0;
constexpr int L = 1;
constexpr int A = 2;
constexpr int MOD = 1e6;

long long dp[1001][3][3][2];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	
	//fill(&dp[0][0][0][0], &dp[1000][2][2][1] + 1, -1);

	dp[2][O][O][false] = dp[2][O][A][false] = dp[2][A][O][false] = dp[2][A][A][false] = 1;
	dp[2][L][O][false] = dp[2][L][A][false] = dp[2][A][L][false] = dp[2][O][L][false] = 1;


	int N; cin >> N;

	for(int n = 3; n <= N; n++)
	{
		dp[n][O][O][false] = (dp[n - 1][O][A][false] + dp[n - 1][O][O][false]) % MOD;
		dp[n][A][O][false] = (dp[n - 1][O][A][false] + dp[n - 1][O][O][false]) % MOD;
		dp[n][O][A][false] = (dp[n - 1][A][O][false] + dp[n - 1][A][A][false]) % MOD;
		dp[n][A][A][false] = dp[n - 1][A][O][false];

		dp[n][L][O][false] = (dp[n - 1][O][A][false] + dp[n - 1][O][O][false]) % MOD;
		dp[n][L][A][false] = (dp[n - 1][A][A][false] + dp[n - 1][A][O][false]) % MOD;
		dp[n][O][L][false] = (dp[n - 1][L][O][false] + dp[n - 1][L][A][false]) % MOD;
		dp[n][A][L][false] = (dp[n - 1][L][O][false] + dp[n - 1][L][A][false]) % MOD;

		dp[n][O][O][true] = (dp[n - 1][O][O][true] + dp[n - 1][O][A][true] + dp[n - 1][O][L][false]) % MOD;
		dp[n][A][O][true] = (dp[n - 1][O][A][true] + dp[n - 1][O][O][true] + dp[n - 1][O][L][false]) % MOD;
		dp[n][O][A][true] = (dp[n - 1][A][O][true] + dp[n - 1][A][A][true] + dp[n - 1][A][L][false]) % MOD;
		dp[n][A][A][true] = (dp[n - 1][A][O][true] + dp[n - 1][A][L][false]) % MOD;
	}

	if(N == 1)
	{
		cout << 3;
		return 0;
	}
	if(N == 2)
	{
		cout << 8;
		return 0;
	}

	long long ans = 0;
	for(int i = 0; i < 3; i++) for(int j = 0; j < 3; j++) for(int k = 0; k < 2; k++)
		ans += dp[N][i][j][k];

	cout << ans;
	return 0;
}