#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <queue>
#include <unordered_set>

using namespace std;

typedef struct Node{
	int a, b, c;
}Node;

int arr[3];
unordered_set<string> visited;
// ㅋㅋ BFS아니면 안됨. 3 7 14

string getStr(int a, int b, int c)
{
	return to_string(a) + " " + to_string(b) + " " + to_string(c);
}

void BFS()
{
	sort(arr, arr + 3);
	queue<Node> Q; Q.push({arr[0], arr[1], arr[2]});
	visited.insert(getStr(arr[0], arr[1], arr[2]));

	while(!Q.empty())
	{
		//cout << Q.size() << '\n';
		int a = Q.front().a;
		int b = Q.front().b;
		int c = Q.front().c; Q.pop();
		if(a == b && b == c)
		{
			cout << 1;
			return;
		}

		
		int temp[3] = {a * 2, b, c - a};
		sort(temp, temp + 3);
		string curStr = getStr(temp[0], temp[1], temp[2]);
		if(temp[2] > 0 && visited.find(curStr) == visited.end())
		{
			visited.insert(curStr);
			Q.push({temp[0], temp[1], temp[2]});
		}

		temp[0] = a * 2; temp[1] = b - a; temp[2] = c;
		sort(temp, temp + 3);
		curStr = getStr(temp[0], temp[1], temp[2]);
		if(b - a > 0 && visited.find(curStr) == visited.end())
		{
			visited.insert(getStr(temp[0], temp[1], temp[2]));
			Q.push({temp[0], temp[1], temp[2]});
		}

		temp[0] = a; temp[1] = b + b; temp[2] = c - b;
		sort(temp, temp + 3);
		curStr = getStr(temp[0], temp[1], temp[2]);
		if(c - b > 0 && visited.find(curStr) == visited.end())
		{
			visited.insert(getStr(temp[0], temp[1], temp[2]));
			Q.push({temp[0], temp[1], temp[2]});
		}
	}

	cout << 0;
	return;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> arr[0] >> arr[1] >> arr[2];
	
	BFS();
	
	return 0;
}

