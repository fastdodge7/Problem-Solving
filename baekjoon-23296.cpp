#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cassert>

using namespace std;

constexpr int SHARK = -1;

constexpr int dy[8] = {0, -1, -1, -1, 0, 1, 1, 1};
constexpr int dx[8] = {-1, -1, 0, 1, 1, 1, 0, -1};

constexpr int sdy[4] = {-1, 0, 1, 0};
constexpr int sdx[4] = {0, -1, 0, 1};

vector<string> sharkMove;


int SharkR, SharkC;

int M, S;
vector<int> board[4][4];
int bloodBoard[4][4];
vector<int> buffer[4][4];

void printBoard()
{
	for(int i = 0; i < 4; i++)
	{
		for(int j = 0; j < 4; j++)
		{
			cout << board[i][j].size() << ' ';
		}
		cout << '\n';
	}
}

void fillSharkMove()
{
	for(int i = 1; i <= 4; i++)
	{
		for(int j = 1; j <= 4; j++)
		{
			for(int k = 1; k <= 4; k++)
			{
				sharkMove.push_back(to_string(100 * i + 10 * j + k));
				sharkMove.back()[0] -= 1;
				sharkMove.back()[1] -= 1;
				sharkMove.back()[2] -= 1;
			}
		}
	}
}

bool canMoveFish(int nr, int nc)
{
	if(nr < 0 || nr >= 4 || nc < 0 || nc >= 4) // 격자를 벗어남
		return false;
	if(bloodBoard[nr][nc] > 0) // 물고기 냄새가 남아있음
		return false;
	if(nr == SharkR && nc == SharkC) // 상어가 있음
		return false;
	
	return true;
}

int findNextDir(int r, int c, int cur)
{
	for(int offset = 0; offset < 8; offset++)
	{
		int nr = r + dy[(cur - offset + 8) % 8];
		int nc = c + dx[(cur - offset + 8) % 8];
		if(canMoveFish(nr, nc))
			return (cur - offset + 8) % 8;
	}
	return -1;
}

void castCopy()
{
	for(int i = 0; i < 4; i++) // 버퍼에 현 상태 복제.
	{
		for(int j = 0; j < 4; j++)
		{
			
			buffer[i][j] = vector<int>(board[i][j]);
			board[i][j].clear();

		}
	}
}

void moveFish()
{
	for(int i = 0; i < 4; i++) 
	{
		for(int j = 0; j < 4; j++)
		{
			for(int idx = 0; idx < buffer[i][j].size(); idx++)
			{
				int direction = findNextDir(i, j, buffer[i][j][idx]);
				if(direction == -1) // 움직일 수 없는 경우
				{
					board[i][j].push_back(buffer[i][j][idx]);
				}
				else
				{

					board[i + dy[direction]][j + dx[direction]].push_back(direction);
				}
			}
		}
	}
}

int countRouteFish(const string& route) //범인1
{
	vector<pair<int, int>> visited;

	int r = SharkR;
	int c = SharkC;
	int ret = 0;
	for(char dir : route)
	{
		r = r + sdy[dir - '0'];
		c = c + sdx[dir - '0'];
		//cout << "(" << r << ", " << c <<")\n";
		if(r < 0 || r >= 4 || c < 0 || c >= 4)
		{
			return -1;
		}


		ret += board[r][c].size();
		for(const auto& history : visited)
		{
			if(history == make_pair(r, c))
			{
				ret -= board[r][c].size();
				break;
			}
		}
		visited.push_back({r, c});
	}
	return ret;
}

string findOptimalSharkMove()
{
	string ret = "";
	int cnt = -1;
	for(int i = 0; i < sharkMove.size(); i++)
	{
		int temp = countRouteFish(sharkMove[i]);
		if(cnt < temp)
		{
			//cout << "Cand Route : " << sharkMove[i] << " / CNT : " << temp << '\n';
			ret = sharkMove[i];
			cnt = temp;
		}
	}
	
	//cout << "Optimal Route : " << ret << " / CNT : " << cnt << '\n';
	assert(ret.size() == 3);
	return ret;
}

void moveShark()
{
	string route = findOptimalSharkMove();
	for(char dir : route)
	{
		SharkR += sdy[dir - '0'];
		SharkC += sdx[dir - '0'];

		if(board[SharkR][SharkC].size() > 0)
		{
			bloodBoard[SharkR][SharkC] = 3;
		}
		board[SharkR][SharkC].clear();
	}
}

void removeBlood()
{
	for(int i = 0; i < 4; i++) for(int j = 0; j < 4; j++)
	{
		if(bloodBoard[i][j] > 0)
			bloodBoard[i][j]--;
	}
}

void pasteFish()
{
	for(int i = 0; i < 4; i++) for(int j = 0; j < 4; j++)
	{
		for(int idx = 0; idx < buffer[i][j].size(); idx++)
		{
			board[i][j].push_back(buffer[i][j][idx]);
		}
	}
}
 

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	fillSharkMove();

	cin >> M >> S;
	for(int i = 0; i < M; i++)
	{
		int r, c, dir;
		cin >>r >> c >> dir;
		board[r - 1][c - 1].push_back(dir - 1);
	}
	cin >> SharkR >> SharkC;
	SharkR--; SharkC--;

	for(int phase = 1; phase <= S; phase++)
	{
		castCopy();
		moveFish();
		//printBoard();
		moveShark();
		removeBlood();
		pasteFish();
	}

	int ans = 0;
	for(int i = 0; i < 4; i++) for(int j = 0; j < 4; j++)
	{
		ans += (int)board[i][j].size();
	}

	cout << ans;
	
	return 0;
}