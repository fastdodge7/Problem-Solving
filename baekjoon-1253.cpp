#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int N;
vector<int> arr;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> N;
	for(int i = 0; i < N; i++)
	{
		int temp; cin >> temp;
		arr.push_back(temp);
	}

	sort(arr.begin(), arr.end());

	int ans = 0;
	for(int i = 0; i < N; i++)
	{
		for(int j = 0; j < N; j++)
		{
			auto iter = lower_bound(arr.begin(), arr.end(), arr[i] - arr[j]);
			auto uiter = upper_bound(arr.begin(), arr.end(), arr[i] - arr[j]);
			int cnt = uiter - iter;
			//cout << cnt << '\n';
			if(i == j) continue;
			if(arr[i] == *iter && arr[j] == *iter && cnt < 3) continue;
			if((arr[i] == *iter || arr[j] == *iter) && cnt < 2) continue;
			if(arr[j] + *iter != arr[i]) continue;
			ans++;
			break;
		}
	}
	cout << ans;
	return 0;
}