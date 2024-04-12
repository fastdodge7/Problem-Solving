#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N;
int switches[10001];
int bulb[10001];
int mapper[10001];
int arr[10001];
int dp[10001];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	
	cin >> N;
	for(int i = 1; i <= N; i++)
		cin >> switches[i];
	for(int i = 1; i <= N; i++)
	{
		cin >> bulb[i];
		mapper[bulb[i]] = i;
	}
	for(int i = 1; i <= N; i++)
	{
		arr[i] = mapper[switches[i]];
	}

	int length = 1;
	dp[1] = arr[1];
	switches[1] = 1;
	for(int i = 2; i <= N; i++)
	{
		if(dp[length] < arr[i])
		{
			dp[++length] = arr[i];
			switches[i] =length;
		}
		else
		{
			auto ptr = lower_bound(&dp[1], &dp[length] + 1, arr[i]);
			*ptr = arr[i];
			switches[i] = ptr - dp;
		}
	}

	vector<int> ans;
	for(int i = N; i > 0; i--)
	{
		if(switches[i] == length)
		{
			ans.push_back(bulb[arr[i]]);
			length--;
		}
	}
	
	sort(ans.begin(), ans.end());

	cout << ans.size() << '\n';
	for(int a : ans)
		cout << a << ' ';


	return 0;
}