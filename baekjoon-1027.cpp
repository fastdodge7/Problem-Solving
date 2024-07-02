#include <iostream>
#include <algorithm>

using namespace std;

int N;
int arr[50];
int ans[50];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	
	cin >> N;
	for(int i = 0; i < N; i++)
		cin >> arr[i];

	for(int i = 0; i < N; i++)
	{
		for(int j = i + 1; j < N; j++)
		{
			int dx = j - i, dy = arr[j] - arr[i];
			bool visible = true;
			for(int k = i + 1; k < j; k++)
			{
				int cdx = k - i, cdy = arr[k] - arr[i];
				if((long long)cdy * dx >= (long long)dy * cdx)
				{
					visible = false;
					break;
				}
			}

			if(visible)
			{
				ans[i]++;
				ans[j]++;
			}
		}
	}

	cout<< *max_element(ans, ans + N);
	return 0;
}