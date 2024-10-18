#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <list>

using namespace std;

typedef struct Node{
	int a, b, c;
}Node;

int a, b, c;
bool visited[201][201][201];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> a >> b >> c;

	vector<int> ans = {c};

	queue<Node> Q; Q.push({0, 0, c});
	visited[0][0][c] = true;
	while(!Q.empty())
	{
		Node cur = Q.front(); Q.pop();

		if(cur.a > 0)
		{
			Node newNode = {cur.a - min(cur.a, b - cur.b), cur.b + min(cur.a, b - cur.b), cur.c};
			if(!visited[newNode.a][newNode.b][newNode.c]) 
			{
				Q.push(newNode);
				visited[newNode.a][newNode.b][newNode.c] = true;
				if(newNode.a == 0)
					ans.push_back(newNode.c);
			}
			newNode = {cur.a - min(cur.a, c - cur.c), cur.b, cur.c + min(cur.a, c - cur.c)};
			if(!visited[newNode.a][newNode.b][newNode.c]) 
			{
				Q.push(newNode);
				visited[newNode.a][newNode.b][newNode.c] = true;
				if(newNode.a == 0)
					ans.push_back(newNode.c);
			}
		}
		if(cur.b > 0)
		{
			Node newNode = {cur.a + min(cur.b, a - cur.a), cur.b - min(cur.b, a - cur.a), cur.c};
			if(!visited[newNode.a][newNode.b][newNode.c]) 
			{
				Q.push(newNode);
				visited[newNode.a][newNode.b][newNode.c] = true;
				if(newNode.a == 0)
					ans.push_back(newNode.c);
			}
			newNode = {cur.a, cur.b - min(cur.b, c - cur.c), cur.c + min(cur.b, c - cur.c)};
			if(!visited[newNode.a][newNode.b][newNode.c]) 
			{
				Q.push(newNode);
				visited[newNode.a][newNode.b][newNode.c] = true;
				if(newNode.a == 0)
					ans.push_back(newNode.c);
			}
		}
		if(cur.c > 0)
		{
			Node newNode = {cur.a + min(cur.c, a - cur.a), cur.b, cur.c - min(cur.c, a - cur.a)};
			if(!visited[newNode.a][newNode.b][newNode.c]) 
			{
				Q.push(newNode);
				visited[newNode.a][newNode.b][newNode.c] = true;
				if(newNode.a == 0)
					ans.push_back(newNode.c);
			}
			newNode = {cur.a, cur.b + min(cur.c, b - cur.b), cur.c - min(cur.c, b - cur.b)};
			if(!visited[newNode.a][newNode.b][newNode.c]) 
			{
				Q.push(newNode);
				visited[newNode.a][newNode.b][newNode.c] = true;
				if(newNode.a == 0)
					ans.push_back(newNode.c);
			}
		}
	}

	sort(ans.begin(), ans.end());

	for(int a : ans)
		cout << a << ' ';
	return 0;
}