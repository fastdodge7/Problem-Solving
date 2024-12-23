#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <deque>
#include <list>
#include <cassert>

using namespace std;

constexpr int dy[4] = {0, 1, 0, -1};
constexpr int dx[4] = {-1, 0, 1, 0};

int N, Q;
int board[55][55];
int idx[55][55];
vector<int> arr;
int ans = 0;

void initIdx()
{
	int r = N / 2, c = N / 2;
	int len = 1;
	int dir = 0;
	int cnt = 0;
	while(r >= 0 && c >= 0)
	{
		for(int i = 0; i < len; i++)
		{
			r += dy[dir % 4];
			c += dx[dir % 4];
			if(r < 0 || c < 0) return;
			idx[r][c] = ++cnt;
		}
		for(int i = 0; i < len; i++)
		{
			r += dy[(dir + 1) % 4];
			c += dx[(dir + 1) % 4];
			if(r < 0 || c < 0) return;
			idx[r][c] = ++cnt;
		}
		len++;
		dir = (dir + 2) % 4;
	}
}

void initArr()
{
	int r = N / 2, c = N / 2;
	int len = 1;
	int dir = 0;
	while(r >= 0 && c >= 0)
	{
		for(int i = 0; i < len; i++)
		{
			r += dy[dir];
			c += dx[dir];
			if(r < 0 || c < 0 || board[r][c] == 0) return;
			arr.push_back(board[r][c]);
		}
		for(int i = 0; i < len; i++)
		{
			r += dy[(dir + 1) % 4];
			c += dx[(dir + 1) % 4];
			if(r < 0 || c < 0 || board[r][c] == 0) return;
			arr.push_back(board[r][c]);
		}
		len++;
		dir = (dir + 2) % 4;
	}
}

void blizzard(int direction, int dist)
{
	int converter[5] = {0, 3, 1, 0, 2};
	direction = converter[direction];

	int r = N / 2, c = N / 2;
	for(int i = 1; i <= dist; i++)
	{
		r += dy[direction];
		c += dx[direction];

		if(arr.size() <= idx[r][c] - 1) break;
		arr[idx[r][c] - 1] = 0;
	}

	vector<int> narr;
	for(int elem : arr)
	{
		if(elem == 0) continue;
		narr.push_back(elem);
	}

	arr = vector<int>(narr);
}

bool explode()
{
	vector<int> buff;
	vector<int> narr;
	bool ret = false;
	for(int elem : arr)
	{
		if(buff.empty() || buff.back() == elem)
		{
			buff.push_back(elem);
		}
		else
		{
			if(buff.size() <= 3)
			{
				for(int jj : buff)
					narr.push_back(jj);
			}
			else
			{
				ret = true;
				ans += (buff.size() * buff.back());
			}
				
			buff.clear();
			buff.push_back(elem);
		}
	}
	if(buff.size() <= 3)
	{
		for(int jj : buff)
			narr.push_back(jj);
	}
	else
	{
		ret = true;
		ans += (buff.size() * buff.back());
	}

	arr = vector<int>(narr);
	return ret;
}

void populate()
{
	vector<int> buff;
	vector<int> narr;
	for(int elem : arr)
	{
		if(buff.empty() || buff.back() == elem)
		{
			if(narr.size() >= N * N - 1) break;
			buff.push_back(elem);
		}
		else
		{
			assert(buff.size() < 4);
			if(narr.size() >= N * N - 1) break;
			narr.push_back(buff.size());
			if(narr.size() >= N * N - 1) break;
			narr.push_back(buff.back());
			buff.clear();
			buff.push_back(elem);
		}
	}
	if(!buff.empty())
	{
		if(narr.size() >= N * N - 1)
		{
			arr = vector<int>(narr);
			return;
		}
		narr.push_back(buff.size());
		if(narr.size() >= N * N - 1)
		{
			arr = vector<int>(narr);
			return;
		}
		narr.push_back(buff.back());
	}

	arr = vector<int>(narr);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	
	cin >> N >> Q;
	for(int i = 0; i < N; i++)
	{
		for(int j = 0; j < N; j++)
			cin >> board[i][j];
	}

	initIdx();
	initArr();

	for(int i = 0; i < Q; i++)
	{
		int d, dst; cin >> d >> dst;

		blizzard(d, dst);
		while(explode())
		{

		}
		populate();
	}

	cout <<  ans << '\n';
	return 0;
}	