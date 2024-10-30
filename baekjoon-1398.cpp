#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <queue>

using namespace std;

int T;

constexpr long long arr[8] = {25, 2500, 250000, 25000000, 2500000000, 250000000000, 25000000000000, 2500000000000000};

long long solve(long long cur, int coinIdx)
{
	if(cur == 0) return 0;
	if(coinIdx < 0)
	{
		int ret = 0;
		while(cur > 0)
		{
			ret += cur % 10;
			cur /= 10;
		}
		return ret;
	}

	if(cur < arr[coinIdx]) return solve(cur, coinIdx - 1);

	long long ans = 1e18;
	for(int m = 0; m < 5; m++)
	{
		if(m * arr[coinIdx] > cur) break;
		ans = min(ans, solve(cur - m * arr[coinIdx], coinIdx - 1) + m);
	}

	return ans;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> T;
	for(int test_case = 0; test_case < T; test_case++)
	{
		long long num; cin >> num;

		cout << solve(num, 7) << '\n';
	}
	return 0;
}