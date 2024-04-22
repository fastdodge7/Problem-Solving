#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <queue>
#include <cmath>

using namespace std;

int T, k;
pair<int, int> coin[101];
int dp[101][10001];
bool visited[101][10001];

int solve(int lastType, int total)
{
	if(lastType < 0) return 0;
	if(total < 0) return 0;

	if(visited[lastType][total]) return dp[lastType][total];
	visited[lastType][total] = true;
	if(total == 0) return dp[lastType][total] = 1;

	int temp = 0;
	for(int cnt = 0; cnt <= coin[lastType].second; cnt++)
	{
		temp += solve(lastType - 1, total - ((coin[lastType].first) * cnt));
	}
	return dp[lastType][total] = temp;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> T >> k;
	for(int i = 1; i <= k; i++)
	{
		cin >> coin[i].first >> coin[i].second;
	}

	sort(coin + 1, coin + k + 1);
	cout << solve(k, T);

	

	return 0;
}