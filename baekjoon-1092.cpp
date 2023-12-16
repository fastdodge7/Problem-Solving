#include <iostream>
#include <algorithm>

using namespace std;

int cargo[10000];
int crane[50];
int ans[50];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	
	int N; cin >> N;
	for(int i = 0; i < N; i++)
		cin >> crane[i];
		
	int M; cin >> M;
	for(int i = 0; i < M; i++)
		cin >> cargo[i];
		
	sort(crane, crane + N, greater<int>());
	sort(cargo, cargo + M, greater<int>());
	
	if(cargo[0] > crane[0])
	{
		cout << -1;
		return 0;
	}
	
	for(int c = 0; c < M; c++)
	{
		int targetIndex = 0;
		for(int i = 0; i < N; i++)
		{
			if(crane[i] < cargo[c])
				break;
			if(ans[targetIndex] > ans[i])
				targetIndex = i;
		}
		ans[targetIndex]++;
	}
	
	cout << *max_element(ans, ans + N);
	return 0;
}