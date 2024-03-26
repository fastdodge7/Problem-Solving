#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <queue>

using namespace std;

int N, M;
int dp[1001][1001];
int name[1001];

int solve(int idx, int len)
{
	if(idx >= N) return 0;

	if(dp[idx][len]) return dp[idx][len];

	dp[idx][len] = (M - len + 1) * (M - len + 1) + solve(idx + 1, name[idx] + 1);
	if(len + name[idx] <= M)
		dp[idx][len] = min(dp[idx][len], solve(idx + 1, len + name[idx] + 1));
	return dp[idx][len];
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> N >> M;
	for(int i = 0; i < N; i++)
		cin >> name[i];

	cout << solve(0, 0) << '\n';
	

	return 0;
}