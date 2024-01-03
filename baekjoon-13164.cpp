#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

vector<int> diff;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	
	int N, K; cin >> N >> K;
	int base; cin >> base;
	for(int i = 1; i < N; i++)
	{
		int temp; cin >> temp;
		diff.push_back(temp - base);
		base = temp;
	}
	
	sort(diff.begin(), diff.end());
	
	for(int i = 1; i < K; i++)
		diff.pop_back();
	
	cout << accumulate(diff.begin(), diff.end(), 0) << '\n';
	return 0;
}