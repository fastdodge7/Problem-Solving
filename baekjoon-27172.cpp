#include <iostream>
#include <algorithm>

using namespace std;

int N, D, K, C;

int num[1000001];
int numToPlayer[1000001];
int ans[100001];

void updateFilter(int n)
{
	for (int m = 2; n * m <= 1000000; m++)
	{
		if (numToPlayer[n * m] != 0)
		{
			ans[numToPlayer[n * m]]--;
			ans[numToPlayer[n]]++;
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int N; cin >> N;
	for (int i = 1; i <= N; i++)
	{
		int k; cin >> k;
		numToPlayer[k] = i;
		num[i - 1] = k;
	}

	sort(num, num + N);

	for (int i = 0; i < N; i++)
	{
		int number = num[i];
		updateFilter(number);
	}

	for (int i = 1; i <= N; i++)
	{
		cout << ans[i] << " ";
	}
	
	return 0;
}