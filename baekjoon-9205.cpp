#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <cmath>

using namespace std;

typedef struct Node{
	int r, c;
	bool operator==(const Node& other) const {
		return r == other.r && c == other.c;
	}
	int operator-(const Node& other) const {
		return abs(r - other.r) + abs(c - other.c);
	}
}Node;

Node arr[102];
bool visited[102];

int T, N;

string BFS()
{
	fill(visited, visited + 102, false);
	queue<Node> Q; Q.push(arr[0]);
	visited[0] = true;
	const Node& festival = arr[N + 1];

	while(!Q.empty())
	{
		auto cur = Q.front(); Q.pop();
		if(cur == festival)
			return "happy";
		
		for(int i = 1; i < N + 2; i++)
		{
			if(visited[i]) continue;
			if(cur - arr[i] > 1000) continue;

			Q.push(arr[i]);
			visited[i] = true;
		}
	}
	return "sad";
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> T;
	for(int test_case = 1; test_case <= T; test_case++)
	{
		cin >> N;
		for(int i = 0; i < N + 2; i++)
		{
			int r, c; cin >> r >> c;
			arr[i] = {r, c};
		}

		cout << BFS() << '\n';
	}

	return 0;
}
