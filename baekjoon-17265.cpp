#include <iostream>
#include <vector>
#include <unordered_map>
#include <deque>
#include <algorithm>

using namespace std;

int N;
char arr[5][5];
int maxDp[5][5];
int minDp[5][5];

int calc(int a, char oper, int b)
{
	if(oper == '+')
		return a + b;
	if(oper == '-')
		return a - b;
	else
		return a * b;
}		

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> N;
	for(int i = 0; i < N; i++)for(int j = 0; j < N; j++)
	{
		cin >> arr[i][j];
		minDp[i][j] = 1e9;
		maxDp[i][j] = -1e9;
	}
	
	maxDp[0][0] = minDp[0][0] = arr[0][0] - '0';
	for(int i = 0; i < N; i++)for(int j = 0; j < N; j++)
	{
		if('0' <= arr[i][j] && arr[i][j] <= '5')
		{
			if(i - 2 >= 0)
			{
				maxDp[i][j] = max(maxDp[i][j], calc(maxDp[i - 2][j], arr[i - 1][j], arr[i][j] - '0'));
				minDp[i][j] = min(minDp[i][j], calc(minDp[i - 2][j], arr[i - 1][j], arr[i][j] - '0'));
			}
			if(j - 2 >= 0)
			{
				maxDp[i][j] = max(maxDp[i][j], calc(maxDp[i][j - 2], arr[i][j - 1], arr[i][j] - '0'));
				minDp[i][j] = min(minDp[i][j], calc(minDp[i][j - 2], arr[i][j - 1], arr[i][j] - '0'));
			}
			if(i - 1 >= 0 && j - 1 >= 0)
			{
				maxDp[i][j] = max(maxDp[i][j], calc(maxDp[i - 1][j - 1], arr[i - 1][j], arr[i][j] - '0'));
				maxDp[i][j] = max(maxDp[i][j], calc(maxDp[i - 1][j - 1], arr[i][j - 1], arr[i][j] - '0'));
				minDp[i][j] = min(minDp[i][j], calc(minDp[i - 1][j - 1], arr[i - 1][j], arr[i][j] - '0'));
				minDp[i][j] = min(minDp[i][j], calc(minDp[i - 1][j - 1], arr[i][j - 1], arr[i][j] - '0'));
			}
		}
	}

	cout << maxDp[N - 1][N - 1] << ' ' << minDp[N - 1][N - 1];
	return 0;
}