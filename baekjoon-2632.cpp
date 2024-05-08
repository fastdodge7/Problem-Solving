#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int S, M, N;
int buff[1001];
vector<int> pizzaA = {0};
vector<int> pizzaB = {0};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> S >> M >> N;
	for(int i = 1; i <= M; i++)
	{
		cin >> buff[i];
		buff[i] += buff[i - 1];
	}

	int total = buff[M];
	for(int size = 1; size < M; size++)
	{
		for(int pos = 1; pos <= M; pos++)
		{

			int left = pos;
			int right = ((pos + size - 1) > M) ? (pos + size - 1) % M : (pos + size - 1);
 

			if(right < left)
			{
				pizzaA.push_back(total - (buff[left - 1] - buff[right]));
			}
			else
				pizzaA.push_back(buff[right] - buff[left - 1]);
		}
	}
	pizzaA.push_back(total);

	for(int i = 1; i <= N; i++)
	{
		cin >> buff[i];
		buff[i] += buff[i - 1];
	}

	total = buff[N];

	for(int size = 1; size < N; size++)
	{
		for(int pos = 1; pos <= N; pos++)
		{
			int left = pos;
			int right =  ((pos + size - 1) > N) ? (pos + size - 1) % N : (pos + size - 1);
 
			if(right < left)
			{
				pizzaB.push_back(total - (buff[left - 1] - buff[right]));
			}
			else
				pizzaB.push_back(buff[right] - buff[left - 1]);
		}
	}
	pizzaB.push_back(total);
	
	sort(pizzaA.begin(), pizzaA.end());
	sort(pizzaB.begin(), pizzaB.end());

	long long ans = 0;
	for(int target : pizzaA)
	{
		auto low = lower_bound(pizzaB.begin(), pizzaB.end(), S - target);
		auto hi = upper_bound(pizzaB.begin(), pizzaB.end(), S - target);
		if(target + *low == S)
		{
			ans += (hi - low);
		}
	}

	cout << ans << '\n';
	return 0;
}
