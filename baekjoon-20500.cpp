#include <iostream>
#include <algorithm>

using namespace std;

constexpr long long MOD = 1e9 + 7;
constexpr long long MODFT = 15;

int N;
long long ans[1516][15];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	
	cin >> N;
	ans[1][1] = ans[1][5] = 1;
	ans[2][11] = ans[2][0] = ans[2][6] = ans[2][10] = 1;
	
	for(int i = 3; i <= N; i++)
	{
		for(int j = 0; j < 15; j++)
		{
			long long tenTimes = (j * 10) % MODFT;
			ans[i][(j + 10) % MODFT] = (ans[i][(j + 10) % MODFT] + ans[i - 1][j]) % MOD;
			ans[i][(j + 5) % MODFT] = (ans[i - 1][j] + ans[i][(j + 5) % MODFT]) % MOD;
		}
	}

	cout << ans[N][0];
	return 0;
}