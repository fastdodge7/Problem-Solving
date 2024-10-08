#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <deque>
#include <queue>

using namespace std;

int id[100000];
int cost[100000];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int T; cin >> T;
	for(int test_case = 1; test_case <= T; test_case++)
	{
		int N, L, K; cin >> N >> L >> K;
		for(int i = 0; i < N; i++)
		{
			int tPos; cin >> tPos >> id[i];
			if(id[i] > 0)
				cost[i] = L - tPos;
			else
				cost[i] = tPos;
		}

		deque<pair<int, int>> idxDq;
		deque<int> timeDq;
		vector<pair<int, int>> ans;
		for(int i = 0; i < N; i++)
		{
			if(id[i] < 0)
			{
				if(idxDq.size() == 0)
				{
					ans.push_back({cost[i], id[i]});
					continue;
				}
				idxDq.push_back({id[i], i});
				timeDq.push_front(cost[i]);
				int tarId = idxDq.front().first;
				ans.push_back({timeDq.front(), tarId});
				idxDq.pop_front();
				timeDq.pop_front();
			}
			else
			{
				idxDq.push_back({id[i], i});
				timeDq.push_back(cost[i]);
			}
		}
		while(!idxDq.empty())
		{
			int tarId = idxDq.front().first;
			ans.push_back({timeDq.front(), tarId});
			idxDq.pop_front();
			timeDq.pop_front();
		}

		sort(ans.begin(), ans.end());

		cout << ans[K - 1].second << '\n';
	}
	return 0;
}