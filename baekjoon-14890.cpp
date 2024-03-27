#include <iostream>
#include <algorithm>

using namespace std;

int N, L;
int board[100][100];
int isPlaced[100][100];

bool checkHorDesc(int r, int c)
{
	for(int i = 1; i <= L; i++)
	{
		int nc = c + i;
		if(nc >= N) 
			return false;
		if(board[r][c] - 1 != board[r][nc] || isPlaced[r][nc] > 0)
			return false;
	}

	for(int i = 1; i <= L; i++)
		isPlaced[r][c + i] = true;

	return true;
}


bool checkHorAsc(int r, int c)
{
	for(int i = 1; i <= L; i++)
	{
		int nc = c - i;
		if(nc < 0) 
			return false;
		if(board[r][c] - 1 != board[r][nc] || isPlaced[r][nc] > 0)
			return false;
	}

	for(int i = 1; i <= L; i++)
		isPlaced[r][c - i] = true;
		
	return true;
}

bool checkVerDesc(int r, int c)
{
	for(int i = 1; i <= L; i++)
	{
		int nr = r + i;
		if(r >= N) 
			return false;
		if(board[r][c] - 1 != board[nr][c] || isPlaced[nr][c] > 0)
			return false;
	}

	for(int i = 1; i <= L; i++)
		isPlaced[r + i][c] = true;

	return true;
}

bool checkVerAsc(int r, int c)
{
	for(int i = 1; i <= L; i++)
	{
		int nr = r - i;
		if(r < 0) 
			return false;
		if(board[r][c] - 1 != board[nr][c] || isPlaced[nr][c] > 0)
			return false;
	}

	for(int i = 1; i <= L; i++)
		isPlaced[r - i][c] = true;

	return true;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	
	cin >> N >> L;
	for(int i = 0; i < N; i++) for(int j = 0; j < N; j++)
		cin >> board[i][j];

	int ans = 0;
	for(int i = 0; i < N; i++)
	{
		bool flag = true;
		for(int j = 0; j < N - 1; j++)
		{
			if(board[i][j] > board[i][j + 1])
			{
				if(!checkHorDesc(i, j))
				{
					flag = false;
					break;
				}
			}
			if(board[i][j] < board[i][j + 1])
			{
				if(!checkHorAsc(i, j + 1))
				{
					flag = false;
					break;
				}
			}
		}
		if(flag)
		{
			ans++;
			//cout << "Hor : " << i <<"\n";
		}
			
	}

	fill(&isPlaced[0][0], &isPlaced[99][99] + 1, 0);
	for(int i = 0; i < N; i++)
	{
		bool flag = true;
		for(int j = 0; j < N - 1; j++)
		{
			if(board[j][i] > board[j + 1][i])
			{
				if(!checkVerDesc(j, i))
				{
					flag = false;
					break;
				}
			}
			if(board[j][i] < board[j + 1][i])
			{
				if(!checkVerAsc(j + 1, i))
				{
					flag = false;
					break;
				}
			}
		}
		if(flag)
		{
			ans++;
			//cout << "Ver : " << i <<"\n";
		}
	}

	cout << ans << '\n';
	return 0;
}