#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <queue>
#include <unordered_map>
#include <cmath>
#include <cstring>
#include <bitset>

using namespace std;

typedef pair<int, int> Node;

int a, b, c, d;
struct pair_hash {
	template <class T1, class T2>
	std::size_t operator () (const std::pair<T1,T2> &p) const {
		auto h1 = std::hash<T1>{}(p.first);
		auto h2 = std::hash<T2>{}(p.second);

		return h1 ^ h2;  
	}
};

unordered_map<Node, int, pair_hash> dp;

Node nextNode(const Node& node, int idx)
{
	switch(idx){
		case 0:
			return {0, node.second};
		case 1:
			return {node.first, 0};
		case 2:
			return {a, node.second};
		case 3:
			return {node.first, b};
		case 4:
		{
			int diff = node.first - (b - node.second);
			if(diff >= 0)
				return {diff, b};
			else
				return {0, node.second + node.first};
		}	
		case 5:
		{
			int diff = node.second - (a - node.first);
			if(diff >= 0)
				return {a, diff};
			else
				return {node.second + node.first, 0};
		}
			
		default:
			return node;
	}
}

int BFS()
{
	Node dest = {c, d};
	dp.insert({{0, 0}, 0});
	queue<Node> Q; Q.push({0, 0});

	while(!Q.empty())
	{
		auto cur = Q.front(); Q.pop();
		if(cur == dest) return dp[cur];

		for(int i = 0; i < 6; i++)
		{
			auto next = nextNode(cur, i);
			if(next.first > a) continue;
			if(next.second > b) continue;
			if(dp.find(next) == dp.end())
			{
				dp.insert({next, dp[cur] + 1});
				Q.push(next);
			}
		}
	}
	return -1;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> a >> b >> c >> d;
	cout << BFS() << '\n';

	return 0;
}
