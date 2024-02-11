#include <iostream>
#include <cmath>
using namespace std;

int N;
int arr[1000];
int dp[1000];

int main() {
	cin >> N;
	for(int i = 0; i < N; i++)
		cin >> arr[i];
		
	dp[1] = abs(arr[1] - arr[0]);
	for(int i = 2; i < N; i++)
	{
		dp[i] = abs(arr[i] - arr[0]);
		for(int j = 1; j <= i; j++)
		{
			dp[i] = max(dp[i], dp[j - 1] + abs(arr[i] - arr[j]));
		}
	}
	cout << dp[N - 1];
	return 0;
}