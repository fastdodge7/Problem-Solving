#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <unordered_set>
#include <cassert>

using namespace std;

constexpr int dy[8] = {-1, -1, 0, 1, 1, 1, 0, -1};
constexpr int dx[8] = {0, 1, 1, 1, 0, -1, -1, -1};

typedef struct Fireball
{
	Fireball(int r, int c, int mass, int dir, int speed) : r(r), c(c), mass(mass), dir(dir), speed(speed) {}
	Fireball(const Fireball& other) : r(other.r), c(other.c), mass(other.mass), dir(other.dir), speed(other.speed) {}

	int r, c, mass, dir, speed;
}Fireball;

int N, M, K;
vector<Fireball> board[50][50];

void moveBalls()
{
	vector<Fireball> ballList;
	for(int i  = 0; i < N; i++) for(int j = 0; j < N; j++)
	{
		if(board[i][j].empty()) continue;
		for(Fireball ball : board[i][j])
			ballList.push_back(ball);

		board[i][j].clear();
	}

	for(Fireball cur : ballList)
	{
		cur.r = (cur.r + dy[cur.dir] * cur.speed + 500 * N) % N;
		cur.c = (cur.c + dx[cur.dir] * cur.speed + 500 * N) % N;
		board[cur.r][cur.c].push_back(cur);
	}
}

void combine()
{
	for(int i  = 0; i < N; i++) for(int j = 0; j < N; j++)
	{
		if(board[i][j].size() < 2) continue;
		int mass = 0, speed = 0;
		bool odd = false, even = false;
		for(Fireball ball : board[i][j])
		{
			mass += ball.mass;
			speed += ball.speed;
			if(ball.dir % 2 == 0) even = true;
			else odd = true;
		}
		mass /= 5;
		speed /= ((int)board[i][j].size());

		board[i][j].clear();
		if(mass == 0) continue;

		for(int dir : {0, 2, 4, 6})
			board[i][j].push_back(Fireball(i, j, mass, dir + (int)(odd & even), speed));
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	
	cin >> N >> M >> K;
	for(int i = 0; i < M; i++)
	{
		int r, c, m, s, d; cin >> r >> c >> m >> s >> d;
		board[r - 1][c - 1].push_back(Fireball(r - 1, c - 1, m, d, s));
	}

	for(int i = 0; i < K; i++)
	{
		moveBalls();
		combine();
	}

	int ans = 0;
	for(int i  = 0; i < N; i++) for(int j = 0; j < N; j++)
	{
		if(board[i][j].empty()) continue;

		for(Fireball ball : board[i][j])
			ans += ball.mass;
	}

	cout << ans;

	return 0;
}