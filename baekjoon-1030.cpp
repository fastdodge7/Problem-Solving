#include <iostream>
#include <cmath>

using namespace std;

// 가운데 K * K 점에 속하는지 

long long powerOf[9][11];
int ans[50][50];

long long s, N, K, Ra, Rb, Ca, Cb;
bool isBlack(int sec, long long r, long long c)
{
	if(sec == 0)
		return false;

	long long blackBlockSize = powerOf[N][sec - 1] * K;
	long long dividedBlockSize = powerOf[N][sec - 1];

	int padding = (powerOf[N][sec] - powerOf[N][sec - 1] * K) / 2;
	if(padding <= r && r < padding + blackBlockSize && padding <= c && c < padding + blackBlockSize)
		return true;

	int blockRow = r / dividedBlockSize;
	int blockCol = c / dividedBlockSize;
	
	return isBlack(sec - 1, r - dividedBlockSize * blockRow, c - dividedBlockSize * blockCol);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> s >> N >> K >> Ra >> Rb >> Ca >> Cb;

	for(int i = 1; i <= 8; i++)
	{
		powerOf[i][0] = 1;
		powerOf[i][1] = i;
		for(int j = 2; j <= 10; j++)
			powerOf[i][j] = powerOf[i][j - 1] * i;
	}

	for(int i = 0; Ra + i <= Rb; i++)
	{
		for(int j = 0; Ca + j <= Cb; j++)
			cout << (isBlack(s, Ra + i, Ca + j) ? 1 : 0);
		cout << '\n';
	}

	return 0;
}