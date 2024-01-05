#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int N; 
vector<int> matrix[51];
bool visited[51];

int BFS(int start)
{
	fill(visited, visited + 51, false);
	queue<pair<int, int>> Q; Q.push({start, 0});
	visited[start] = true;
	
	int ret = 0;
	while(!Q.empty())
	{
		int cur = Q.front().first;
		int bridge = Q.front().second; Q.pop();
		ret = bridge;
		for(int next : matrix[cur])
		{
			if(visited[next]) continue;
			visited[next] = true;
			Q.push({next, bridge + 1});
		}
	}
	return ret;
}

int main() {
	cin >> N;
	while(1)
	{
		int a, b; cin >>a >> b;
		if(a== -1 && b == -1) break;
		matrix[a].push_back(b);
		matrix[b].push_back(a);
	}
	
	vector<pair<int, int>> ans;
	for(int i = 1; i <= N; i++)
		ans.push_back({BFS(i), i});
	
	sort(ans.begin(), ans.end());
	
	int point = ans[0].first;
	while(ans.back().first != point)
		ans.pop_back();
	
	cout << point << ' ' << ans.size() << '\n';
	for(auto a : ans)
		cout << a.second << ' ';
	return 0;
}