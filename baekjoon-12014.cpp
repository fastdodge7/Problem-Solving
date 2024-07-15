#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int T, N, K;
vector<int> dp = {};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> T;
	for(int test_case = 1; test_case <= T; test_case++)
	{
		cin >> N >> K;
		int temp; cin >> temp;

		dp = { temp };
		for(int i = 1; i < N; i++)
		{
			cin >> temp;
			if(dp.back() < temp)
			{
				dp.push_back(temp);
				continue;
			}
			auto iter = lower_bound(dp.begin(), dp.end(), temp);
			*iter = temp;
		}
		cout << "Case #" << test_case << '\n';
		cout << (int)(dp.size() >= K) << '\n';
	}

	return 0;
}