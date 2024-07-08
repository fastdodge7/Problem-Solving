#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

int N, M;
int dp[101][101];
bool cannot[101];

void DFS(int curDay, int curCost, int curCoupons)
{
	if(curDay > N) return;
	if(curCost >= dp[curDay][curCoupons]) return;
	
	dp[curDay][curCoupons] = curCost;

	if(cannot[curDay + 1])
		DFS(curDay + 1, curCost, curCoupons);
	else
		DFS(curDay + 1, curCost + 10000, curCoupons);

	DFS(curDay + 3, curCost + 25000, curCoupons + 1);
	DFS(curDay + 5, curCost + 37000, curCoupons + 2);

	if(curCoupons >= 3 && !cannot[curDay + 1])
	{
		DFS(curDay + 1, curCost, curCoupons - 3);
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	fill(&dp[0][0], &dp[100][100] + 1, 1e9);
	cin >> N >> M;
	for(int i = 0; i < M; i++)
	{
		int k; cin >> k;
		cannot[k] = true;
	}
	
	DFS(0, 0, 0);

	cout << *min_element(&dp[N][0], &dp[N][100] + 1);
	return 0;
}