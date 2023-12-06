#include <iostream>

using namespace std;

int T, W;
long long dp[31][31];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	for (int half = 0; half <= 30; half++)
		dp[0][half] = 1;

	for (int whole = 1; whole <= 30; whole++)
	{
		dp[whole][0] = dp[whole - 1][1];
		for (int half = 1; whole + half <= 30; half++)
			dp[whole][half] = dp[whole - 1][half + 1] + dp[whole][half - 1];
	}

	while (1)
	{
		int n; cin >> n;
		if (n == 0) break;
		cout << dp[n][0] << '\n';
	}

	return 0;
}