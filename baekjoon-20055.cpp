#include <iostream>
#include <list>

using namespace std;

int timeStamp = 0;
int cnt = 0;

int N, K;
int dur[200];
bool occupied[200];
int inPos = 0;
int outPos = -1;
list<int> robots;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	
	cin >> N >> K; outPos = N - 1;
	for(int i = 0; i < 2*N; i++)
		cin >> dur[i];
	
	int ans = 0;
	while(cnt < K)
	{
		ans++;
		inPos = (inPos - 1 + 2*N) % (2*N);
		outPos = (outPos - 1 + 2*N) % (2*N);
		
		for(auto iter = robots.begin(); iter != robots.end(); iter++) // 회전 후 삭제
		{
			int position = (timeStamp + *iter) % (2 * N);
			if(position == outPos)
			{
				robots.erase(iter);
				occupied[position] = false;
				break;
			}
		}

		for(auto iter = robots.begin(); iter != robots.end(); iter++) 
		{
			int nextPosition = (timeStamp + *iter + 1) % (2 * N);
			if(occupied[nextPosition] || dur[nextPosition] <= 0)
				continue;
			
			occupied[(*iter) % (2*N)] = false;
			occupied[nextPosition] = true;
			dur[nextPosition] -= 1;
			if(dur[nextPosition] == 0) cnt++;
			*iter = *iter + 1;
		}

		for(auto iter = robots.begin(); iter != robots.end(); iter++) // 이동 후 삭제
		{
			int position = (timeStamp + *iter) % (2 * N);
			if(position == outPos)
			{
				robots.erase(iter);
				occupied[position] = false;
				break;
			}
		}

		if(occupied[inPos] == 0 && dur[inPos] > 0)
		{
			occupied[inPos] = true;
			dur[inPos] -= 1;
			if(dur[inPos] == 0) cnt++;
			robots.push_back(inPos);
		}
	}

	cout << ans << '\n';
	return 0;
}