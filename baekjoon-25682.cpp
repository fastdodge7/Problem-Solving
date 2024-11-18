#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

constexpr int MAX_N = 2001;

int N, M, K;
string board[MAX_N];
int blackMap[MAX_N][MAX_N];
int whiteMap[MAX_N][MAX_N];

void printMaps()
{
	cout << "-----------------------------------\n";
	for(int i = 0; i <= N; i++)
	{
		for(int j = 0; j <= M; j++)
		{
			cout << blackMap[i][j] << ' ';		
		}
		cout << '\n';
	}
	cout << "-------------colorChange------------\n";
	for(int i = 0; i <= N; i++)
	{
		for(int j = 0; j <= M; j++)
		{
			cout << whiteMap[i][j] << ' ';		
		}
		cout << '\n';
	}
	cout << "-----------------------------------\n";
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	
	cin >> N >> M >> K;
	for(int i = 0; i < N; i++)
		cin >> board[i];

	for(int i = 0; i < N; i++) for(int j = 0; j < M; j++)
	{
		if(((i + j) % 2 == 0 && board[i][j] == 'W') 
		||	((i + j) % 2 == 1 && board[i][j] == 'B'))
		{
			blackMap[i + 1][j + 1] = 1;
		}
		if(((i + j) % 2 == 0 && board[i][j] == 'B')
		|| ((i + j) % 2 == 1 && board[i][j] == 'W'))
		{
			whiteMap[i + 1][j + 1] = 1;
		}
	}

	for(int i = 1; i <= N; i++) for(int j = 1; j <= M; j++)
	{
		whiteMap[i][j] += (whiteMap[i][j - 1] + whiteMap[i - 1][j] - whiteMap[i - 1][j - 1]);
		blackMap[i][j] += (blackMap[i][j - 1] + blackMap[i - 1][j] - blackMap[i - 1][j - 1]);
	}

	int ans = 1e9;
	for(int i = K; i <= N; i++)
	{
		for(int j = K; j <= M; j++)
		{
			ans = min(ans, min(whiteMap[i][j] - whiteMap[i - K][j] - whiteMap[i][j - K] + whiteMap[i - K][j - K]
			, blackMap[i][j] - blackMap[i - K][j] - blackMap[i][j - K] + blackMap[i - K][j - K]));
		}
	}

	cout << ans;
	return 0;
}
