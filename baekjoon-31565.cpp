#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>

using namespace std;

constexpr int monthToDate[13] = { -1, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

int N, T;
pair<int, int> arr[101];
int dp[101][10001];

typedef struct Date{
	int year, month, day;

	bool isLeapYear() { return (year % 400 == 0) || ((year % 4 == 0) && (year % 100 != 0)); }
	
	int getDateCnt()
	{
		year--;
		int res = 0;
		res += ((year * 365) - (year / 100) + (year / 4) + (year / 400));

		year++;
		for(int i = 1; i < month; i++)
		{
			res += monthToDate[i];
			if(i == 2 && isLeapYear())
				res++;
		}

		res += day;
		return res;
	}
}Date;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	
	int y1, m1, d1; cin >> y1 >> m1 >> d1;
	int y2, m2, d2; cin >> y2 >> m2 >> d2;
	Date target = {y2, m2, d2};
	Date start = {y1, m1, d1};

	int diff = target.getDateCnt() - start.getDateCnt();

	cin >> T >> N;

	for(int i = 1; i <= N; i++)
	{
		int a, b, c; cin >> a >> b >> c;
		if(a == 3) 
			c *= 30;

		arr[i].first = b;
		arr[i].second = c;
	}

	for(int i = 1; i <= N; i++)
	{
		for(int j = 1; j <= T; j++)
		{
			if(j >= arr[i].first)
				dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - arr[i].first] + arr[i].second);
			else
				dp[i][j] = dp[i - 1][j];
		}
	}	

	cout << abs(diff - dp[N][T]) << '\n';
	return 0;
}