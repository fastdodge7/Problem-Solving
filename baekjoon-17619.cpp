#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

typedef struct Log{
	int number;
	int start;
	int end;

	bool operator<(const Log& other) const {
		return start < other.start;
	}
}Log;

int N, Q;
Log arr[100000];
int parent[100001];
int idx[100001];

int Find(int a)
{
	if(parent[a] == 0)
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

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> N >> Q;
	for(int i = 0; i < N; i++)
	{
		int dummy;
		cin >> arr[i].start >> arr[i].end >> dummy;
		arr[i].number = i + 1;
	}

	sort(arr, arr + N);

	for(int i = 0; i < N; i++)
		idx[arr[i].number] = i;

	for(int i = 1; i < N; i++)
	{
		int headIdx = idx[Find(arr[i - 1].number)];
		if(arr[headIdx].end >= arr[i].start)
		{
			arr[headIdx].end = max(arr[headIdx].end, arr[i].end);
			Union(arr[headIdx].number, arr[i].number);
		}
	}

	for(int i = 0; i < Q; i++)
	{
		int a, b;
		cin >> a >> b;
		cout << (int)(Find(a) == Find(b)) << '\n';
	}
	
	return 0;
}