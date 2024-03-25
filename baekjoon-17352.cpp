#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int N;
vector<int> matrix[300001];

int marking[300001];
int targetA = 0, targetB = 0;

void BFS(int start, int marker)
{
	if(marking[start] != 0) return;
	
	queue<int> Q; Q.push(start);
	marking[start] = marker;
	
	if(targetA == 0)
		targetA = start;
	else
		targetB = start;
	
	while(!Q.empty())
	{
		int cur = Q.front(); Q.pop();
		for(int next : matrix[cur])
		{
			if(marking[next] != 0) continue;
			marking[next] = marker;
			Q.push(next);
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	
	cin >> N;
	for(int i = 0; i < N - 2; i++)
	{
		int a, b; cin >> a >> b;
		matrix[a].push_back(b);
		matrix[b].push_back(a);
	}
	
	BFS(1, 1);
	for(int i = 2; i <= N; i++)
	{
		BFS(i, 2);
	}
	
	cout << targetA << ' ' << targetB;
	return 0;
}