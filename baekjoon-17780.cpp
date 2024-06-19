#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

constexpr int BLUE = 2;
constexpr int RED = 1;

int dy[4] = {0, 0, -1, 1};
int dx[4] = {1, -1, 0, 0};

int N, K;

int color[12][12];

typedef struct Piece{
	int num;
	int r, c;
	int dir;

	bool shouldFlip()
	{
		int nr = r + dy[dir];
		int nc = c + dx[dir];
		if(nr < 0 || nr >= N || nc < 0 || nc >= N) return true;
		return color[nr][nc] == BLUE;
	}

	void move()
	{
		int nr = r + dy[dir];
		int nc = c + dx[dir];
		if(nr < 0 || nr >= N || nc < 0 || nc >= N) return;
		if(color[nr][nc] == BLUE) return;
		r = nr;
		c = nc;
	}

	void flip()
	{
		if(dir == 0) dir = 1;
		else if(dir == 1) dir = 0;
		else if(dir == 2) dir = 3;
		else if(dir == 3) dir = 2;
	}
}Piece;

vector<int> board[12][12];
vector<Piece> arr;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> N >> K;
	for(int i = 0; i < N; i++) for(int j = 0; j < N; j++)
	{
		board[i][j] = {};
		cin >> color[i][j];	
	}

	for(int i = 0; i < K; i++)
	{
		int r, c, dir; cin >> r >> c >> dir;
		board[r - 1][c - 1].push_back(i);
		arr.push_back({i, r - 1, c - 1, dir - 1});
	}

	int ans = 1;
	while(ans <= 1000)
	{
		for(int i = 0; i < K; i++)
		{
			Piece& pic = arr[i];
			int r = pic.r;
			int c = pic.c;
			if(board[r][c].empty() || board[r][c][0] != arr[i].num) continue; // 가장 아래가 아니면 이동 X

			if(pic.shouldFlip())
			{
				pic.flip();
			}
			pic.move(); // 앞이 파랑색이면 부동.

			if(r != pic.r || c != pic.c) // 실제로 움직였다면
			{
				if(color[pic.r][pic.c] == RED)
				{
					reverse(board[r][c].begin(), board[r][c].end());
				}
				for(auto k : board[r][c])
				{
					board[pic.r][pic.c].push_back(k);
					if(board[pic.r][pic.c].size() == 4)
					{
						cout << ans;
						return 0;
					}
					arr[k].r = pic.r;
					arr[k].c = pic.c;
				}
				board[r][c].clear();
			}
		}
			
		ans++;
	}

	cout << -1;
	return 0;
}