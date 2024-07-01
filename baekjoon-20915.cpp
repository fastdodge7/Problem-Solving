#include <iostream>
#include <algorithm>

using namespace std;

int T;
string str;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	
	cin >> T;
	for(int test_case = 1; test_case <= T; test_case++)
	{
		cin >> str;
		for(int i = 0; i < str.size(); i++)
		{
			if(str[i] == '6') str[i] = '9';
		}
		sort(str.begin(), str.end(), greater<char>());

		long long ans = 0;
		for(int bits = 0; bits < (1 << str.size()); bits++)
		{
			long long a = 0, b = 0;
			int pos = 0;
			for(int idx = (1 << str.size() - 1); idx > 0; idx >>= 1)
			{
				if((idx & bits) == 0)
				{
					a *= 10;
					a += (str[pos++] - '0');
				}
				else
				{
					b *= 10;
					b += (str[pos++] - '0');
				}
			}
			ans = max(ans, a * b);
		}
		cout << ans << '\n';
	}

	return 0;
}