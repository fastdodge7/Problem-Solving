#include <iostream>
#include <algorithm>

using namespace std;

int N, T;

int dp[101][10001];
int score[101];
int studyTime[101];

int main() {
	// your code goes here
	cin >> N >> T;
	for(int i = 1; i <= N; i++)
		cin >>studyTime[i] >>  score[i];
	
	for(int i = 1; i <= N; i++)
	{
		for(int j = 1; j <= T; j++)
		{
			if(j >= studyTime[i])
				dp[i][j] = max(dp[i - 1][j], max(dp[i - 1][j -studyTime[i]] + score[i], dp[i][j - 1]));
			else
				dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
		}
	}
	cout << dp[N][T];
	return 0;
}