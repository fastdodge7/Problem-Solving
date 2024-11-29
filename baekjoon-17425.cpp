#include <iostream>
#include <algorithm>

using namespace std;

constexpr int MAX_N = 1000001;

int T;
long long dp[MAX_N];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	fill(dp, dp + MAX_N, 1);
	for(int i = 2; i < MAX_N; i++)
	{
		for(int m = 1; i * m < MAX_N; m++)
			dp[i * m] += i;
	}

	for(int i = 2; i < MAX_N; i++)
		dp[i] += dp[i - 1];
	
	cin >> T;
	for(int test_case = 1; test_case <= T; test_case++)
	{
		int N; cin >> N;
		cout << dp[N] << '\n';
	}
	return 0;
}