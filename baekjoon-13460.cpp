#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <unordered_set>
#include <cassert>

using namespace std;

constexpr int dy[4] = {0, -1, 0, 1};
constexpr int dx[4] = {-1, 0, 1, 0};

enum STATE{
	TBD, SUCCESS, FAILED
};

int N, M;

typedef struct Node{
	int redIdx;
	int blueIdx;
	string board;
	STATE state = TBD;

	Node() {}
	Node(int rdx, int bdx, string board, STATE state) : redIdx(rdx), blueIdx(bdx), board(board), state(state) {}
	Node(const Node& other) : redIdx(other.redIdx), blueIdx(other.blueIdx), board(other.board), state(other.state) {}

	void printBoard()
	{
		cout << "\n=======================================\n";
		for(int i = 0; i < board.size(); i++)
		{
			if(i % M == 0) cout << '\n';
			cout << board[i];
		}
		cout << '\n' << "redIdx : " << redIdx << " / blueIdx : " << blueIdx << '\n';
	}
}Node;

unordered_set<string> visited;

int coordToIdx(int r, int c)
{
	return M * r + c;
}

pair<int, int> idxToCoord(int idx)
{
	return {idx / M, idx % M};
}

Node move(int direction, const Node& curinput)
{
	Node cur = Node(curinput);
	auto red = idxToCoord(cur.redIdx);
	auto blue = idxToCoord(cur.blueIdx);

	bool repeat = false;
	while(red.first >= 0)
	{
		auto [r, c] = red;
		int nr = r + dy[direction];
		int nc = c + dx[direction];

		if(nr < 0 || nr >= N || nc < 0 || nc >= M) break;
		if(cur.board[coordToIdx(nr, nc)] == '#') break;
		if(cur.board[coordToIdx(nr, nc)] == 'B')
		{
			repeat = true;
			break;
		}
		if(cur.board[coordToIdx(nr, nc)] == 'O') 
		{
			cur.state = SUCCESS;
			red = {-1, -1};
			break;
		}

		red = {nr, nc};
	}

	while(blue.first >= 0)
	{
		auto [r, c] = blue;
		int nr = r + dy[direction];
		int nc = c + dx[direction];

		if(nr < 0 || nr >= N || nc < 0 || nc >= M) break;
		if(cur.board[coordToIdx(nr, nc)] == '#') break;
		if(cur.board[coordToIdx(nr, nc)] == 'R')
		{
			repeat = true;
			break;
		}
		if(cur.board[coordToIdx(nr, nc)] == 'O')
		{
			cur.state = FAILED;
			return cur;
		}

		blue = {nr, nc};
	}

	cur.board[cur.redIdx] = '.';
	cur.board[cur.blueIdx] = '.';

	if(red.first != -1)
	{
		cur.board[coordToIdx(red.first, red.second)] = 'R';
		cur.redIdx = coordToIdx(red.first, red.second);
	}
	cur.board[coordToIdx(blue.first, blue.second)] = 'B';
	cur.blueIdx = coordToIdx(blue.first, blue.second);

	if(repeat)
	{
		pair<int, int> rNext = {red.first + dy[direction], red.second + dx[direction]};
		pair<int, int> bNext = {blue.first + dy[direction], blue.second + dx[direction]};
		if(blue == rNext || red == bNext)
			return cur;
		
		else
			return move(direction, cur);
	}
	return cur;
}

int BFS(const Node& initNode)
{
	queue<pair<int, Node>> Q;
	visited.insert(initNode.board);
	Q.push({0, Node(initNode)});

	while(!Q.empty())
	{
		auto [cnt, node] = Q.front(); Q.pop();

		for(int d = 0; d < 4; d++)
		{
			Node nextNode = move(d, node);
			if(cnt == 10) break;
			if(nextNode.state == FAILED) continue;
			if(nextNode.state == SUCCESS) return cnt + 1;
			if(visited.find(nextNode.board) != visited.end()) continue;

			Q.push({cnt+ 1, nextNode});
			visited.insert(nextNode.board);
		}
	}
	return -1;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	
	cin >> N >> M;

	string initBoard = "";
	for(int i = 0; i < N; i++)
	{
		string str; cin >> str;
		initBoard += str;
	}

	int ridx = -1, bidx = -1;
	for(int i = 0; i < initBoard.size(); i++)
	{
		if(initBoard[i] == 'R')
			ridx = i;
		if(initBoard[i] == 'B')
			bidx = i;
	}

	Node init = {ridx, bidx, initBoard, TBD};

	cout << BFS(init);
	return 0;
}