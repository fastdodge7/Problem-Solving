#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <queue>

using namespace std;

int N, K;

priority_queue<long long, vector<long long>, greater<long long>> pq;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> N;
	long long maxVal = 0;
	for (int i = 0; i < N; i++)
	{
		long long t; cin >> t;
		maxVal = max(maxVal, t);
		pq.push(t);
	}
	long long initMaxVal = maxVal;
	long long ans = 1e12;
	while (1)
	{
		auto cur = pq.top(); pq.pop();
		ans = min(ans, maxVal - cur);

		pq.push(cur * 2);
		maxVal = max(maxVal, cur * 2);

		if (initMaxVal < pq.top() )
		{
			cout << ans << '\n';
			return 0;
		}
	}

	return 0;
}