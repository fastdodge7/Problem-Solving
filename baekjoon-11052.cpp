#include <algorithm>
#include <iostream>

using namespace std;

int N;
int arr[1001];
int dp[1001][1001];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> N;
	for(int i = 1; i <= N; i++)
		cin >> arr[i];

	for(int idx = 1; idx <= N; idx++)
	{
		for(int capa = 1; capa <= N; capa++)
		{
			if(capa < idx)
				dp[idx][capa] = max(dp[idx][capa - 1], dp[idx - 1][capa]);
			else
			{
				if(arr[idx] <= arr[idx - 1])
					dp[idx][capa] = max(dp[idx][capa - 1], dp[idx - 1][capa]);
				else
				{
					for(int cnt = 1; (cnt * idx) <= capa; cnt++)
						dp[idx][capa] = max(dp[idx][capa], dp[idx - 1][capa - idx * cnt] + arr[idx] * cnt);
					dp[idx][capa] = max(dp[idx][capa], dp[idx - 1][capa]);
					dp[idx][capa] = max(dp[idx][capa - 1], dp[idx][capa]);
				}
			}
		}
	}
    
	cout << dp[N][N];
	return 0;
}