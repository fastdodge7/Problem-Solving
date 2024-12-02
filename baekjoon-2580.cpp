#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int rowCheck[9];
int colCheck[9];
int boxCheck[9];

int board[9][9];
bool flag = false;
vector<pair<int, int>> arr;

void DFS(int idx)
{
	if(idx == arr.size())
	{
		flag = true;
		for(int i = 0; i < 9; i++)
		{
			for(int j = 0; j < 9; j++)
				cout << board[i][j] << ' ';
			cout << '\n';
		}
		return;
	}

	auto [r, c] = arr[idx];
	for(int cand = 1; cand <= 9; cand++)
	{
		if((rowCheck[r] & (1 << cand)) != 0) continue;
		if((colCheck[c] & (1 << cand)) != 0) continue;
		if((boxCheck[3 * (r / 3) + (c / 3)] & (1 << cand)) != 0) continue;

		rowCheck[r] = (rowCheck[r] | (1 << cand));
		colCheck[c] = (colCheck[c] | (1 << cand));
		boxCheck[3 * (r / 3) + (c / 3)] = (boxCheck[3 * (r / 3) + (c / 3)] | (1 << cand));
		board[r][c] = cand;

		DFS(idx + 1);

		if(flag) break;

		board[r][c] = 0;
		rowCheck[r] = (rowCheck[r] ^ (1 << cand));
		colCheck[c] = (colCheck[c] ^ (1 << cand));
		boxCheck[3 * (r / 3) + (c / 3)] = (boxCheck[3 * (r / 3) + (c / 3)] ^ (1 << cand));
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	
	for(int i = 0; i < 9; i++)
	{
		for(int j = 0; j < 9; j++)
		{
			cin >> board[i][j];
			if(board[i][j] == 0)
				arr.push_back({i, j});
			else
			{
				rowCheck[i] = (rowCheck[i] | (1 << board[i][j]));
				colCheck[j] = (colCheck[j] | (1 << board[i][j]));
				boxCheck[3 * (i / 3) + (j / 3)] = (boxCheck[3 * (i / 3) + (j / 3)] | (1 << board[i][j]));
			}
		}
	}

	DFS(0);
	
	return 0;
}