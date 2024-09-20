#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int N;
string arr[81];

bool check(const string& cand)
{
	for(int len = 1; len <= cand.size() / 2; len++)
	{
		bool isIdentical = true;
		for(int idx = cand.size() - 2 * len; idx < cand.size() - len; idx++)
		{
			if(cand[idx] != cand[idx + len])
			{
				isIdentical = false;
				break;
			}
		}
		if(isIdentical) return false;
	}
	return true;
}

bool solve(string& cur)
{
	if(cur.size() == N)
	{
		cout << cur;
		return true;
	}

	for(char last = '1'; last <= '3'; last++)
	{
		cur.push_back(last);
		if(!check(cur))
		{
			cur.pop_back();
			continue;
		}

		if(solve(cur))
			return true;
		cur.pop_back();
	}

	return false;
}

int main() {
	iostream::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> N;
	string init = "1";
	solve(init);
	return 0;
}