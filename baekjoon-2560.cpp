#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int a, b, d, N;
int dp[1000001];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	
	cin >> a >> b >> d >> N;

	for(int i = 0; i < a; i++)
		dp[i] = 1;
	
	for(int i = a; i <= N; i++)
	{
		dp[i] = (dp[i - 1] + dp[i - a]) % 1000;  // 새로운 개체가 나오는 것.
		if(b <= i)	// 
			dp[i] = (dp[i] - dp[i - b]) % 1000;
	}

	cout << (dp[N] - dp[N - d] + 1000) % 1000;

	return 0;
}