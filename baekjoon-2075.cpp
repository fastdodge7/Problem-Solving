#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int N;
priority_queue<int, vector<int>, greater<int>> pq;


int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> N;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			int t; cin >> t;
			if (pq.size() < N)
				pq.push(t);
			else
			{
				if (t < pq.top()) continue;
				pq.push(t);
				pq.pop();
			}
		}
	}
	cout << pq.top();
	return 0;
}