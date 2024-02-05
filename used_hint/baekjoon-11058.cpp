#include <iostream>
#include <algorithm>

using namespace std;

int N;
long long dp[101];

int main() {
	// your code goes here
	cin >> N;
	dp[1] = 1;
	dp[2] = 2;
	dp[3] = 3;
	dp[4] = 4;
	dp[5] = 5;

	for(int i = 6; i <= N; i++)
	{
		dp[i] = dp[i - 1] + 1;
		for(int j = 3; i - 3 >= j; j++)
		{
			dp[i] = max(dp[i], dp[j - 1] * (i - j));
		}
		
	}
	cout << dp[N];
	return 0;
}