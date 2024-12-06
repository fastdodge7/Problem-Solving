#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <unordered_set>

using namespace std;

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, -1, 0, 1};

int N;
int board[20][20];
unordered_set<int> st[401];

void printBoard()
{
	for(int i = 0; i < N; i++)
	{
		for(int j = 0; j < N; j++)
		{
			cout << board[i][j] << ' ';
		}
		cout << '\n';
	}
}

void locate(int num, const vector<int>& arr)
{
	int favorCnt = 0;
	int emptyCnt = 0;
	int r = -1, c = -1;
	for(int i = 0; i < N; i++) for(int j = 0; j < N; j++)
	{

		if(board[i][j] != 0) continue;
		

		int tf = 0;



		int te = 0;
		for(int d = 0; d < 4; d++)
		{
			int nr = i + dy[d];
			int nc = j + dx[d];
			if(nr < 0 || nr >= N || nc < 0 || nc >= N) continue;
			if(st[num].find(board[nr][nc]) != st[num].end())
				tf++;
			
			if(board[nr][nc] == 0) 
				te++;
		}

		if((tf > favorCnt) || (tf == favorCnt && te > emptyCnt))
		{
			r = i;
			c = j;
			favorCnt = tf;
			emptyCnt = te;
			continue;
		}
		if(r == -1 && c == -1)
		{
			r = i;
			c = j;
			continue;
		}
	}
	board[r][c] = num;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	
	cin >> N;
	for(int i = 1; i <= N * N; i++)
	{
		int num; cin >> num;
		vector<int> v;
		for(int j  = 0; j < 4; j++)
		{
			int a; cin >> a;
			v.push_back(a);
			st[num].insert(a);
		}

		locate(num, v);

	}
	//printBoard();
	int ans = 0;

	for(int i = 0; i < N; i++) for(int j = 0; j < N; j++)
	{
		int sat = 0;
		for(int d = 0; d < 4; d++)
		{
			int nr = i + dy[d];
			int nc = j + dx[d];
			if(nr < 0 || nr >= N || nc < 0 || nc >= N) continue;
			if(st[board[i][j]].find(board[nr][nc]) != st[board[i][j]].end())
			{
				if(sat == 0) sat = 1;
				else sat *= 10;
			}
		}
		ans += sat;
	}

	cout << ans;
	return 0;
}