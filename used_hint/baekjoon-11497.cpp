#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <deque>

using namespace std;

int T;
int N;
int arr[10000];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> T;
	for(int test_case = 1; test_case <= T; test_case++)
	{
		cin >> N;
		for(int i = 0; i < N; i++)
			cin >> arr[i];

		sort(arr, arr + N, greater<int>());

		deque<int> dq;
		int dir = 0;

		for(int i = 0; i < N; i++)
		{
			if((++dir) % 2 == 1)
				dq.push_front(arr[i]);
			else
				dq.push_back(arr[i]);
		}

		int diff = abs(dq.front() - dq.back());

		int tem = dq.front(); dq.pop_front();
		while(!dq.empty())
		{
			diff = max(abs(tem - dq.front()), diff);
			tem = dq.front(); dq.pop_front();
		}

		cout << diff << '\n';
	}


	return 0;
}