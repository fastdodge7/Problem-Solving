#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

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

int findNextDir(int r, int c, int cur)
{
	for(int offset = 0; offset < 8; offset++)
	{
		int nr = r + dy[(cur - offset + 8) % 8];
		int nc = c + dx[(cur - offset + 8) % 8];
		if(nr < 0 || nr >= 4 || nc < 0 || nc >= 4) continue;
		if((bloodBoard[nr][nc] > 0)) continue;
		if(nr == SharkR && nc == SharkC) continue;
		return (cur - offset + 8) % 8;
	}
	return -1;
}
 

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	fillSharkMove();

	for(int i = 0; i < 4; i++) for(int j = 0; j < 4; j++)
	{
		board[i][j] = {};
	}

	cin >> M >> S;
	for(int i = 0; i < M; i++)
	{
		int r, c, dir; cin >> r >> c >> dir;
		board[r - 1][c - 1].push_back(dir - 1);
	}

	cin >> SharkR >> SharkC;
	SharkR--; SharkC--;

	for(int i = 0; i < S; i++)
	{
		// 물고기 복제 마법
		for(int j = 0; j < 4; j++)
		{
			for(int k = 0; k < 4; k++)
				buffer[j][k] = vector<int>(board[j][k]);
		}

		// 물고기 이동.
		for(int r = 0; r < 4; r++)
		{
			for(int c = 0; c < 4; c++)
				board[r][c].clear();
		}
		for(int r = 0; r < 4; r++)
		{
			for(int c = 0; c < 4; c++)
			{
				for(int idx = 0; idx < buffer[r][c].size(); idx++)
				{
					int temp = findNextDir(r, c, buffer[r][c][idx]);
					if(temp == -1) 
						continue;
					int nr = r + dy[temp];
					int nc = c + dx[temp];
					board[nr][nc].push_back(temp);
				}
			}
		}

		// 상어 이동
		int move = -1;
		int cnt = -1;
		for(int moveIdx = 0; moveIdx < sharkMove.size(); moveIdx++)
		{
			int temp = 0;
			int cr = SharkR;
			int cc = SharkC;

			bool captured[4][4];
			fill(&captured[0][0], &captured[3][3] + 1, false);

			for(int step = 0; step < 3; step++) // 쳐먹었던거 또쳐먹네
			{
				cr += sdy[sharkMove[moveIdx][step] - '0'];
				cc += sdx[sharkMove[moveIdx][step] - '0'];
				if(cr < 0 || cr >= 4 || cc < 0 || cc >= 4)
				{
					break;
				}
				if(!captured[cr][cc])
					temp += board[cr][cc].size();
				captured[cr][cc] = true;
			}
			
			if(cr < 0 || cr >= 4 || cc < 0 || cc >= 4)
			{
				continue;
			}
			if(temp > cnt)
			{
				cnt = temp;
				move = moveIdx;
			}
		}
		cout << "상어 루트 : " << sharkMove[move] << '\n';
		for(int step = 0; step < 3; step++)
		{
			SharkR += sdy[sharkMove[move][step] - '0'];
			SharkC += sdx[sharkMove[move][step] - '0'];

			if(!board[SharkR][SharkC].empty())
			{
				board[SharkR][SharkC].clear();
				bloodBoard[SharkR][SharkC] = 3;
			}
		}

		// 냄새 관리
		for(int r = 0; r < 4; r++)
		{
			for(int c = 0; c < 4; c++)
			{

				if(bloodBoard[r][c] > 0)
					bloodBoard[r][c]--;

			}
		}

		//복제 완료
		for(int r = 0; r < 4; r++)
		{
			for(int c = 0; c < 4; c++)
			{
				for(int idx = 0; idx < buffer[r][c].size(); idx++)
				{
					if(buffer[r][c][idx] < 0) continue;
					board[r][c].push_back(buffer[r][c][idx]);
				}
			}
		}
	}

	int ans = 0;
	for(int i = 0; i < 4; i++) for(int j = 0; j < 4; j++)
	{
		
		ans += (int)board[i][j].size();
	}
	
	cout << ans;
	return 0;
}