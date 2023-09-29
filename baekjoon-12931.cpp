#include <iostream>

using namespace std;

int N;
int arr[50];
int ans = 0;

bool canDivide()
{
	for (int i = 0; i < N; i++)
	{
		if (arr[i] % 2 == 1)
			return false;
	}
	return true;
}

bool equalToZero()
{
	for (int i = 0; i < N; i++)
	{
		if (arr[i] > 0)
			return false;
	}
	return true;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> N;
	for (int i = 0; i < N; i++)
		cin >> arr[i];

	while (!equalToZero())
	{
		if (canDivide())
		{
			for (int i = 0; i < N; i++)
				arr[i] /= 2;
			ans++;
		}
		else
		{
			for (int i = 0; i < N; i++)
			{
				if (arr[i] % 2 == 1)
				{
					arr[i]--;
					ans++;
				}
			}
		}
	}

	cout << ans << '\n';
	return 0;
}