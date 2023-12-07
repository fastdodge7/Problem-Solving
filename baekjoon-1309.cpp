#include <iostream>
using namespace std;

int dp[100001][2][2];

int main() {
	
	dp[1][0][0] = dp[1][1][0] = dp[1][0][1] = 1;
	for(int i = 2; i <= 100000; i++)
	{
		dp[i][0][0] = (dp[i - 1][0][0] + dp[i - 1][1][0]) % 9901;
		dp[i][0][0] = (dp[i][0][0] + dp[i - 1][0][1]) % 9901;
		dp[i][1][0] = (dp[i - 1][0][0] + dp[i - 1][0][1]) % 9901;
		dp[i][0][1] = (dp[i - 1][0][0] + dp[i - 1][1][0]) % 9901;
	}
	
	int n; cin >> n;
	cout << (((dp[n][0][0] + dp[n][1][0]) % 9901) + dp[n][0][1]) % 9901;
	
	return 0;
}