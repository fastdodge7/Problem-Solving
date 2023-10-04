#include <iostream>
#include <queue>

using namespace std;

constexpr long long MOD = 1000000007;

int T, N;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> T;
	for (int test_case = 1; test_case <= T; test_case++)
	{
		priority_queue<long long, vector<long long>, greater<long long>> minQ;

		int N; cin >> N;
		for (int i = 0; i < N; i++)
		{
			long long a; cin >> a;
			minQ.push(a);
		}

		long long ans = 1;
		while (minQ.size() > 1)
		{
			auto minVal = minQ.top(); minQ.pop();
			auto minVal2 = minQ.top(); minQ.pop();

			long long newVal = (minVal * minVal2);

			minQ.push(newVal);

			ans = ((ans % MOD) * (newVal % MOD)) % MOD;
		}
		cout << ans << '\n';
	}
	return 0;
}