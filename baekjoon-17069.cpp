#include <iostream>
using namespace std;

int N;
long long dp[32][32][3];
int board[32][32];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	
	cin >> N;
	for(int i = 0; i < N; i++) for(int j = 0; j < N; j++)
		cin >> board[i][j];
		
	for(int i = 1; i < N; i++)
	{
		if(board[0][i] == 1) break;
		dp[0][i][0] = 1;
	}
	
	for(int i = 1; i < N; i++)
	{
		for(int j = 1; j < N; j++)
		{
			if(board[i][j] == 1) continue;
			dp[i][j][0] = dp[i][j - 1][0] + dp[i][j - 1][1]; // 가로 방향
			
			if(board[i - 1][j] == 0 && board[i][j - 1] == 0)
				dp[i][j][1] = dp[i - 1][j - 1][0] + dp[i - 1][j - 1][1] + dp[i - 1][j - 1][2]; // 대각선선 방향
			
			dp[i][j][2] = dp[i - 1][j][1] + dp[i - 1][j][2]; // 가로 방향
		}
	}
	cout << dp[N - 1][N - 1][0] + dp[N - 1][N - 1][1] + dp[N - 1][N - 1][2];
	return 0;
}