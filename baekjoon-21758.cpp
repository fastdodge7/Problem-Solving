#include <iostream>
#include <algorithm>

using namespace std;

int N;
int arr[100000];
int prefix[100000];

int getRange(int startExclude, int endInclude){
	return prefix[endInclude] - prefix[startExclude];
}

int getReverseRange(int startInclude, int endExclude){
	return getRange(startInclude, endExclude) - arr[endExclude] + arr[startInclude];
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	
	cin >> N;
	for(int i = 0; i < N; i++)
		cin >> arr[i];
		
	prefix[0] = arr[0];
	for(int i = 1; i < N; i++)
		prefix[i] = prefix[i - 1] + arr[i]; 
		
	int ans = 0;
	for(int i = 1; i < N - 1; i++)
		ans = max(ans, getRange(0, i) + getReverseRange(i, N - 1));
		
	for(int i = 1; i < N - 1; i++)
		ans = max(ans, getRange(0, N - 1) + getRange(i, N - 1) - arr[i]);
	
	for(int i = 1; i < N - 1; i++)
		ans = max(ans, getReverseRange(0, N - 1) + getReverseRange(0, i)- arr[i]);
	
	cout << ans;
	return 0;
}