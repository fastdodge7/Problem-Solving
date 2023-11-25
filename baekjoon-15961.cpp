#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int N, D, K, C;

int arr[3000000];
int check[3001];
int cnt = 0;
int ans = 0;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> N >> D >> K >> C;
	for (int i = 0; i < N; i++)
		cin >> arr[i];

	int start = 0;
	int end = K - 1;

	for (int i = start; i <= end; i++)
	{
		int idx = i % N;
		if (check[arr[idx]] == 0)
			cnt++;
		check[arr[idx]]++;
	}
	ans = cnt + (check[C] > 0 ? 0 : 1);

	while (start != N - 1)
	{
		check[arr[start++]]--;
		if (check[arr[start - 1]] == 0)
			cnt--;

		int idx = (++end) % N;
		check[arr[idx]]++;
		if (check[arr[idx]] == 1)
			cnt++;

		ans = max(ans, cnt + (check[C] > 0 ? 0 : 1));
	}
	cout << ans;
	return 0;
}