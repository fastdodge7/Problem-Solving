#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <queue>
#include <cmath>

using namespace std;

int T, N;

int ans[5];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> T;
	for(int test_case = 1; test_case <= T; test_case++)
	{
		cin >> N;
		

		ans[0] = N / 60;
		N -= (60 * (N / 60));
		if(N % 60 > 35)
		{
			N -= 60;
			ans[0]++;
		}

		if(N < 0)
		{
			N *= -1;
			ans[2] = N / 10;
			N -= (10 * (N / 10));
			if(N % 10 > 5)
			{
				ans[2]++;
				ans[3] = 10 - N;
			}
			else
				ans[4] = N;
		}
		else
		{
			ans[1] = N / 10;
			N -= (10 * (N / 10));
			if(N % 10 > 5)
			{
				ans[1]++;
				ans[4] = 10 - N;
			}
			else
				ans[3] = N;
		}

		for(int i = 0; i < 5; i++)
			cout << ans[i] << ' ';
		cout << '\n';
		fill(ans, ans + 5, 0);
	}
	return 0;
}


// 29 -> +60 -> -10 -> -10 -> -10 -> -1
// 29 -> +10 -> +10 -> +10 -> -1
// 30 -> +60 -> -10 -> -10 -> -10
// 30 -> +10 -> +10 -> +10
// 31 -> +60 -> -10 -> -10 -> -10 -> +1
// 31 -> +10 -> +10 -> +10 -> +1
// 39 -> +60 -> -10 -> -10 -> -1
// 39 -> +10 -> +10 -> +10 -> +10 -> -1
// 35 -> +60 -> -10 -> -10 -> -1 * 5
// 35 -> +10 -> +10 -> +10 -> +1 * 5 // 이쪽이 승리
// 36 -> +60 -> -10 -> -10 -> -1 * 4
// 36 -> +10 -> +10 -> +10 -> +1 * 6
// 34 -> +10 -> +10 -> +10 -> +1 * 4
// 34 -> +60 -> -10 -> -10 -> -10
