#include <iostream>
#include <cmath>
using namespace std;

int N;
int cnt;
int arr[20];
int da, db;

int DFS(int doorA, int doorB, int level)
{
	if(level == cnt) return 0;
	
	int ret = 1e9;
	
	ret = min(ret, DFS(arr[level], doorB, level + 1) + abs(doorA - arr[level]));
	ret = min(ret, DFS(doorA, arr[level], level + 1) + abs(doorB - arr[level]));
	return ret;
}

int main() {
	// your code goes here
	
	cin >> N;
	cin >> da >> db;
	cin >> cnt;
	
	for(int i = 0; i < cnt; i++)
		cin >> arr[i];
		
	cout << DFS(da, db, 0);
	return 0;
}