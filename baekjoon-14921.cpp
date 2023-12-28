#include <iostream>
#include <algorithm>

using namespace std;

int N;
int arr[100000];

int solve(int startInclude, int endInclude, int target)
{
	int left = startInclude;
	int right = endInclude;
	while(left + 1 < right)
	{
		int mid = (left + right)/2;
		if(target == arr[mid])
			return arr[mid];
		else if(target < arr[mid])
			right = mid;
		else
			left = mid;
	}
	
	if(abs(target - arr[left]) < abs(target - arr[right]))
		return arr[left];
	return arr[right];
	
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	
	cin >> N;
	for(int i = 0; i < N; i++)
		cin >> arr[i];
		
	int ans = 2e9;
	for(int i = 0; i < N - 1; i++)
	{
		int t = arr[i] + solve(i + 1, N - 1, -arr[i]);
		ans = abs(ans) < abs(t) ? ans : t;
	}
	cout << ans;
	return 0;
}