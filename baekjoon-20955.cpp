#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

constexpr int MAX_N = 101;

int N, M;
int parent[MAX_N];
int ans = 0;
int target = 0;

int Find(int a)
{
	if(parent[a] == 0) return a;
	return parent[a] = Find(parent[a]);
}

void Union(int a, int b)
{
	a = Find(a);
	b = Find(b);
	if(a == b) 
	{
		ans++;
		return;
	}
	target--;
	parent[b] = a;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> N >> M;
	target = N - 1;
	for(int i = 0; i < M; i++)
	{
		int a, b; cin >> a >> b;
		Union(a, b);
	}
	cout << ans + target;
	return 0;
}
