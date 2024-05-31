#include <algorithm>
#include <iostream>
#include <vector>
#include <queue>
#include <string>

using namespace std;

int N;
string arr[1000];

bool compare(const string& a, const string& b)
{
	string testerA = a + b;
	string testerB = b + a;

	return testerA >= testerB;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	cin >> N;
	bool allZero = true;
	for(int i = 0; i < N; i++)
	{
		int temp; cin >> temp;
		if(temp > 0) allZero = false;
		arr[i] = to_string(temp);
	}

	if(allZero)
	{
		cout << 0;
		return 0;
	}

	sort(arr, arr + N, compare);

	for(int i = 0; i < N; i++)
		cout << arr[i];

	return 0;
}
