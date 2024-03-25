#include <iostream>
using namespace std;
int main() {
	long long N; cin >> N;
	N = (N - 2) % 7;
	
	if(N == 0 || N == 5)
		cout << "CY";
	else
		cout << "SK";
	return 0;
}