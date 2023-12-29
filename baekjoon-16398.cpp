#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef struct Edge{
	int cost;
	int a, b;
	bool operator<(const Edge& other) const {
		return cost < other.cost;
	}
}Edge;

int N;
int parent[1000];
vector<Edge> edges;

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

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	
	fill(parent, parent + 1000, -1);
	cin >> N;
	for(int i = 0; i < N; i++)
	{
		for(int j = 0; j < N; j++)
		{
			int cost; cin >> cost;
			if(i == j) continue;
			edges.push_back({cost, i, j});
		}
	}
	
	sort(edges.begin(), edges.end());
	
	long long ans = 0;
	for(const Edge& e : edges)
	{
		if(Find(e.a) == Find(e.b)) continue;
		ans += e.cost;
		Union(e.a, e.b);
	}
	cout << ans;
	return 0;
}