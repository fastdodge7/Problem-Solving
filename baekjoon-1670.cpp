#include <iostream>
#include <cmath>
using namespace std;

constexpr int MOD = 987654321;

int N;
long long dp[10001];

int main() {
	ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

	dp[0] = dp[2] = 1;

	for(int i = 4; i <= 10000; i += 2)
	{
		for(int j = 0; j <= i - 2; j += 2)
		{
			int left = j, right = i - 2 - j;
			dp[i] += (dp[left] * dp[right]) % MOD;
			dp[i] %= MOD;
		}
	}

	cin >> N;
	cout << dp[N];
	
	return 0;
}