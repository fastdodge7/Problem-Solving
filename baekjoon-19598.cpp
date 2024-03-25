#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

typedef struct Meeting{
	int start;
	int end;
	bool operator<(const Meeting& other) const {
		return start < other.start;
	}
}Meeting;

int N;
Meeting arr[100000];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	
	cin >> N;
	for(int i = 0; i < N; i++)
		cin >> arr[i].start >> arr[i].end;
		
	sort(arr, arr + N);
	
	priority_queue<int, vector<int>, greater<int>> pq;
	pq.push(0);
	
	int ans = 0;
	for(int i = 0; i < N; i++)
	{
		while(!pq.empty() && arr[i].start >= pq.top())
		{
			pq.pop();
		}
		pq.push(arr[i].end);
		ans = max(ans, (int)pq.size());
	}

	cout << ans << '\n';
	return 0;
}