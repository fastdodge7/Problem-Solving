#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int N;

vector<int> arr;

string step(string str)
{
	for(int i = 0; i < str.size(); i++)
	{
		arr.push_back(2 * (str[i] - '0'));
	}
	arr[arr.size() - 1] += 1;

	for(int i = str.size() - 1; i > 0; i--)
	{
		if(arr[i] > 9)
		{
			arr[i - 1] += 1;
			arr[i] -= 10;
		}
	}
	string ret = "";
	for(int i = 0; i < str.size(); i++)
	{
		ret = ret + to_string(arr[i]);
	}
	arr.clear();
	return ret;
}

void solve(int N, int from, int to)
{
	if(N < 1) return;

	solve(N - 1, from, 6 - (from + to));
	cout << from << ' ' << to << '\n';
	solve(N - 1, 6 - (from + to), to);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	
	cin >> N;
	string ans = "1";

	for(int i = 0; i < N - 1; i++)
		ans = step(ans);

	cout << ans << '\n';
	if(N <= 20)
		solve(N, 1, 3);
	
	return 0;
}