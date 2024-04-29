#include <iostream>
#include <algorithm>

using namespace std;

int N;
int arr[5000];
int dp[5000][5000];

int solve(int start, int end)
{
	if(start >= end) return 0;
	if(dp[start][end] >= 0) return dp[start][end];


	if(arr[start] == arr[end])
		return dp[start][end] = solve(start + 1, end - 1);

	return dp[start][end] = min(solve(start + 1, end), solve(start, end - 1)) + 1;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	
	fill(&dp[0][0], &dp[4999][4999] + 1, -1);

	cin >> N;
	for(int i = 0; i < N; i++)
		cin >> arr[i];

	cout << solve(0, N - 1);
		
	return 0;
}