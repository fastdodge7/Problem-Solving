#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

typedef struct Node {
	int value;
	string str;
}Node;

int T;
bool visited[10000];

string BFS(int start, int target) {
	queue<Node> Q; Q.push({ start, "" });
	visited[start] = true;
	while (!Q.empty())
	{
		int num = Q.front().value;
		string log = Q.front().str; Q.pop();
		if (num == target)
			return log;
		
		if (!visited[(2 * num) % 10000])
		{
			Q.push({ (2 * num) % 10000, log + "D" });
			visited[(2 * num) % 10000] = true;
		}
		if (!visited[(num - 1 + 10000) % 10000])
		{
			Q.push({ (num - 1 + 10000) % 10000, log + "S" });
			visited[(num - 1 + 10000) % 10000] = true;
		}

		int d1 = num / 1000;
		int d4 = num % 10;
		if (!visited[((num * 10) % 10000) + d1])
		{
			Q.push({ ((num * 10) % 10000) + d1, log + "L" });
			visited[((num * 10) % 10000) + d1] = true;
		}
		if (!visited[(num / 10) + 1000 * d4])
		{
			Q.push({ (num / 10) + 1000 * d4, log + "R" });
			visited[(num / 10) + 1000 * d4] = true;
		}
	}
	return "NONE";
}


int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> T;
	for (int test_case = 1; test_case <= T; test_case++)
	{
		int A, B; cin >> A >> B;
		cout << BFS(A, B) << '\n';
		fill(visited, visited + 10000, false);
	}
	return 0;
}