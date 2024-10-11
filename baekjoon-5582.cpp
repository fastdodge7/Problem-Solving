#include <iostream>
#include <string>
#include <queue>
#include <algorithm>
#include <cassert>

using namespace std;

string a, b;
int dp[4001][4001];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	cin >> a >> b;

	for(int i = 0; i < a.size(); i++)
	{
		for(int j = 0; j < b.size(); j++)
			dp[i + 1][j + 1] = a[i] == b[j] ? dp[i][j] + 1 : 0;
	}

	int ans = 0;
	for(int i = 0; i <= a.size(); i++) for(int j = 0; j <= b.size(); j++)
		ans = max(ans, dp[i][j]);
	
	cout << ans;
	return 0;
}