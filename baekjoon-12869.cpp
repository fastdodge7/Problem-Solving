#include <iostream>
using namespace std;

constexpr int MOD = 1e9 + 7;

int N;
int init[3];
int dp[61][61][61];

int solve(int a, int b, int c)
{
	if(a <= 0 && b <= 0 && c <= 0)
		return 0;

	if(dp[a][b][c] < 1e9)
		return dp[a][b][c];
	
	dp[a][b][c] = min(dp[a][b][c], solve(max(a - 1, 0), max(b - 3, 0), max(c - 9, 0)) + 1);
	dp[a][b][c] = min(dp[a][b][c], solve(max(a - 1, 0), max(b - 9, 0), max(c - 3, 0)) + 1);
	dp[a][b][c] = min(dp[a][b][c], solve(max(a - 3, 0), max(b - 1, 0), max(c - 9, 0)) + 1);
	dp[a][b][c] = min(dp[a][b][c], solve(max(a - 3, 0), max(b - 9, 0), max(c - 1, 0)) + 1);
	dp[a][b][c] = min(dp[a][b][c], solve(max(a - 9, 0), max(b - 1, 0), max(c - 3, 0)) + 1);
	dp[a][b][c] = min(dp[a][b][c], solve(max(a - 9, 0), max(b - 3, 0), max(c - 1, 0)) + 1);
	
	return dp[a][b][c];
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	
	fill(&dp[0][0][0], &dp[60][60][60] + 1, 1e9);
	cin >> N;
	for(int i = 0; i < N; i++)
		cin >> init[i];

	cout << solve(init[0], init[1], init[2]);

	return 0;
}