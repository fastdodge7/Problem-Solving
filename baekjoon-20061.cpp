#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <unordered_set>
#include <cassert>

using namespace std;

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, -1, 0, 1};

int N;
int greenBoard[6][4];
int blueBoard[6][4];
int ans = 0;

void placeBlock(int x, int y, int type)
{
	if(type == 0)
	{
		int blueLevel = 5;
		int greenLevel = 5;
		for(int i = 0; i < 6; i++)
		{
			if(greenBoard[i][x] != 0)
			{
				greenLevel = i - 1;
				break;
			}
		}
		
		for(int i = 0; i < 6; i++)
		{		
			if(blueBoard[i][y] != 0)
			{
				blueLevel = i - 1;
				break;
			}
		}

		assert(greenBoard[greenLevel][x] == 0);
		assert(blueBoard[blueLevel][y] == 0);
		greenBoard[greenLevel][x] = type + 1;
		blueBoard[blueLevel][y] = type + 1;
	}
	else if(type == 1)
	{
		int blueLevel = 4;
		int greenLevel = 5;
		for(int i = 0; i < 6; i++)
		{
			if(greenBoard[i][x] != 0 || greenBoard[i][x + 1] != 0)
			{
				greenLevel = i - 1;
				break;
			}
		}
		for(int i = 0; i < 5; i++)
		{
			if(blueBoard[i + 1][y] != 0 || blueBoard[i][y] != 0)
			{
				blueLevel = i - 1;
				break;
			}
		}
		assert(greenBoard[greenLevel][x] == 0 && greenBoard[greenLevel][x + 1] == 0);
		assert(blueBoard[blueLevel][y] == 0 && blueBoard[blueLevel + 1][y] == 0);
		greenBoard[greenLevel][x] = greenBoard[greenLevel][x + 1] = type + 1;
		blueBoard[blueLevel][y] = blueBoard[blueLevel + 1][y] = type + 1;
	}
	else
	{
		int blueLevel = 5;
		int greenLevel = 4;
		for(int i = 0; i < 5; i++)
		{
			if(greenBoard[i][x] != 0 || greenBoard[i + 1][x] != 0)
			{
				greenLevel = i - 1;
				break;
			}
		}
		for(int i = 0; i < 6; i++)
		{
			if(blueBoard[i][y] != 0 || blueBoard[i][y + 1] != 0)
			{
				blueLevel = i - 1;
				break;
			}
		}
		assert(greenBoard[greenLevel][x] == 0 && greenBoard[greenLevel + 1][x] == 0);
		assert(blueBoard[blueLevel][y] == 0 && blueBoard[blueLevel][y + 1] == 0);
		greenBoard[greenLevel][x] = greenBoard[greenLevel + 1][x] = type + 1;
		blueBoard[blueLevel][y] = blueBoard[blueLevel][y + 1] = type + 1;
	}
}

void clearRow()
{
	for(int r = 0; r < 6; r++)
	{
		bool gflag = false, bflag = false;
		for(int c = 0; c < 4; c++)
		{
			if(greenBoard[r][c] == 0) gflag = true;
			if(blueBoard[r][c] == 0) bflag = true;
		}
		if(!gflag)
		{
			for(int c = 0; c < 4; c++)
				greenBoard[r][c] = 0;
			
			for(int c = 0; c < 4; c++) for(int pr = r - 1; pr >= 0; pr--)
				greenBoard[pr + 1][c] = greenBoard[pr][c];
			
			ans++;
		}
		if(!bflag)
		{
			for(int c = 0; c < 4; c++)
				blueBoard[r][c] = 0;
			
			for(int c = 0; c < 4; c++) for(int pr = r - 1; pr >= 0; pr--)
				blueBoard[pr + 1][c] = blueBoard[pr][c];
			
			ans++;
		}
	}
}

void printBoard()
{
	cout << "===============Green Board=================\n";
	for(int i = 0; i < 6; i++)
	{
		for(int j = 0; j < 4; j++)
			cout << greenBoard[i][j] << ' ';
		cout << '\n';
	}
	cout << "===============Blue Board=================\n";
	for(int i = 0; i < 6; i++)
	{
		for(int j = 0; j < 4; j++)
			cout << blueBoard[i][j] << ' ';
		cout << '\n';
	}
}

void arrange()
{
	int gCnt = 0;
	for(int r = 0; r < 2; r++)
	{
		for(int c = 0; c < 4; c++)
		{
			if(greenBoard[r][c])
			{
				gCnt++;
				break;
			}
		}
	}

	int bCnt = 0;
	for(int r = 0; r < 2; r++)
	{
		for(int c = 0; c < 4; c++)
		{
			if(blueBoard[r][c])
			{
				bCnt++;
				break;
			}
		}
	}

	for(int r = 5; r >= gCnt; r--)
	{
		for(int c = 0; c < 4; c++)
			greenBoard[r][c] = greenBoard[r - gCnt][c];
	}
	for(int r = 5; r >= bCnt; r--)
	{
		for(int c = 0; c < 4; c++)
			blueBoard[r][c] = blueBoard[r - bCnt][c];
	}
	for(int c = 0; c < 4; c++)
	{
		blueBoard[0][c] = blueBoard[1][c] = 0;
		greenBoard[0][c] = greenBoard[1][c] = 0;
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	
	cin >> N;
	for(int i = 0; i < N; i++)
	{
		int type, x, y; cin >> type >> x >> y;
		placeBlock(y, x, type - 1);
		clearRow();
		arrange();
		printBoard();
	}

	cout << ans << '\n';
	int cnt = 0;
	for(int i = 0; i < 6; i++) for(int j = 0; j < 4; j++)
	{
		if(blueBoard[i][j] != 0) cnt++;
		if(greenBoard[i][j] != 0) cnt++;
	}
	cout << cnt << '\n';
	return 0;
}