#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <queue>

using namespace std;

long long N, M;
vector<pair<long long, long long>> arr;
long long ans = 0;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> N >> M;
	for(int i = 0; i < N; i++)
	{
		int a, b; cin >> a >> b;
		if(a <= b) continue;
		arr.push_back({b, a});
	}

	sort(arr.begin(), arr.end());

	long long curStart = 0, curEnd = 0;
	for(auto [start, end] : arr)
	{
		if(curEnd < start)
		{
			ans += curEnd - curStart;
			curStart = start;
			curEnd = end;
			continue;
		}

		curEnd = max(end, curEnd);
	}
	ans += (curEnd - curStart);
	
	cout << M + 2 * ans;
	return 0;
}

