#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <queue>

using namespace std;

int N, M;
int arr[500000];
pair<int, int> customer[500000];
long long ans[500001];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> N >> M;
	for(int i = 0; i < N; i++)
	{
		cin >> arr[i];
	}

	sort(arr, arr + N);

	for(int i = 0; i < M; i++)
	{
		int a, b; cin >> a >> b;
		customer[i] = {a, b};
	}

	sort(customer, customer + M);

	int curTime = customer[0].first;
	queue<int> Q;
	Q.push(customer[0].second);
	for(int i = 1; i < M; i++)
	{	
		if(Q.empty() || customer[i].first <= Q.front())
		{
			ans[Q.size()] += (customer[i].first - curTime);
			Q.push(customer[i].second);
			curTime = customer[i].first;
		}
		else
		{
			ans[Q.size()] += (Q.front() - curTime + 1);
			int prev = Q.front();
			curTime = Q.front() + 1; Q.pop();
			while(!Q.empty())
			{
				if(Q.front() != prev) break;
				Q.pop();
			}
			i--;
		}
	}

	while(!Q.empty())
	{
		ans[Q.size()] += (Q.front() - curTime + 1);
		int prev = Q.front();
		curTime = Q.front() + 1; Q.pop();
		while(!Q.empty())
		{
			if(Q.front() != prev) break;
			Q.pop();
		}
	}

	for(int i = N - 1; i > 0; i--)
		ans[i] += ans[i + 1];

	long long maxVal = 0, minVal = 0;
	int idx = 0;
	for(int cnt = 1; cnt <= N; cnt++)
	{
		if(ans[cnt] > 0)
		{
			maxVal += (ans[cnt] * arr[N - 1 - idx]);
			minVal += (ans[cnt] * arr[idx]);
			idx++;
		}
	}

	cout << minVal << ' ' << maxVal << '\n';
	return 0;
}