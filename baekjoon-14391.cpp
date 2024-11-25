#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int N, M;
int arr[4][4];

int calc(int bits)
{
	int val = 0;
	for(int i = 0; i < N; i++)
	{
		int temp = 0;
		for(int j = 0; j < M; j++)
		{
			if((bits & (1 << (M * i + j))) == 0)
			{
				temp *= 10;
				temp += arr[i][j];
			}
			else
			{
				val += temp;
				temp = 0;
			}
		}
		val += temp;
	}
	for(int i = 0; i < M; i++)
	{
		int temp = 0;
		for(int j = 0; j < N; j++)
		{
			if((bits & (1 << (M * j + i))) != 0)
			{
				temp *= 10;
				temp += arr[j][i];
			}
			else
			{
				val += temp;
				temp = 0;
			}
		}
		val += temp;
	}
	return val;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	
	cin >> N >> M;
	for(int i = 0; i < N; i++) 
	{
		string str; cin >> str;
		for(int j = 0; j < M; j++)
			arr[i][j] = (str[j] - '0');
	}
	
	int ans = 0;
	for(int bits = 0; bits < (1 << (N * M)); bits++)
		ans = max(ans, calc(bits));

	cout << ans;
	return 0;
}