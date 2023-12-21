#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <queue>

using namespace std;

int N, M, K;

int parent[10001];
int cost[10001];
int ans[10001];

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
	cin.tie(0); cout.tie(0);

	fill(ans, ans + 10001, 1e9);
	cin >> N >> M >> K;

	for(int i = 1; i <= N; i++)
		cin >> cost[i];
	
	for(int i = 0; i < M; i++)
	{
		int a, b; cin >> a >> b;
		Union(a, b);
	}

	for(int i = 1; i <= N; i++)
		ans[Find(i)] = min(ans[Find(i)], cost[i]);

	int total = 0;
	for(int i = 1; i<= N; i++)
	{
		if(ans[i] < 1e9)
			total += ans[i];
	}

	if(total <= K)
		cout << total;
	else
		cout << "Oh no";
	
	return 0;
}