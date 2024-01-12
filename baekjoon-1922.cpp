#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>

using namespace std;

typedef struct Edge{
	int a, b;
	int cost;
	bool operator>(const Edge& other) const {
		return cost > other.cost;
	}
}Edge;

int N, M;
int parent[1001];

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
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	
	priority_queue<Edge, vector<Edge>, greater<Edge>> pq;
	cin >> N >> M;
	for(int i = 0; i < M; i++)
	{
		int a, b, c; cin >> a >> b >> c;
		if(a == b) continue;
		pq.push({a, b, c});
	}
	
	int ans = 0;
	while(!pq.empty())
	{
		Edge cur = pq.top(); pq.pop();
		if(Find(cur.a) == Find(cur.b)) continue;
		Union(cur.a, cur.b);
		ans += cur.cost;
	}
	
	cout << ans;
	return 0;
}