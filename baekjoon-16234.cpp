#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>

using namespace std;

int dy[4] = {0, -1, 0, 1};
int dx[4] = {-1, 0, 1, 0};

int N, L, R;
int arr[50][50];
bool visited[50][50];

bool BFS(int startR, int startC)
{
	visited[startR][startC] = true;
	int cnt = 0;
	int acc = 0;
	queue<pair<int, int>> Q; Q.push({startR, startC});
	vector<pair<int, int>> vec;
	while(!Q.empty())
	{
		vec.push_back(Q.front());
		int r = Q.front().first;
		int c = Q.front().second; Q.pop();
		
		cnt++;
		acc += arr[r][c];
		for(int i = 0; i < 4; i++)
		{
			int nr = r + dy[i];
			int nc = c + dx[i];
			if(nr < 0 || nr >= N || nc < 0 || nc >= N) continue;
			
			if(visited[nr][nc]) continue;
			if(L <= abs(arr[r][c] - arr[nr][nc]) && abs(arr[r][c] - arr[nr][nc]) <= R)
			{
				Q.push({nr, nc});
				visited[nr][nc] = true;
			}
		}
	}
	for(auto p : vec)
		arr[p.first][p.second] = acc / cnt;
	return !(vec.size() == 1);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> L >> R;
	for(int i = 0; i < N; i++) for(int j = 0; j < N; j++)
		cin >> arr[i][j];

	bool flag = false;
	int ans = 0;
	do
	{
		flag = false;
		for(int i = 0; i < N; i++) for(int j = 0; j < N; j++)
		{
			if(!visited[i][j])
			{
				bool temp = BFS(i,j);
				flag = flag || temp;
			}
		}
		
		if(flag)
			ans++;
		fill(&visited[0][0], &visited[N - 1][N - 1] + 1, false);
			
	}while(flag);

	cout << ans;
	
	return 0;
}