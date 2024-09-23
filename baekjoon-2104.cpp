#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int N;
int arr[100001];
pair<int, int> sortedArr[100001];
long long prefix[100001];
int ptr[100001];

long long ans = 0;

long long extendRange(int idx)
{
	int left = idx - 1;
	while(1)
	{
		if(left < 1) break;
		if(arr[left] < arr[idx]) break;
		if(arr[left] == arr[idx])
		{
			ptr[left] = left;
			left--;
			continue;
		}

		if(ptr[left] < left) // 구간의 오른쪽 끝인 경우
			left = ptr[left];
		else // 구간의 왼쪽 끝 혹은 크기가 1인 구간인 경우
			left--;
	}

	int right = idx + 1;
	while(1)
	{
		if(right > N) break;
		if(arr[right] < arr[idx]) break;
		if(arr[right] == arr[idx])
		{
			ptr[right] = right;
			right++;
			continue;
		}

		if(ptr[right] <= right) // 구간의 오른쪽 끝인 경우
			right++;
		else // 구간의 왼쪽 끝 혹은 크기가 1인 구간인 경우
			right = ptr[right];
	}
	
	left++;
	right--;

	ptr[left] = right;
	ptr[right] = left;

	return prefix[right] - prefix[left] + arr[left];
}

int main() {
	iostream::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> N;
	for(int i = 1; i <= N; i++)
		cin >> arr[i];


	for(int i = 1; i <= N; i++)
	{
		sortedArr[i] = {arr[i], i};
		prefix[i] = arr[i] + prefix[i - 1];
	}

	sort(sortedArr + 1, sortedArr + N + 1, greater<pair<int, int>>());

	for(int minIdx = 1; minIdx <= N; minIdx++)
	{
		auto [minValue, idx] = sortedArr[minIdx];
		if(ptr[idx] == idx) continue;
		long long summation = extendRange(idx);

		//cout << "minValue : " << minValue << " / sum : " << summation << '\n';
		ans = max(ans, summation * (long long)minValue);
	}

	cout << ans;
	return 0;
}