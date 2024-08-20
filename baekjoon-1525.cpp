#include <iostream>
#include <algorithm>
#include <queue>
#include <unordered_set>
using namespace std;

constexpr int dy[4] = {0, -1, 0, 1};
constexpr int dx[4] = {-1, 0, 1, 0};

int R, C;
unordered_set<string> visited;

pair<int, int> getCoord(const string& state)
{
	for(int i = 0; i < state.size(); i++)
	{
		if(state[i] == '0')
			return {i / 3, i % 3};
	}
	return {-1, -1};
}

int BFS(const string& initState)
{
	queue<pair<string, int>> Q; Q.push({initState, 0});
	visited.insert(initState);
	
	if(initState == "123456780") return 0;

	while(!Q.empty())
	{
		auto [cur, cnt] = Q.front(); Q.pop();
		auto [curR, curC] = getCoord(cur);

		for(int i = 0; i < 4; i++)
		{
			int nr = curR + dy[i];
			int nc = curC + dx[i];
			if(nr < 0 || nr >= 3 || nc < 0 || nc >= 3) continue;

			int nIdx = nr * 3 + nc;
			string newState = string(cur);
			swap(newState[nIdx], newState[curR * 3 + curC]);
			if(newState == "123456780") return cnt + 1;
			if(visited.find(newState) != visited.end()) continue;
			Q.push({newState, cnt + 1});
			visited.insert(newState);
		}
	}
	return -1;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	
	string initState = "";
	for(int i = 0; i < 9; i++)
	{
		char c; cin >> c;
		initState += c;
	}

	cout << BFS(initState) << '\n';

	return 0;
}