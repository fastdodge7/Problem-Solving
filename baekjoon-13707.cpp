#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

constexpr int MOD = 1e9;

int N, K;
int dp[10000][5000];

int Comb(int n, int r)
{
	if(r == 0) return 1;
	if(r == 1) return n;

	if(n - r < r) return Comb(n, n - r);

	if(dp[n][r] > 0) return dp[n][r];

	return dp[n][r] = ((Comb(n - 1, r - 1) % MOD) + (Comb(n - 1, r) % MOD)) % MOD;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	
	cin >> N >> K;
	cout << Comb(K + N - 1, N);
	return 0;
}