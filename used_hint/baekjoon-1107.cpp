#include <iostream>
#include <algorithm>
using namespace std;

int target;
int tLen;
int cnt;
bool broken[10];

int getNumLen(int num)
{
	if(num == 0) return 1;
	int len = 0;
	int temp = num;
	while(temp > 0)
	{
		len++;
		temp /= 10;
	}
	return len;
}
int getNum(int num, int idx, int len)
{
	for(int i = 0; i < len - idx - 1; i++)
		num /= 10;
	return num % 10;
}

bool canMove(int num)
{
	int len = getNumLen(num);
	for(int i = 0; i < len; i++)
	{
		int pos = getNum(num, i, len);
		if(broken[pos]) return false;
	}
	return true;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	
	cin >> target >> cnt;
	
	int temp = target;
	while(temp > 0)
	{
		tLen++;
		temp /= 10;
	}

	for(int i = 0; i < cnt; i++)
	{
		int b; cin >> b;
		broken[b] = true;
	}

	int ans = abs(target - 100);
	for(int i = 0; i <= 1000000; i++)
	{
		if(canMove(i))
		{
			ans = min(ans, getNumLen(i) + abs(i - target));
		}
	}

	cout << ans;
	return 0;
}