#include <iostream>
#include <algorithm>

using namespace std;

int N;
int arr[50];
int cycle[50];

void markCycle(int cnt, int cur)
{
	if(cycle[cur] == cnt)
		return;
	
	cycle[cur] = cnt;
	markCycle(cnt, arr[cur]);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	
	cin >> N;
	for(int i = 0; i < N; i++)
		cin >> arr[i];

	int cnt = 1;
	for(int i = 0; i < N; i++)
	{
		if(cycle[i] == 0)
			markCycle(cnt++, i);
	}

	cout << (cnt <= 2 ? 0 : cnt - 1);
	return 0;
}