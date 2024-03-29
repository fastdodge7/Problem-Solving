#include <iostream>
using namespace std;

constexpr int MOD = 100000;
constexpr int Left = 0;
constexpr int Up = 1;

int N, M;
int dp[100][100][2][2];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	
	cin >> N >> M;

	for(int i = 1; i < M; i++)
		dp[0][i][Left][Left] = 1;
	
	for(int i = 1; i < N; i++)
		dp[i][0][Up][Up] = 1;
	
	for(int i = 1; i < N; i++)
	{
		for(int j = 1; j < M; j++)
		{
			dp[i][j][Left][Left] = (dp[i][j - 1][Left][Left] + dp[i][j - 1][Left][Up]) % MOD;
			dp[i][j][Left][Up] =  dp[i][j - 1][Up][Up];
			dp[i][j][Up][Left] = dp[i - 1][j][Left][Left];
			dp[i][j][Up][Up] = (dp[i - 1][j][Up][Up] + dp[i - 1][j][Up][Left]) % MOD;
		}
	}

	cout << (dp[N - 1][M - 1][Left][Left] + dp[N - 1][M - 1][Left][Up] + dp[N - 1][M - 1][Up][Up] + dp[N - 1][M - 1][Up][Left]) % MOD;
	return 0;
}