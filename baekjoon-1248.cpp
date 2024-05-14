#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <cmath>

using namespace std;

constexpr int TERMINATED = -100;

int N;
int matrix[10][10];
int ans[10];

int DFS(int depth, int sum)
{
	if(depth == N)
	{
		for(int i = 0 ; i < N; i++)
			cout << ans[i] << ' ';
		return TERMINATED;
	}

	if(matrix[depth][depth] == '0')
	{
		for(int begin = depth - 1; begin >= 0; begin--)
		{
			if(matrix[begin][depth] != matrix[begin][depth - 1])
				return -1;
		}

		return DFS(depth + 1, sum);
	}
	
	int ret = 0;
	for(int absv = 1; absv <= 10; absv++)
	{
		int sign = matrix[depth][depth] == '+' ? 1 : -1;
		ans[depth] = absv * sign;
		int summation = ans[depth];

		bool flag = true;
		for(int begin = depth - 1; begin >= 0; begin--)
		{
			summation += ans[begin];
			char checker = '0';
			if(summation > 0) checker = '+';
			if(summation < 0) checker = '-';

			if(checker == matrix[begin][depth])
				continue;
			else
			{
				if(absv == 10) return -1;
				if(summation == 0 && absv == 10)
					return -1;

				char checkFlag = '0';
				if(summation + sign * (10 - absv) < 0) checkFlag = '-';
				if(summation + sign * (10 - absv) > 0) checkFlag = '+';
				if(checkFlag == checker) // summation == 0인 경우는?
					return -1;

				flag = false;
				break;
			}
		}
		if(flag)
			ret = DFS(depth + 1, sum + ans[depth]);
		if(ret == TERMINATED)
			return TERMINATED;
	}

	return ret;

}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> N;
	string str; cin >> str;

	int cnt = 0;
	for(int i = 0; i < N; i++)
	{
		for(int j = i; j < N; j++)
			matrix[i][j] = str[cnt++];
	}

	DFS(0, 0);


	return 0;
}
