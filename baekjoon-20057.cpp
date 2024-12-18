#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <unordered_set>
#include <cassert>

using namespace std;

constexpr int dy[4] = {0, 1, 0, -1};
constexpr int dx[4] = {-1, 0, 1, 0};

int N;
vector<tuple<int, int, int>> range = {{-2, 0, 5}, {-1, -1, 10}, {-1, 1, 10}, {0, -2, 2}, {0, -1, 7}, {0, 1, 7}, {0, 2, 2}, {1, -1, 1}, {1, 1, 1}, {-1, 0, 999}};
int board[500][500];

vector<tuple<int, int, int>> rotate(int cnt, int cr, int cc)
{
	vector<tuple<int, int, int>> ret;
	int sum = 0;
	for(auto [c, r, percent] : range)
	{
		for(int i = 0; i < cnt; i++)
		{
			int temp = c;
			c = r;
			r = -temp;
		}
		r = cr + r;
		c = cc + c;
		if(percent == 999)
			ret.push_back({r, c, board[cr][cc] - sum});
		else
		{
			ret.push_back({r, c, board[cr][cc] * percent / 100});
			sum += board[cr][cc] * percent / 100;
		}
	}

	board[cr][cc] = 0;
	return ret;
}

int distribute(const vector<tuple<int, int, int>>& data)
{
	int ret = 0;
	for(auto [r, c, sand] : data)
	{
		if(r < 0 || r >= N || c < 0 || c >= N)
		{
			ret += sand;
			continue;
		}
		board[r][c] += sand;
	}
	return ret;
}

void printBoard()
{
	cout << "===================================\n";
	for(int i = 0; i < N; i++)
	{
		for(int j = 0; j < N; j++)
		{
			cout << board[i][j] << ' ';
		}
		cout << '\n';
	}
	cout << "===================================\n";
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	
	cin >> N;
	for(int i = 0; i < N; i++) for(int j = 0; j < N; j++)
		cin >> board[i][j];

	int cnt = 0;
	int dir = 0;
	int ans = 0;

	int r = N / 2, c = N / 2;
	for(int len = 1; cnt < N * N - 1; len++)
	{
		if(cnt + len == N * N)
		{
			for(int i= 0; i < len - 1; i++)
			{
				r += dy[dir % 4];
				c += dx[dir % 4];
				ans += distribute(rotate(dir % 4, r, c));
				cnt++;
			}
			break;
		}

		for(int i= 0; i < len; i++)
		{
			r += dy[dir % 4];
			c += dx[dir % 4];
			ans += distribute(rotate(dir % 4, r, c));
			cnt++;
		}

		for(int i= 0; i < len; i++)
		{
			r += dy[(dir + 1) % 4];
			c += dx[(dir + 1) % 4];
			ans += distribute(rotate((dir + 1) % 4, r, c));
			cnt++;
		}

		dir = (dir + 2) % 4;
	}

	cout << ans;
	return 0;
}