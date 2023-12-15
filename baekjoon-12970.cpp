#include <iostream>
#include <algorithm>

using namespace std;

int N, K; 
char arr[50];
int main() {
	cin >> N >> K;
	if((N / 2) * (N - (N / 2)) < K)
	{
		cout << -1;
		return 0;
	}
	fill(arr, arr + N, 'A');
	int leng = N;
	
	int cnt = 0;
	while(K > 0)
	{
		if(N - 1 >= K)
			break;
		arr[N - 1] = 'B';
		cnt++;
		
		
		N--;
		K -= N;
		K += cnt;
		
	}
	arr[K] = 'B';
	
	for(int i = 0; i < leng; i++)
		cout << arr[i];
	
	return 0;
}