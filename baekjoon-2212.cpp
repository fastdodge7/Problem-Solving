#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int N, K;
int arr[10000];
priority_queue<int, vector<int>, greater<int>> pq;

int main() {
	ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    
	cin >> N >> K;
	for(int i = 0; i < N; i++)
		cin >> arr[i];
		
	sort(arr, arr + N);
	
	for(int i = 0; i < N - 1; i++)
		pq.push(arr[i + 1] - arr[i]);
	
	int ans = 0;
	while(N > K)
	{
		ans += pq.top(); pq.pop();
		N--;
	}
	
	cout << ans;
	return 0;
}