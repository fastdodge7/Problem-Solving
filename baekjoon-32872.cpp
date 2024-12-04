#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

constexpr int MAX_N = 32;

int H;
int tree[MAX_N];
vector<int> prefix;
int ans = 0;

bool checkPal(const vector<int>& arr)
{
	prefix.push_back(0);
	for(int i = 0; i < arr.size(); i++)
		prefix.push_back(prefix.back() + arr[i]);

	for(int leftPole = 1; leftPole < arr.size(); leftPole++)
	{
		for(int rightPole = leftPole; rightPole < arr.size(); rightPole++)
		{
			int left = prefix[leftPole] - prefix[0];
			int mid = prefix[rightPole] - prefix[leftPole];
			int right = prefix[arr.size()] - prefix[rightPole];
			//cout << "(" << left << ", " << mid << ", " << right << ")\n";
			if(left == right) 
			{
				//cout << "--------------------------------\n";
				prefix.clear();
				return true;
			}
		}
	}
	//cout << "--------------------------------\n";
	prefix.clear();
	return false;
}

void solve()
{	
	for(int l = (1 << (H - 1)); l < (1 << H); l++)
	{
		for(int r = l + 1; r < (1 << H); r++)
		{
			int tl = l, tr = r;
			int right = 0;
			vector<int> lvec = {}, rvec = {};
			while(tl != tr)
			{
				lvec.push_back(tree[tl]);
				rvec.push_back(tree[tr]);
				right += (lvec.back() + rvec.back());
				tl /= 2;
				tr /= 2;
			}
			lvec.push_back(tree[tl]);
			right += tree[tl];
			while(!rvec.empty())
			{
				lvec.push_back(rvec.back());
				rvec.pop_back();
			}

			if(checkPal(lvec)) ans++;		
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	
	cin >> H;

	for(int i = 1; i < (1 << H); i++)
		cin >> tree[i];

	solve();

	cout << ans << '\n';
	return 0;
}