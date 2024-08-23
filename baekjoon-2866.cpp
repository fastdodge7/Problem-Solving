#include <algorithm>
#include <string>
#include <iostream>
#include <unordered_set>

using namespace std;

int R, C;
string arr[1000];
unsigned int hashval[1000][1000];

void fillHash()
{
	for(int col = 0; col < C; col++)
	{
		unsigned int hash = 5381;
		for(int row = R - 1; row >= 0; row--)
		{
			hashval[row][col] = hash = ((hash << 5) + hash) + arr[row][col];
		}
	}
}

int solve()
{
	fillHash();
	int ans = 0;
	for(int row = 1; row < R; row++)
	{
		unordered_set<unsigned int> hashTable;
		for(int col = 0; col < C; col++)
		{
			if(hashTable.find(hashval[row][col]) != hashTable.end())
				return ans;
				
			else
				hashTable.insert(hashval[row][col]);
		}
		ans++;
	}
	return ans;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> R >> C;
	for(int i = 0; i < R; i++)
		cin >> arr[i];

	cout << solve();
	return 0;
}