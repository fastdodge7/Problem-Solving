#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, I, M;
pair<int, int> arr[100];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> N >> I >> M;

	for(int i = 0; i < M; i++)
		cin >> arr[i].first >> arr[i].second;

	int ans = 0;
	for(int st = 0; st < M; st++)
	{
		int hor = 1;
		int ver = (I / 2) - 1;
		for(;ver > 0; hor++, ver--)
		{
			int horStart = arr[st].second;
			int horEnd = arr[st].second + hor;
			int verStart = arr[st].first;
			int verEnd = arr[st].first + ver;
			
			if(verEnd > N)
			{
				verStart -= (verEnd - N);
				verEnd -= (verEnd - N);
				if(verStart < 1) continue;
			}

			if(horEnd > N)
			{
				horStart -= (horEnd - N);
				horEnd -= (horEnd - N);
				if(horStart < 1) continue;
			}

			for(int offset = 0; horStart > 0 && horEnd >= arr[st].second; offset++)
			{
				int cnt = 0;
				for(int target = 0; target < M; target++)
				{
					if(verStart <= arr[target].first && arr[target].first <= verEnd
					&& horStart <= arr[target].second && arr[target].second <= horEnd)
						cnt++;
				}
				ans = max(ans, cnt);
				horStart--;
				horEnd--;
			}
		}
	}

	cout << ans << '\n';
	return 0;
}