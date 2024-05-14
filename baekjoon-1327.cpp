#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <unordered_set>

using namespace std;

typedef struct Node{
	int cnt;
	string state;
}Node;

int N, K;
string ans = "";
unordered_set<string> visited;

int BFS(const string& str)
{
	queue<Node> Q; Q.push({0, str});
	visited.insert(str);

	while(!Q.empty())
	{
		auto cur = Q.front(); Q.pop();
		if(cur.state == ans)
			return cur.cnt;

		for(int i = 0; i <= N - K; i++)
		{
			string newState = string(cur.state);
			reverse(newState.begin() + i, newState.begin() + i + K);
			if(visited.find(newState) == visited.end())
			{
				visited.insert(newState);
				Q.push({cur.cnt + 1, newState});
			}
		}
	}

	return -1;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	string inputStr = "";
	cin >> N >> K;
	for(int i = 0; i < N; i++)
	{
		int temp; cin >> temp;
		inputStr += ('0' + temp);
		ans += ('0' + i + 1);
	}

	cout << BFS(inputStr);
	return 0;
}
