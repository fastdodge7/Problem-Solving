#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

typedef long long ll;

int T;
int inorder[1000];
int preorder[1000];

void solve(int inStart, int inEnd, int preStart, int preEnd)
{
	if(inStart >= inEnd) return;
	if(inStart + 1 == inEnd)
	{
		cout << inorder[inStart] << ' ';
		return;
	}
	int leftCnt = 0;
	for(int i = inStart; i < inEnd; i++)
	{
		
		if(preorder[preStart] == inorder[i])
			break;
		leftCnt++;
	}

	solve(inStart, inStart + leftCnt, preStart + 1, preStart + leftCnt + 1);
	solve(inStart + leftCnt + 1, inEnd, preStart + leftCnt + 1, preEnd);
	cout << preorder[preStart] << ' ';
}


int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> T;
	for(int test_case = 1; test_case <= T; test_case++)
	{
		int N; cin >> N;
		for(int i = 0; i < N; i++)
			cin >> preorder[i];
		
		for(int i = 0; i < N; i++)
			cin >> inorder[i];

		solve(0, N, 0, N);
		cout << '\n';
		
		fill(preorder, preorder + 1000, 0);
		fill(inorder, inorder + 1000, 0);
	}

	return 0;
}