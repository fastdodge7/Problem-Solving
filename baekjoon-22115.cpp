#include <iostream>
#include <algorithm>

using namespace std;

int N, K;
int dp[100001];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	fill(&dp[0], &dp[100000] + 1, 1e9);
	dp[0] = 0;
    
	cin >> N >> K;
	for(int i = 1; i <= N; i++)
	{
		int cur; cin >> cur;
		for(int j = K; j >= cur; j--)
			dp[j] = min(dp[j], dp[j - cur] + 1);
	}

	cout << (dp[K] > 100 ? -1 : dp[K]);
	return 0;
}