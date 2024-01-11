#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

vector<int> stck;

int main() {
	// your code goes here
	int H, W; cin >> H >> W;
	int ans = 0;
	for(int i = 0; i < W; i++)
	{
		int height; cin >> height;
		if(stck.empty())
		{
			stck.push_back(height);
			continue;
		}
		for(int i = stck.size() - 1; i >= 0; i--)
		{
			if(height <= stck[i]) break;
			ans += (min(height, stck[0]) - stck[i]);
			stck[i] = min(height, stck[0]);
		}
		
		if(height >= stck[0])
			stck.clear();
		stck.push_back(height);
	}
	cout << ans;
	return 0;
}