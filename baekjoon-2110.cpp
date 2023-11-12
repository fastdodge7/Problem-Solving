#include <iostream>
#include <algorithm>

using namespace std;

int arr[200000];
int N, K;

int check(int mid)
{
	int temp = 0;
	int ret = 1;
	for (int i = 1; i < N; i++)
	{
		temp += arr[i] - arr[i - 1];
		if (temp >= mid)
		{
			ret++;
			temp = 0;
		}
	}
	return ret;
}

int main(int argc, char* argv[]) {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> N >> K;
	for (int i = 0; i < N; i++)
		cin >> arr[i];

	sort(arr, arr + N);

	int left = 1; 
	int right = arr[N - 1] - arr[0] + 1;
	while (left < right)
	{
		int mid = (left + right) / 2;
		if (check(mid) >= K)
			left = mid + 1;
		else
			right = mid;
	}
	cout << right - 1 << '\n';
	return 0;
}