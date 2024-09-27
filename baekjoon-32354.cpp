#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef struct Node{
	Node() {

	}
	Node(int parent, long long topValue, long long sum) : parent(parent), topValue(topValue), sum(sum) {

	}
	int parent;
	long long topValue;
	long long sum;
	vector<Node*> children;
}Node;

long long N;

Node arr[500001];
int topIdx[500001];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	
	long long len = 1;
	long long curLastDeckElemIdx = 0;
	cin >> N;
	for(int i = 1; i <= N; i++)
	{
		string cmd; cin >> cmd;
		if(cmd == "push" || cmd == "restore")
		{
			long long num; cin >> num;
			if(cmd == "push")
			{
				arr[len] = Node(curLastDeckElemIdx, num, arr[curLastDeckElemIdx].sum + num);
				curLastDeckElemIdx = len++;
				topIdx[i] = len - 1;
				continue;
			}
			if(cmd == "restore")
			{
				curLastDeckElemIdx = topIdx[num];
				topIdx[i] = topIdx[num];
				continue;
			}
		}
		else
		{
			if(cmd == "pop")
			{
				curLastDeckElemIdx = topIdx[i] =  arr[curLastDeckElemIdx].parent;
				continue;
			}
			if(cmd == "print")
			{
				topIdx[i] = topIdx[i - 1];
				cout << arr[curLastDeckElemIdx].sum << '\n';
				continue;
			}
		}


	}
	
	return 0;
}
// 1 


// 1 2 3 4 5 r2 6

// 1 2 3 4 5 2 6