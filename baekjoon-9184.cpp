#include <algorithm>
#include <iostream>

using namespace std;

int a, b, c;
int dp[51][51][51];

long long solve(int a, int b, int c)
{
	if(a <= 0 || b <= 0 || c <= 0)
		return dp[0][0][0] = 1;

	if(dp[a][b][c] != -2e9)
		return dp[a][b][c];
	
	if(a > 20 || b > 20 || c > 20)
		return dp[a][b][c] = solve(20, 20, 20);

	if(a < b && b < c)
		return dp[a][b][c] = solve(a, b, c-1) + solve(a, b-1, c-1) - solve(a, b - 1, c);

	return dp[a][b][c] = solve(a-1, b, c) + solve(a - 1, b - 1, c) + solve(a - 1, b, c - 1) - solve(a - 1, b - 1, c - 1);
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	fill(&dp[0][0][0], &dp[50][50][50] + 1, -2e9);

	
	while(1)
	{
		cin >> a >> b >> c;
		if(a == -1 && b == -1 && c == -1)
			break;

		cout << "w(" << a << ", " << b << ", " << c << ") = ";
		cout << solve(a,b,c) << '\n';
	}

	return 0;
}