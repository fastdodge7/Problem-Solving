#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;

int N, L;
pair<int, int> arr[10000];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	
	cin >> N >> L;
	for(int i = 0; i < N; i++)
	{
		cin >> arr[i].first >> arr[i].second;
	}
	sort(arr, arr + N);
	
	int ans = 0;
	int lastPos = -1;
	for(int i = 0; i < N; i++)
	{
		if(lastPos >= arr[i].second) continue;
		int needed = ceil((float)(arr[i].second - max(lastPos, arr[i].first)) / L);
		ans += (needed);
		
		if(lastPos >= arr[i].first)
			lastPos += L * needed;
		else
			lastPos = arr[i].first + L * needed;
	}
	
	cout << ans;
	
	// your code goes here
	return 0;
}