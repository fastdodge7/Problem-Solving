#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <queue>

using namespace std;

int N;
int target[48];
int arr[48];
int temp[48];
int shuff[48];
bool visited[48];
int maxTry = 1;
int ans = 0;

int gcd(int a, int b)
{
	if(a > b) swap(a, b);
	while(b > 0)
	{
		int temp = b;
		b = a % b;
		a = temp;
	}
	return a;
}

int findTry(int cur)
{
	if(visited[cur]) return 0;

	visited[cur] = true;

	if(visited[shuff[cur]]) return 1;

	return findTry(shuff[cur]) + 1;
}

bool check()
{
	bool flag = true;
	for(int i = 0; i < N; i++)
	{
		if(target[i] != arr[i]) 
		{
			flag = false;
			break;
		}	
	}
	return flag;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> N;
	for(int i = 0; i < N; i++)
	{
		cin >> target[i];
		arr[i] = i % 3;
	}
		
	for(int i = 0; i < N; i++)
		cin >> shuff[i];

	for(int i = 0; i < N; i++)
	{
		int cycSize = findTry(i);
		if(cycSize > 0)
		{
			maxTry = maxTry * cycSize / gcd(maxTry, cycSize);
		}
	}

	if(check())
	{
		cout << ans;
		return 0;
	}

	for(int t = 0; t < maxTry; t++)
	{
		ans++;
		for(int i = 0; i < N; i++)
			temp[shuff[i]] = arr[i];
		swap(arr, temp);

		

		if(check())
		{
			cout << ans;
			return 0;
		}
	}

	cout << -1;
	return 0;
}