#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <queue>

using namespace std;

constexpr int WHITE = 0;
constexpr int GRAY = 1;
constexpr int BLACK = 2;

int N;
int arr[101];
int visited[101];
bool isCycle[101];
int ans = 0;

void markCycle(int cur)
{
	isCycle[cur] = true;
	ans++;
	if(isCycle[arr[cur]]) return;

	markCycle(arr[cur]);
}

bool DFS(int cur)
{
	if(visited[cur] == BLACK) return true;
	if(visited[arr[cur]] == BLACK) return true;
	if(visited[arr[cur]] == GRAY)
	{
		isCycle[cur] = true;
		ans++;
		if(cur != arr[cur])
			markCycle(arr[cur]);
		return false;
	}

	visited[cur] = GRAY;
	bool ret = DFS(arr[cur]);
	visited[cur] = BLACK;
	
	return ret;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> N;
	for(int i = 1; i <= N; i++)
		cin >> arr[i];

	for(int i = 1; i <= N; i++)
	{
		DFS(i);
	}

	cout << ans << '\n';
	for(int i = 1; i <= N; i++)
	{
		if(isCycle[i])
			cout << i << '\n';
	}

	return 0;
}