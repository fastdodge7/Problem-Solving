#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <queue>

using namespace std;

int N, T;

typedef struct Carrot{
	int w, p;
	bool operator<(const Carrot& other) const {
		return p < other.p;
	}
}Carrot;

Carrot arr[200000];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	long long ans = 0;

	cin >> N >> T;
	for(int i = 0; i < N; i++)
		cin >> arr[i].w >> arr[i].p;
	
	sort(arr, arr + N);

	long long pad = T - N;
	for(int i = 0; i < N; i++)
	{
		ans += ((long long)arr[i].w + (long long)arr[i].p * (pad++));
	}

	cout << ans;
	return 0;
}