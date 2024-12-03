#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

constexpr int MAX_N = 10;

int N, M;
int arr[MAX_N];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	
	cin >> N >> M;
	for(int i = 0; i < N; i++) cin >> arr[i];

	sort(arr, arr + N);

	int ans = 2e9 + 7;
	for(int i = 0; i < N; i++)
	{
		int target = *lower_bound(arr + i + 1, arr + N, M + arr[i]);
		ans = min(ans, target - arr[i]);
	}

	cout << ans;
	return 0;
}