#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N;
int parent[301];

int ans = 0;

typedef struct Edge{
	int from, to;
	int cost;
	bool operator<(const Edge& other) const {
		return cost < other.cost;
	}
}Edge;

vector<Edge> edges;

int Find(int a)
{
	if(parent[a] == -1) return a;
	return parent[a] = Find(parent[a]);
}

bool Union(int a, int b)
{
	a = Find(a);
	b = Find(b);
	if(a == b) return false;
	parent[b] = a;
	return true;
}

int main() 
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	
	cin >> N;
	for(int i = 0; i <= N; i++) for(int j = 1; j <= N; j++)	{
		int a; cin >> a;
		if(i < j)
		{
			edges.push_back({i, j, a});
		}
	}

	sort(edges.begin(), edges.end());
	
	fill(parent, parent + N + 1, -1);

	for(Edge e : edges)
	{
		if(Union(e.from, e.to))
			ans += e.cost;
	}

	cout << ans << '\n';
	return 0;
}