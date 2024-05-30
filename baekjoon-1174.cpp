#include <algorithm>
#include <iostream>
#include <vector>
#include <string>

using namespace std;

int N;
int cnt = 0;
long long prev = -1;

vector<long long> arr;

int solve(int last, int depth, string& str)
{
	if(depth == 0)
	{
		arr.push_back(stoll(str));
		return 0;
	}
	for(int i = 0; i < last; i++)
	{
		str.push_back(i + '0');
		solve(i, depth - 1, str);
		str.pop_back();
	}
	return 0;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	cin >> N;
	if(N >= 1024)
	{
		cout << -1;
		return 0;
	}
	
	string str = "0";
	solve(0, 0, str);
	str.pop_back();
	for(int i = 1; i <= 10; i++)
	{
		for(int j = 1; j <= 9; j++)
		{
			str.push_back(j + '0');
			solve(j, i - 1, str);
			str.pop_back();
		}
	}

	sort(arr.begin(), arr.end());
	cout << arr[N - 1];

	return 0;
}