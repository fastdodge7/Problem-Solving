#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <string>

using namespace std;

constexpr int dy[4] = {0, -1, 0, 1};
constexpr int dx[4] = {-1, 0, 1, 0};

int N, M;
string board[50];
bool visited[50][50][1 << 6];

typedef struct Node{
    int cnt;
    int r, c;
    int bits;
}Node;

bool hasKey(int bits, char door)
{
    int target = door - 'A';
    return (bits & (1 << target)) > 0;
}

int addKey(int bits, char key)
{
    return (bits | (1 << (key - 'a')));
}

int BFS(int r, int c)
{
    queue<Node> Q; Q.push({0, r, c, 0});
    visited[r][c][0] = true;
    while(!Q.empty())
    {
        Node cur = Q.front(); Q.pop();
        
        for(int i = 0; i < 4; i++)
        {
            int nr = cur.r + dy[i];
            int nc = cur.c + dx[i];
            int newBits = cur.bits;

            if(nr < 0 || nr >= N || nc < 0 || nc >= M) continue;
            if(board[nr][nc] == '#') continue; // 벽은 이동 불가
            if(board[nr][nc] == '1') return cur.cnt + 1; // 1은 도착
            if('A' <= board[nr][nc] && board[nr][nc] <= 'F') // 잠긴 문
            {
                if(!hasKey(cur.bits, board[nr][nc]))
                    continue;
            }
            if('a' <= board[nr][nc] && board[nr][nc] <= 'f') // 열쇠
                newBits = addKey(newBits, board[nr][nc]);  
                 
            if(visited[nr][nc][newBits]) continue;

            Q.push({cur.cnt + 1, nr, nc, newBits});
            visited[nr][nc][newBits] = true;
        }
    }

    return -1;
}

int main(int argc, char* argv[])
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int r, c;
    cin >> N >> M;
    for(int i = 0; i < N; i++)
    {
        cin >> board[i];
        for(int j = 0; j < M; j++)
        {
            if(board[i][j] == '0')
            {
                r = i;
                c = j;
            }
        }
    }

    cout << BFS(r, c);
    return 0;
}