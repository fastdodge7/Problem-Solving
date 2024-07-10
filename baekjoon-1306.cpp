#include <iostream>
#include <algorithm>

using namespace std;

int arr[1000001];
int tree[1048576 * 2 + 1];

int makeTree(int idx, int start, int end)
{
	if(start == end) return tree[idx] = arr[start];
	int mid = (start + end) / 2;
	return tree[idx] = max(makeTree(idx * 2, start, mid), makeTree(idx * 2 + 1, mid + 1, end));
}

int findMax(int idx, int curStart, int curEnd, int targetStart, int targetEnd)
{
	if(curStart == targetStart && curEnd == targetEnd)
		return tree[idx];

	int mid = (curStart + curEnd) / 2;
	if(mid < targetStart)
		return findMax(idx * 2 + 1, mid + 1, curEnd, targetStart, targetEnd);

	else if(targetEnd <= mid)
		return findMax(idx * 2, curStart, mid, targetStart, targetEnd);
	
	else
		return max(
			findMax(idx * 2, curStart, mid, targetStart, mid), 
			findMax(idx * 2 + 1, mid + 1, curEnd, mid + 1, targetEnd)
			);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int N, M; cin >> N >> M;
	for(int i = 1; i <= N; i++)
		cin >> arr[i];

	makeTree(1, 1, N);
	for(int i = M; i <= N - M + 1; i++)
	{
		cout << findMax(1, 1, N, i - M + 1, i + M - 1) << ' ';
	}

	return 0;
}