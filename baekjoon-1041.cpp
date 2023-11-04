#include <iostream>
#include <algorithm>

using namespace std;

long long triple[8][6] = {
	{1, 1, 1, 0, 0, 0},
	{1, 0, 1, 0, 1, 0},
	{1, 0, 0, 1, 1, 0},
	{1, 1, 0, 1, 0, 0},
	{0, 1, 1, 0, 0, 1},
	{0, 0, 1, 0, 1, 1},
	{0, 0, 0, 1, 1, 1},
	{0, 1, 0, 1, 0, 1}
};

long long dble[12][6] = {
	{1, 1, 0, 0, 0, 0},
	{1, 0, 1, 0, 0, 0},
	{1, 0, 0, 1, 0, 0},
	{1, 0, 0, 0, 1, 0},
	{0, 1, 0, 0, 0, 1},
	{0, 0, 1, 0, 0, 1},
	{0, 0, 0, 1, 0, 1},
	{0, 0, 0, 0, 1, 1},
	{0, 1, 1, 0, 0, 0},
	{0, 0, 1, 0, 1, 0},
	{0, 0, 0, 1, 1, 0},
	{0, 1, 0, 1, 0, 0}
};

long long N;
long long dice[6];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> N;
	for (int i = 0; i < 6; i++)
		cin >> dice[i];

	long long one = *min_element(dice, dice + 6);

	long long twice = 1e9;
	for (int i = 0; i < 12; i++)
	{
		long long temp = 0;
		for (int j = 0; j < 6; j++)
		{
			temp += dble[i][j] * dice[j];
		}
		twice = min(temp, twice);
	}

	long long triples = 1e9;
	for (int i = 0; i < 8; i++)
	{
		long long temp = 0;
		for (int j = 0; j < 6; j++)
		{
			temp += triple[i][j] * dice[j];
		}
		triples = min(temp, triples);
	}

	if (N == 1)
	{
		int sum = 0;
		for (int i = 0; i < 6; i++)
			sum += dice[i];
		cout << sum - *max_element(dice, dice + 6);
	}
	else
		cout << triples * 4 + twice * ((N - 2) * 4 + (N - 1) * 4) + one * ((N - 2) * (N - 2) * 5 + (N - 2) * 4);

	return 0;
}