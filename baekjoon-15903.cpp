#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int N, M;
priority_queue<long long, vector<long long>, greater<long long>> pQ;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	long long ans = 0;

	cin >> N >> M;
	for (int i = 0; i < N; i++)
	{
		long long a; cin >> a;
		ans += a;
		pQ.push(a);
	}

	for(int i = 0; i < M; i++)
	{
		long long a = pQ.top(); pQ.pop();
		long long b = pQ.top(); pQ.pop();
		ans += (a + b);
		pQ.push(a + b);
		pQ.push(a + b);
	}

	cout << ans;
	return 0;
}