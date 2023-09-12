#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int N, M, T;
int parent[10001];

int Find(int cur)
{
	if (parent[cur] <= 0)
		return cur;
	return parent[cur] = Find(parent[cur]);
}

void Union(int a, int b)
{
	a = Find(a);
	b = Find(b);
	
	parent[b] = a;
}

typedef struct Edge {
	bool operator<(const Edge& other) const { return cost < other.cost;  }
	int cost;
	int a, b;
}Edge;

vector<Edge> vec;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> N >> M >> T;
	for (int i = 0; i < M; i++)
	{
		int a, b, c; cin >> a >> b >> c;
		vec.push_back({ c, a, b });
	}

	sort(vec.begin(), vec.end());

	int ans = 0;
	int extraCost = 0;
	for (const Edge& e : vec)
	{
		if (Find(e.a) != Find(e.b))
		{
			ans += (e.cost + extraCost);
			extraCost += T;
			Union(e.a, e.b);
		}
	}

	cout << ans << '\n';

	return 0;
}