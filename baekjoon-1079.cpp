#include <iostream>

using namespace std;

int N;
int susp[16];
int matrix[16][16];
int mafia;
bool isDead[16];

constexpr int DAY = 1;
constexpr int NIGHT = -1;

int ans = 0;
int DFS(int depth, int nightCnt, int dayOrNight)
{
	if (depth == N)
		return nightCnt;
	if (dayOrNight == DAY)
	{
		int target = -1;
		for (int i = 0; i < N; i++)
		{
			if (isDead[i]) continue;
			if (target == -1)
			{
				target = i;
				continue;
			}
			if (susp[target] < susp[i])
				target = i;
		}
		if (target == mafia)
			return nightCnt;

		isDead[target] = true;
		int ret = DFS(depth + 1, nightCnt, dayOrNight * (-1));
		isDead[target] = false;
		return ret;
	}

	int ret = 0;
	for (int i = 0; i < N; i++)
	{
		if (i == mafia) continue;
		if (isDead[i]) continue;

		isDead[i] = true;
		for (int j = 0; j < N; j++)
			susp[j] += matrix[i][j];
		ret = max(ret, DFS(depth + 1, nightCnt + 1, dayOrNight * (-1)));
		for (int j = 0; j < N; j++)
			susp[j] -= matrix[i][j];
		isDead[i] = false;
	}
	return ret;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> N;
	for (int i = 0; i < N; i++)
		cin >> susp[i];
	for (int i = 0; i < N; i++) for (int j = 0; j < N; j++)
		cin >> matrix[i][j];
	cin >> mafia;

	if (N % 2 == 1) // 낮부터 시작
		cout << DFS(1, 0, DAY);
	else
		cout << DFS(1, 0, NIGHT);

	return 0;
}