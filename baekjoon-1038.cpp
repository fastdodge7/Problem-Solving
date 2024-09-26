#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <queue>

using namespace std;

long long arr[1023];

int BFS()
{
	queue<long long> Q;
	for(int i = 1; i < 10; i++)
		Q.push(i);
	
	int cnt = 0;
	while(!Q.empty())
	{
		long long cur = Q.front(); Q.pop();
		arr[++cnt] = cur;

		for(long long tail = 0; tail < 10; tail++)
		{
			if(tail < cur % 10)
				Q.push(10 * cur + tail);
		}
	}

	return cnt;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	

	int N; cin >> N;

	BFS();
	cout << (N > 1022 ? -1 : arr[N]);

	return 0;
}