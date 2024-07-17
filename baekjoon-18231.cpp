#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cassert>

using namespace std;

int N, M;
vector<int> matrix[2001];
vector<int> destroyed;
bool isDestroyed[2001];
bool isAttacked[2001];
bool visited[2001];
vector<int> ans;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> N >> M;
	for(int i = 0; i < M; i++)
	{
		int a, b; cin >> a >> b;
		matrix[a].push_back(b);
		matrix[b].push_back(a);
	}
	int cnt; cin >> cnt;
	for(int i = 0; i < cnt; i++)
	{
		int a; cin >> a;
		isDestroyed[a] = true;
		destroyed.push_back(a);
	}

	for(int cand : destroyed)
	{
		bool canAttack = true;
		for(int adj : matrix[cand])
		{
			if(!isDestroyed[adj])
			{
				canAttack = false;
				break;
			}
		}

		if(canAttack)
		{
			isAttacked[cand] = true;
			ans.push_back(cand);
		}
	}

	for(int i = 1; i <= N; i++)
	{
		if(isAttacked[i])
		{
			visited[i] = true;
			for(int adj : matrix[i])
				visited[adj] = true;
		}
	}

	for(int i = 1; i <= N; i++)
	{
		if(isDestroyed[i] != visited[i])
		{
			cout << -1;
			return 0;
		}
	}

	cout << ans.size() << '\n';
	for(int a : ans)
		cout << a << ' ';



	return 0;
}

/*
1. 폭격 가능한 모든 곳에 폭격 -> 인접한 모든 곳이 박살난 곳이라면 100% 박살 난다.
2. 박살났지만 인접한 곳에 멀쩡한 곳이 있는 경우 -> 인접한 곳에 폭격을 맞은 곳이 있나 확인해야 한다.
*/