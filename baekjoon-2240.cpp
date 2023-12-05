#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int T, W;
int dp[1000][31][2];
int arr[1000];

int DFS(int time, int move, int pos)
{
	if (time == T - 1)
		return dp[time][move][pos] = (arr[time] == pos + 1 ? 1 : 0);

	if (dp[time][move][pos] >= 0)
		return dp[time][move][pos];

	if (arr[time + 1] == pos + 1 || move == W)
		return dp[time][move][pos] = DFS(time + 1, move, pos) + (arr[time] == pos + 1 ? 1 : 0);
	
	return dp[time][move][pos] = max(DFS(time + 1, move, pos), DFS(time + 1, move + 1, (pos + 1) % 2)) + (arr[time] == pos + 1 ? 1 : 0);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> T >> W;
	for (int i = 0; i < T; i++)
		cin >> arr[i];

	fill(&dp[0][0][0], &dp[999][30][1] + 1, -10000);

	cout << max(DFS(0, 0, 0), DFS(0, 1, 1));


	return 0;
}