#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
using namespace std;

int N, K;

const int INF = 1e9;

int dp[200001];

int BFS()
{
	queue<pair<int, int>> Q; Q.push({N, 0});
	dp[N] = 0;
	
	while(!Q.empty())
	{
		int cur = Q.front().first;
		int step = Q.front().second; Q.pop();
		if(cur == K)
			continue;
			
		if(cur + 1 <= 100000 && dp[cur + 1] > step )
		{
			dp[cur + 1] = step + 1;
			Q.push({cur + 1, step + 1});
		}
			
			
		if(cur - 1 >= 0 && dp[cur - 1] > step )
		{
			dp[cur - 1] = step + 1;
			Q.push({cur - 1, step + 1});
		}
			
		if(2 * cur <= 200000 && dp[2 * cur] > step)
		{
			dp[2 * cur] = step;
			Q.push({2 * cur, step});
		}
	}
	return dp[K];
}

int main() {
	cin >> N >> K;
	fill(dp, dp + 200001, INF);
	
	cout << BFS() << '\n';
	return 0;
}