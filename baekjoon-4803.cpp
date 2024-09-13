#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <queue>
#include <cmath>

using namespace std;

constexpr int WHITE = 0;
constexpr int GRAY = 1;
constexpr int BLACK = 2;

int N, M;
vector<int> matrix[501];
int visited[501];

bool DFS(int cur, int parent)
{
	visited[cur] = GRAY;

	bool ret = false;
	for(int next : matrix[cur])
	{
		if(next == parent) continue;
		if(visited[next] == GRAY)
		{

			ret = ret || true;
			continue;
		}

		if(visited[next] == BLACK) continue;

		bool ci = DFS(next, cur);
		ret = (ret || ci );
	}

	visited[cur] = BLACK;
	return ret;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int test_case = 1;
	while(1)
	{
		cin >> N >> M;
		if(N == M && N == 0) break;

		for(int i = 0; i < M; i++)
		{
			int a, b; cin >> a >> b;
			matrix[a].push_back(b);
			matrix[b].push_back(a);
		}

		int ans = 0;
		for(int i = 1; i <= N; i++)
		{
			if(visited[i] == WHITE && !DFS(i, 0))
			{
				cout << endl;
				ans++;
			}	
		}
		cout << "Case " << test_case++ << ": ";
		if(ans == 0)
			cout << "No trees.\n";
		else if(ans == 1)
			cout << "There is one tree.\n";
		else
			cout << "A forest of " << ans << " trees.\n";

		fill(visited, visited + 501, WHITE);
		for(int i = 0; i <= N; i++)
			matrix[i].clear();
	}

	return 0;
}