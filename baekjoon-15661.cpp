#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <unordered_set>
#include <cassert>

using namespace std;

int N;
int matrix[20][20];

int Check(int bits)
{
	int Apower = 0, Bpower = 0;
	vector<int> Ateam, Bteam;
	int idx = N;
	for(int i = (1 << (N - 1)); i > 0; i >>= 1)
	{
		idx--;
		if((bits & i) != 0)
		{
			for(int teammate : Ateam)
				Apower += (matrix[teammate][idx] + matrix[idx][teammate]);
			Ateam.push_back(idx);
		}
		else
		{
			for(int teammate : Bteam)
				Bpower += (matrix[teammate][idx] + matrix[idx][teammate]);
			Bteam.push_back(idx);
		}
	}
	
	return abs(Apower - Bpower);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	
	cin >> N;
	for(int i = 0; i < N; i++) for(int j = 0; j < N; j++)
		cin >> matrix[i][j];

	int ans = 1e9;
	for(int bits = 0; bits < (1 << N); bits++)
	{
		ans = min(ans, Check(bits));
	}
	cout << ans;
	return 0;
}