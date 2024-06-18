#include <iostream>

using namespace std;

int N, M;
long long arr[1000];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	long long sum = 0;
	cin >> N >> M;
	for(int i = 0; i < N; i++)
	{
		int a; cin >> a;
		sum += a;
		arr[sum % M] += 1;
	}

	long long ans = arr[0];
	for(int i = 0; i < M; i++)
	{
		if(arr[i] > 1)
		{
			ans += ((arr[i] * (arr[i] - 1)) / 2);
		}
	}

	cout << ans;
	return 0;
}