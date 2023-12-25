#include <iostream>
#include <algorithm>
using namespace std;

typedef struct Road{
	int cost;
	int start, end;
	bool operator<(const Road& other) {
		return cost < other.cost;
	}
}Road;

int N, M;
int parent[200000];
Road roads[200000];

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

int mst()
{
	int ans = 0;
	sort(roads, roads + N);
	for(int i = 0; i < N; i++)
	{
		if(Find(roads[i].start) == Find(roads[i].end))
		{
			ans += roads[i].cost;
			continue;
		}
		Union(roads[i].start, roads[i].end);
	}
	return ans;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	
	while(1)
	{
		cin >> M >> N;
		if(N == M && N == 0) return 0;
		fill(parent, parent + M, -1);
		for(int i = 0; i < N; i++)
		{
			int x, y, z; cin >> x >> y >> z;
			roads[i] = {z, x, y};
		}
		cout << mst() << '\n';
	}
	
	return 0;
}