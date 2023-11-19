#include <iostream>
#include <algorithm>

using namespace std;

int arr[100000];
int dp[100000][2];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int N; cin >> N;
	for(int i = 0; i < N; i++)
		cin >> arr[i];

	dp[0][0] = arr[0];
	dp[0][1] = 0;

	for(int i = 1; i < N; i++)
	{
		dp[i][0] = max(dp[i - 1][0] + arr[i], arr[i]);
		dp[i][1] = max(dp[i - 1][0], dp[i - 1][1] + arr[i]);
	}

	int ans = -1e9;
	for(int i = 1; i < N; i++)
		ans = max(ans, max(dp[i][0], dp[i][1]));
	
	cout << ans;
	return 0;
}