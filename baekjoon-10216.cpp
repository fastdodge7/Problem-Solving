#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef struct Node{
	int y, x, r;
}Node;

int T, N;

Node points[3001];
int parent[3001];

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
	cout.tie(0); cin.tie(0);
	
	cin >> T;
	for(int test_case = 1; test_case <= T; test_case++)
	{
		cin >> N;
		for(int i = 1; i <= N; i++)
		{
			int x, y, r; cin >> x >> y >> r;
			points[i] = {y, x, r};
			for(int j = 1; j < i; j++)
			{
				int dy = abs(points[j].y - points[i].y);
				int dx = abs(points[j].x - points[i].x);
				int r = (points[i].r + points[j].r)*(points[i].r + points[j].r);
				int dist = dy*dy + dx*dx;
				if(dist <= r)
					Union(i, j);
			}
		}
		
		int ans = 0;
		for(int i = 1; i <= N; i++)
		{
			if(i == Find(i))
				ans++;
		}
		
		cout << ans << '\n';
		fill(parent, parent + 3001, 0);
	}
	return 0;
}