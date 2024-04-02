#include <algorithm>
#include <iostream>
#include <string>

using namespace std;

constexpr int ANGEL = 0;
constexpr int DEVIL = 1;

int dp[101][21][2];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	string password; cin >> password;
	string angel; cin >> angel;
	string devil; cin >> devil;

	for(int i = 0; i < angel.size(); i++)
	{
		dp[i][0][ANGEL] = (password[0] == angel[i] ? 1 : 0);
		dp[i][0][DEVIL] = (password[0] == devil[i] ? 1 : 0);
	}
	
	for(int i = 1; i < angel.size(); i++)
	{
		for(int j = 1; j < password.size(); j++)
		{
			for(int k = i - 1; k >= 0; k--)
			{
				if(password[j] == angel[i])
					dp[i][j][ANGEL] += dp[k][j - 1][DEVIL];

				if(password[j] == devil[i])
					dp[i][j][DEVIL] += dp[k][j - 1][ANGEL];
			}
		}
	}

	int ans = 0;
	for(int i = 0; i < angel.size(); i++)
	{
		ans += dp[i][password.size() - 1][ANGEL];
		ans += dp[i][password.size() - 1][DEVIL];
	}

	cout << ans << '\n';
	return 0;
}