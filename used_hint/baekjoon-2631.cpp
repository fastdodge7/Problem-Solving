#include <iostream>
#include <algorithm>
using namespace std;

int N;
int arr[201];
int dp[201];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> N;
	for (int i = 1; i <= N; i++)
	{
		cin >> arr[i];
		dp[i] = 1;
	}

	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j < i; j++)
		{
			if (arr[j] < arr[i])
				dp[i] = max(dp[i], dp[j] + 1);
		}
	}

	cout << N - *max_element(dp, dp + N + 1);
	return 0;
}