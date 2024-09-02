#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
#include <cassert>

using namespace std;

int N, M;
int parent[1001];
vector<int> ematrix[1001];

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

	cin >> N >> M;

	for(int i = 0; i < M; i++)
	{
		char type; cin >> type;
		int a, b; cin >> a >> b;

		if(type == 'E')
		{
			ematrix[a].push_back(b);
			ematrix[b].push_back(a);
		}
		else
		{
			Union(a, b);
		}
	}

	for(int i = 1; i <= N; i++)
	{
		for(int enemy : ematrix[i])
		{
			for(int f : ematrix[enemy])
			{
				if(f == i) continue;
				Union(i, f);
			}
		}
	}

	int ans = 0;
	for(int i = 1; i <= N; i++)
	{
		if(parent[i] == 0)
			ans++;
	}

	cout << ans;
	return 0;
}