#include <iostream>
using namespace std;

long long dp[10001][4];
/*

dp[N][1] = dp[N - 1][1];
dp[N][2] = dp[N - 2][2] + dp[N - 2][1];
dp[N][3] = dp[N - 3][3] + dp[N - 3][2] + dp[N - 3][1];
*/

int main() {
	dp[1][1] = 1;
	dp[2][2] = dp[2][1] = 1;
	dp[3][3] = dp[3][2] = dp[3][1] = 1;
	
	for(int i = 4; i <= 10000; i++)
	{
		dp[i][1] = dp[i - 1][1];
		dp[i][2] = dp[i - 2][2] + dp[i - 2][1];
		dp[i][3] = dp[i - 3][3] + dp[i - 3][2] + dp[i - 3][1];
	}
	
	int T; cin >> T;
	for(int i = 0; i < T; i++)
	{
		int a; cin >> a;
		cout << dp[a][1] + dp[a][2] + dp[a][3] << '\n';
	}
	
	
	return 0;
}