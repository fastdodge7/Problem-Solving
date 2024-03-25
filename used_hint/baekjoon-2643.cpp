#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

bool isPossible(const pair<int, int>& top, const pair<int, int>& bottom)
{
	return top.first <= bottom.first && top.second <= bottom.second;
}

int N;
pair<int, int> arr[100];
int dp[100][2];

int main() {
	// your code goes here
	
	cin >> N;
	for(int i = 0; i < N; i++)
    {
        int a, b; cin >> a >> b;
        if(a > b) swap(a, b);
        arr[i] = {a, b};
    }
		
	sort(arr, arr + N);
	
	int ans = 0;
	for(int i = 0; i < N; i++)
	{
		dp[i][1] = 1;
		for(int j = 0; j < i; j++)
		{
			if(isPossible(arr[j], arr[i]))
			{
				dp[i][1] = max(dp[i][1], dp[j][1] + 1);
			}
			dp[i][0] = max(dp[i][0], max(dp[j][0], dp[j][1]));
		}
		ans = max(ans, max(dp[i][0], dp[i][1]));
	}
	
	cout << max(dp[N - 1][0], dp[N - 1][1]);
	return 0;
}