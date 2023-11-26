#include<iostream>
#include<string>
#include<algorithm>

using namespace std;

int dp[11];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	dp[1] = 1;
	dp[2] = 2;
	dp[3] = 4;

	for(int i = 4; i < 11; i++)
		dp[i] = dp[i - 1] + dp[i - 2] + dp[i - 3];

	int N; cin >> N;
	for(int i = 0; i < N; i++)
	{
		int k; cin >> k;
		cout << dp[k] << '\n';
	}
	
	
	return 0;
}