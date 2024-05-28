#include <algorithm>
#include <string>
#include <iostream>

using namespace std;

string str;
int dp[2][5000];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int ans = 0;
	int pos = 1;
	cin >> str;
	for(int i = 0; i < str.size(); i++)
	{
		for(int j = 0; j < str.size(); j++)
		{
			dp[pos][j] = 0;
			if(i == j) continue;
			if(str[i] == str[j])
			{
				if(i == 0 || j == 0)
					dp[pos][j] = 1;
				else
					dp[pos][j] = dp[(pos - 1) * (-1)][j - 1] + 1;
				ans = max(dp[pos][j], ans);
			}	
		}
		pos = (pos - 1) * (-1);
	}

	cout << ans;
	return 0;
}