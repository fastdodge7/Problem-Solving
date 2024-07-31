#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
#include <string>
#include <cassert>
#include <cmath>

using namespace std;

constexpr int dy[4] = {0, -1, 0, 1};
constexpr int dx[4] = {-1, 0, 1, 0};

typedef struct Node{
    int r;
    int c;
    int lastDirection;
    int bits;
    int dist;
}Node;

int N, M;
string board[50];
bool visited[50][50][4][4];

int posR, posC;

int BFS()
{
    queue<Node> Q; Q.push({posR, posC, -1, 0, 0});

    while(!Q.empty())
    {
        auto [curR, curC, curDir, curBits, curDist] = Q.front(); Q.pop();

        for(int nextDir = 0; nextDir < 4; nextDir++)
        {
            if(curDir == nextDir) continue;

            int nr = curR + dy[nextDir];
            int nc = curC + dx[nextDir];
            if(nr < 0 || nr >= N || nc < 0 || nc >= M) continue;
            if(board[nr][nc] == '#') continue;

            int nextBits = curBits;
            if(board[nr][nc] == '0' || board[nr][nc] == '1')
            {
                nextBits = (nextBits | (1 << (((int)board[nr][nc]) - ((int)'0'))));
            }

            if(nextBits == 3)
            {
                return curDist + 1;
            }

            if(visited[nr][nc][nextDir][nextBits]) continue;

            Q.push({nr, nc, nextDir, nextBits, curDist + 1});
            visited[nr][nc][nextDir][nextBits] = true;
        }
    }

    return -1;
}

int main(int argc, char* argv[])
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> M;
    for(int i = 0; i < N; i++)
        cin >> board[i];


    int destinationCnt = 0;
    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < M; j++)
        {
            if(board[i][j] == 'S')
            {
                posR = i;
                posC = j;
            }
            if(board[i][j] == 'C')
                board[i][j] = ('0' + destinationCnt++);
        }
    }

    cout << BFS() << '\n';

    return 0;
}