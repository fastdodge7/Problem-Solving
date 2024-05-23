#include <algorithm>
#include <string>
#include <iostream>

using namespace std;

string str;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> str;

	string minStr;
	string maxStr;

	int mCnt = 0;
	for(int i = 0; i < str.size(); i++)
	{
		if(str[i] == 'K')
		{
			maxStr.push_back('5');
			for(int j  = 0; j < mCnt; j++)
			{
				maxStr.push_back('0');
			}

			for(int j = 0; j < mCnt; j++)
			{
				if(j == 0)
				{
					minStr.push_back('1');
					continue;
				}
				minStr.push_back('0');
			}
			minStr.push_back('5');
			mCnt = 0;
			continue;
		}
		mCnt++;
	}
	
	string temp = "1";
	for(int i = 0; i < mCnt; i++)
	{
		maxStr.push_back('1');
		temp.push_back('0');
	}
	temp.pop_back();
	minStr += temp;

	cout << maxStr << '\n' << minStr;
	return 0;
}