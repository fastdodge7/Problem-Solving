#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cassert>

using namespace std;

int N, Q;
long long tree[4 * 1000001];

long long change(int ptr, int start, int end, int target, long long diffVal)
{
	if(target < start || target > end) return 0;
	if(start == end && end == target)
	{
		tree[ptr] += diffVal;
		return diffVal;
	}

	int mid = (start + end) / 2;
	if(start < end)
	{
		long long d1 = change(ptr * 2, start, mid, target, diffVal);
		long long d2 = change(ptr * 2 + 1, mid + 1, end, target, diffVal);
		tree[ptr] += (d1 + d2);
		return (d1 + d2);
	}
	assert(true);
	return 0;
}

long long Find(int ptr, int start, int end, int tStart, int tEnd)
{
	if(tStart < start || tEnd > end) return 0;
	if(start == tStart && end == tEnd) return tree[ptr];

	int mid = (start + end) / 2;

	long long ans = 0;
	if(tStart <= mid && mid < tEnd)
		return Find(ptr * 2, start, mid, tStart, mid) + Find(ptr * 2 + 1, mid + 1, end, mid + 1, tEnd);

	if(tEnd <= mid)
		return Find(ptr * 2, start, mid, tStart, tEnd);
	
	if(mid < tStart)
		return Find(ptr * 2 + 1, mid + 1, end, tStart, tEnd);
	return 0;
}


int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> N >> Q;
	for(int i = 0; i < Q; i++)
	{
		int command; cin >> command;
		if(command == 1)
		{
			long long a, b; cin >> a >> b;
			change(1, 1, N, a, b);
		}
		else
		{
			long long a, b; cin >> a >> b;
			cout << Find(1, 1, N, a, b) << '\n';
		}
	}

	return 0;
}