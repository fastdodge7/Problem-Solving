#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <deque>
#include <cassert>

using namespace std;

int N;
deque<pair<long long, int>> dqLeft, dqRight;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> N;
	for(int i = 1; i <= N; i++)
	{
		long long a; cin >> a;
		dqRight.push_back({a, i});
	}

	int pass = 0;
	while(dqLeft.size() + dqRight.size() > 1)
	{
		deque<pair<long long, int>>& Ldq = (pass % 2 == 0 ? dqLeft : dqRight);
		deque<pair<long long, int>>& Rdq = (pass % 2 == 0 ? dqRight : dqLeft);
        
        int checker = Ldq.size() + Rdq.size();
        
        bool flag = false;
		while(!Rdq.empty())
		{
			auto cur = Rdq.front(); Rdq.pop_front();
       
			long long val = cur.first;
			if(!Ldq.empty() && val >= Ldq.back().first)
			{
				cur.first += Ldq.back().first;
				Ldq.pop_back();
                flag = true;
			}

			if(!Rdq.empty() && val >= Rdq.front().first)
			{
				cur.first += Rdq.front().first;
				Rdq.pop_front();
                flag = true;
			}
			Ldq.push_back(cur);
		}
        int cur = Ldq.size() + Rdq.size();
		pass++;
	}

	deque<pair<long long, int>>& dq = pass % 2 == 1 ? dqLeft : dqRight;
	cout << dq.back().first << '\n' << dq.back().second << '\n';

	return 0;
}