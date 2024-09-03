#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <deque>
#include <cassert>
#include <queue>

using namespace std;

int N;
int parent[10];
long long ans[10] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1};

int Find(int a)
{
	if(parent[a] == -1)
		return a;
	return parent[a] = Find(parent[a]);
}

void Union(int a, int b)
{
	a = Find(a);
	b = Find(b);
	if(a == b) return;
	parent[b] = a;
}

long long gcb(long long a, long long b)
{
	if(a < b) swap(a, b);

	while(b > 1)
	{
		long long temp = a;
		a = b;
		b = temp % b; 
		if(b == 0) return a;
	}

	return 1;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	
	for(int i = 0; i < 10; i++)
		parent[i] = -1;

	cin >> N;
	for(int i = 0; i < N - 1; i++)
	{
		long long a, b, p, q; cin >> a >> b >> p >> q;

		long long gcbVal = gcb(ans[b] * p, ans[a] * q);
		long long multA = ans[b] * p / gcbVal;
		long long multB = ans[a] * q / gcbVal;

		for(int i = 0; i < N; i++)
		{
			if(Find(i) == Find(a))
				ans[i] *= multA;
			if(Find(b) == Find(i))
				ans[i] *= multB;
		}
		Union(a, b);
	}

	for(int i = 0; i < N; i++)
		cout << ans[i] <<' ';
	return 0;
}