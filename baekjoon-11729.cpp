#include <iostream>

using namespace std;

int getCnt(int n)
{
	if(n == 1) return 1;
	return 2 * getCnt(n - 1) + 1;
}

void solve(int n, int from, int to, int empt)
{
	if(n == 0)
		return;

	solve(n - 1, from, empt, to);
	cout << from << " " << to << '\n';
	solve(n - 1, empt, to, from);
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int N; cin >> N;
	
	cout << getCnt(N) << '\n';
	solve(N, 1, 3, 2);

	return 0;
}