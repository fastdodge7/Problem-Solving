#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int N, M;
vector<int> matrix[100001];
int ans[100001];


void DFS(int cur, int comple)
{
	ans[cur] += comple;
	for(int next : matrix[cur])
	{
		DFS(next, ans[cur]);
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> N >> M;
	for(int i = 1; i <= N; i++)
	{
		int parent; cin >> parent;
		if(parent == -1) continue;
		matrix[parent].push_back(i);
	}

	for(int i = 0; i < M; i++)
	{
		int a, b; cin >> a >> b;
		ans[a] += b;
	}

	DFS(1, 0);

	for(int i = 1; i <= N; i++)
	{
		cout << ans[i] << ' ';
	}

	return 0;
}