#include <iostream>
#include <deque>
#include <string>
using namespace std;

int N;

int main() {
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		string str; cin >> str;
		deque<char> Q;
		for (int j = 0; j < str.size(); j++)
		{
			Q.push_back(str[j]);
		}
		while (1)
		{
			if (Q.size() == 1)
			{
				cout << "NO\n";
				break;;
			}
			if (Q.empty())
			{
				cout << "YES\n";
				break;
			}

			char a = Q.front(); Q.pop_front();
			char b = Q.front(); Q.pop_front();

			if (a == b)
			{
				cout << "NO\n";
				break;
			}
			if (a == '0') continue;
			if (Q.empty())
			{
				cout << "NO\n";
				break;
			}
			if (Q.front() == '1')
			{
				cout << "NO\n";
				break;
			}
			while (!Q.empty() && Q.front() == '0')
				Q.pop_front();
			if (Q.empty())
			{
				cout << "NO\n";
				break;
			}
			Q.pop_front(); // 1 하나 무조건 뽑고
			while (!Q.empty() && Q.front() == '1')
			{
				char x = Q.front(); Q.pop_front();
				if (Q.empty()) break;
				char y = Q.front(); Q.pop_front();
				if (y == '0')
				{
					if (Q.empty()) break;
					char z = Q.front(); Q.pop_front();
					if (z == '0')
					{
						Q.push_front(z);
						Q.push_front(y);
						Q.push_front(x);
						break;
					}
					else
					{
						Q.push_front(z);
						Q.push_front(y);
						break;
					}
				}
				else
					Q.push_front(y);
			}
		}

	}

	return 0;
}