#include <algorithm>
#include <iostream>
#include <vector>
#include <queue>
#include <string>

using namespace std;

constexpr int dy[4] = {0, -1, 0, 1};
constexpr int dx[4] = {-1, 0, 1, 0};

int T, N, M;
string board[100];
string keys = "";
int visited[100][100];

const int a = 'A';

int BFS()
{
	int ans = 0;
	
	queue<pair<int, int>> Q;
	for(int i = 0; i < M; i++)
	{
		if(board[0][i] != '*')
		{
			Q.push({0, i}); 
			visited[0][i] = true; 
		}
		if(board[N - 1][i] != '*')
		{
			visited[N - 1][i] = true;
			Q.push({N - 1, i});
		}
	}
	for(int i = 0; i < N; i++)
	{
		if(board[i][M - 1] != '*')
		{
			Q.push({i, M - 1}); 
			visited[i][M-1] = true; 
		}
		if(board[i][0] != '*')
		{
			visited[i][0] = true;
			Q.push({i, 0});
		}
	}

	bool flag = false;
	queue<pair<int, int>> checker;
	while(!Q.empty())
	{
		auto [cr, cc] = Q.front(); Q.pop();

		if('A' <= board[cr][cc] && board[cr][cc] <= 'Z')
		{
			if(keys.find(board[cr][cc] + 'a' - 'A') == keys.npos)
			{
				if(!checker.empty() && checker.front().first == cr && checker.front().second == cc)
					break;
				checker.push({cr, cc});
				Q.push({cr, cc});
				continue;
			}
		}
		checker = queue<pair<int, int>>();
		if('a' <= board[cr][cc] && board[cr][cc] <= 'z')
		{
			keys.push_back(board[cr][cc]);
			board[cr][cc] = '.';
		}

		if(board[cr][cc] == '$')
		{
			ans++;
			board[cr][cc] = '.';
		}

		for(int i = 0; i < 4; i++)
		{
			int nr = cr + dy[i];
			int nc = cc + dx[i];
			if(nr < 0 || nr >= N || nc < 0 || nc >= M) continue;
			if(board[nr][nc] == '*') continue;
			if(visited[nr][nc] == true) continue;

			visited[nr][nc] = true;	
			Q.push({nr, nc});		
		}
	}
	return ans;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	cin >> T;
	for(int test_case = 1; test_case <= T; test_case++)
	{
		fill(&visited[0][0], &visited[99][99] + 1, false);
		cin >> N >> M;

		for(int i = 0; i < N; i++)
			cin >> board[i];

		string temp; cin >> temp;
		if(temp != "0") keys = temp;

		cout << BFS() << '\n';
		keys = "";
	}
	
	return 0;
}
