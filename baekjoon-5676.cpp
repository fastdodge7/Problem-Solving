#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

constexpr int MAX_N = 101;

int N, K;
int tree[MAX_N * 4];
int arr[MAX_N];

int convert(int value) {
	if (value > 0) return 1;
	else if (value < 0) return -1;
	else return 0;
}

char getAns(int value)
{
	if (value > 0) return '+';
	else if (value < 0) return '-';
	else return '0';	
}

void initia()
{
	fill(tree, tree + MAX_N * 4, 0);
	fill(arr, arr + MAX_N, 0);
}

int makeTree(int idx, int l, int r)
{
	if(l == r){

		return tree[idx] = arr[l];
	}
	int mid = (l + r) / 2;
	return tree[idx] = makeTree(idx * 2, l, mid) * makeTree(idx * 2 + 1, mid + 1, r);
}

int change(int idx, int start, int end, int targetIdx, int val)
{
	if(targetIdx < start || targetIdx > end) return tree[idx];
	if(start == end) return tree[idx] = val;


	int mid = (start + end) / 2;
	return tree[idx] = change(idx * 2, start, mid, targetIdx, val) * change(idx* 2 + 1, mid + 1, end, targetIdx, val);
}

int getProduct(int Node, int start, int end, int left, int right)
{
	if(right < start || left > end) return 1;
	if(left <= start && end <= right) return tree[Node];
	int mid = (start + end) / 2;
	return getProduct(Node * 2, start, mid, left, right) * getProduct(Node * 2 + 1, mid + 1, end, left, right);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	
	while(cin >> N >> K)
	{
		initia();
		for(int i = 1; i <= N; i++)
		{
			cin >> arr[i];
			arr[i] = convert(arr[i]);
		}

		makeTree(1, 1, N);

		for(int i = 0; i < K; i++)
		{
			char cmd; cin >> cmd;
			if(cmd == 'C')
			{
				int index, value; cin >> index >> value;
				change(1, 1, N, index, value);
			}
			else
			{
				int s, e; cin >> s >> e;
				cout << getAns(getProduct(1, 1, N, s, e));
			}
		}
		cout << endl;
	}
	return 0;
}
