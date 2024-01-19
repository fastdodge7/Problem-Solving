#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>

using namespace std;

int N;
pair<int, int> arr[100000];

int main() {
	ios::sync_with_stdio(false);
	cout.tie(0); cin.tie(0);
	
	cin >> N;
	for(int i = 0; i < N; i++)
	{
		int a, b, c;
		cin >> a >> b >> c;
		arr[i] = {b, c};
	}
	
	sort(arr, arr + N);
	
	priority_queue<int, vector<int>, greater<int>> pq;
	
	int ans = 0;
	for(int i = 0; i < N; i++)
	{
		while(!pq.empty() && pq.top() <= arr[i].first)
		{
			pq.pop();
		}
		pq.push(arr[i].second);
		ans = max(ans, (int)pq.size());
	}
	cout << ans << '\n';
	return 0;
}