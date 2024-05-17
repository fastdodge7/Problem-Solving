#include <algorithm>
#include <iostream>

using namespace std;

int N, M, L;
int arr[102];

bool check(int maxDist) // N == 0일때 테스트 필요.
{
	int cur = 0;
	int nextStation = 1;
	int cnt = 0;

	while(cur < arr[N + 1])
	{
		if(cnt > M) return false;
		if(arr[nextStation] - cur > maxDist)
		{
			cur += maxDist;
			cnt++;
		}
		else
			cur = arr[nextStation++];
	}
	return true;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> N >> M >> L;
	for(int i = 1; i <= N; i++)
		cin >> arr[i];
	
	arr[0] = 0; 
	arr[N + 1] = L;

	sort(arr, arr + N + 2);

	int left = 0;
	int right = L + 1;
	while(left + 1 < right)
	{
		int mid = (left + right) / 2;
		if(check(mid))
			right = mid;
		else
			left = mid;
	}

	cout << right;
	return 0;
}