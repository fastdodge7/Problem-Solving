#include <iostream>
#include <vector>

using namespace std;

int N, R, Q;
int dp[100001];
bool visited[100001];

vector<int> arr[100001];

int DFS(int cur)
{
	int ret = 1;
	visited[cur] = true;
	for (int next : arr[cur])
	{
		if (visited[next]) continue;
		ret += DFS(next);
	}
	return dp[cur] = ret;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> N >> R >> Q;
	for (int i = 0; i < N - 1; i++)
	{
		int a, b; cin >> a >> b;
		arr[a].push_back(b);
		arr[b].push_back(a);
	}
	DFS(R);
	for (int i = 0; i < Q; i++)
	{
		int target; cin >> target;
		cout << dp[target] << '\n';
	}
	return 0;
}