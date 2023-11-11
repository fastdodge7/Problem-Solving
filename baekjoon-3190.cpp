#include <iostream>
#include <vector>
#include <unordered_map>
#include <deque>
#include <algorithm>

using namespace std;

int dy[4] = { 0, -1, 0, 1 };
int dx[4] = { -1, 0, 1, 0 };

constexpr char APPLE = 'A';
constexpr char BODY = 'B';

int N, K;
char board[100][100];

typedef struct Node {
	int r, c;
}Node;

deque<Node> snake;
int snakeDir = 2;
int ans = 0;

bool proceed()
{
	Node newNode = {snake.front().r + dy[snakeDir], snake.front().c + dx[snakeDir]};
	ans++;

	if (newNode.r < 0 || newNode.r >= N || newNode.c < 0 || newNode.c >= N) 
		return false;
	if (board[newNode.r][newNode.c] == BODY)
		return false;

	snake.push_front(newNode);
	if (board[newNode.r][newNode.c] != APPLE)
	{
		board[snake.back().r][snake.back().c] = 0;
		snake.pop_back();
	}
	board[snake.front().r][snake.front().c] = BODY;
	return true;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> N >> K;
	for (int i = 0; i < K; i++)
	{
		int a, b; cin >> a >> b;
		board[a - 1][b - 1] = APPLE;
	}
	board[0][0] = BODY;
	snake.push_back({ 0,0 });

	int L; cin >> L;
	for (int i = 0; i < L; i++)
	{
		int x; cin >> x;
		char dir; cin >> dir;
		while (ans < x)
		{
			if (!proceed())
			{
				cout << ans;
				return 0;
			}
		}
		if (dir == 'L')
			snakeDir = (snakeDir - 1 + 4) % 4;
		if (dir == 'D')
			snakeDir = (snakeDir + 1) % 4;
	}
	while (proceed())
	{
	}
	cout << ans;
	return 0;
}