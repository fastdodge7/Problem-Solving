#include <iostream>
#include <vector>

using namespace std;

int arr[500000];
vector<int> stck;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	
	int N; cin >> N;
	for(int i = 0; i < N; i++)
		cin >> arr[i];
		
	for(int i = 0; i < N; i++)
	{
		while(!stck.empty() && arr[stck.back() - 1] < arr[i])
			stck.pop_back();
		if (stck.empty())
			cout << 0 << ' ';
		else
			cout << stck.back() << ' ';
		stck.push_back(i + 1);
	}
	return 0;
}