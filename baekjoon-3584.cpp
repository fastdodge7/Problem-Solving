#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int T, N;

vector<int> matrix[10001];
int parent[10001];
int depth[10001];

void DFS(int cur, int d)
{
	depth[cur] = d;
	for(int next : matrix[cur])
	{
		if(depth[next] == 0)
			DFS(next, d + 1);
	}
}

void clearing()
{
	fill(depth, depth + N + 1, 0);
	fill(parent, parent + N + 1, 0);
	for(int i = 1; i <= 10000; i++)
		matrix[i].clear();
}

int main() {
	// your code goes here
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	
	cin >> T;
	for(int test_case = 1; test_case <= T; test_case++)
	{
		cin >> N;
		for(int i = 0; i < N-1; i++)
		{
			int a, b; cin >> a >> b;
			parent[b] = a;
			matrix[a].push_back(b);
			matrix[b].push_back(a);
		}
		for(int i = 1; i <= N; i++)
		{
			if(parent[i] == 0)
			{
				DFS(i, 1);
				break;
			}
		}
		
		int a, b; cin >> a >> b;
		if(depth[a] < depth[b])	swap(a, b);
		
		while(depth[a] > depth[b])
			a = parent[a];
		
		while(a != b)
		{
			a = parent[a];
			b = parent[b];
		}
		cout << a << '\n';
		clearing();
	}
	return 0;
}