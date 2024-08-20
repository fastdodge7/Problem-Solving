#include <iostream>
#include <algorithm>
using namespace std;

constexpr int TOP = 0;
constexpr int BOTTOM = 5;
constexpr int UP = 4;
constexpr int DOWN = 1;
constexpr int LEFT = 3;
constexpr int RIGHT = 2;

int dice[6] = {1, 2, 3, 4, 5, 6};

void flipRight()
{
	int temp = dice[TOP];
	swap(dice[RIGHT], temp);
	swap(dice[BOTTOM], temp);
	swap(dice[LEFT], temp);
	swap(dice[TOP], temp);
}

void flipLeft()
{
	int temp = dice[TOP];
	swap(dice[LEFT], temp);
	swap(dice[BOTTOM], temp);
	swap(dice[RIGHT], temp);
	swap(dice[TOP], temp);
}

void flipDown()
{
	int temp = dice[TOP];
	swap(dice[DOWN], temp);
	swap(dice[BOTTOM], temp);
	swap(dice[UP], temp);
	swap(dice[TOP], temp);
}

int R, C;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	
	cin >> R >> C;

	int mod4 =(C - 1) % 4;
	int Q4 = (C - 1) / 4;
	int curR = 1;

	long long ans = 0;
	while(curR <= R)
	{
		ans += (14 * Q4);

		ans += dice[TOP];
		if(curR % 2 == 1)
		{
			for(int i = 0; i < mod4; i++)
			{
				flipRight();
				ans += dice[TOP];
			}
		}
		else
		{
			for(int i = 0; i < mod4; i++)
			{
				flipLeft();
				ans += dice[TOP];
			}
		}
		flipDown();
		curR++;
	}

	cout << ans << '\n';
	return 0;
}