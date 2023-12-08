#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int main() {
	string S, T;
	cin >> S >> T;
	
	while(T.size() > S.size())
	{
		if(T.back() == 'B')
			reverse(T.begin(), T.end() - 1);
		T.pop_back();
	}
	cout << (T == S);
	return 0;
}