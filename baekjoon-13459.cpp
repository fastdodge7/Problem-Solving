#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

constexpr int dy[4] = {0, -1, 0, 1};
constexpr int dx[4] = {-1, 0, 1, 0};

int N, M;
string board[10];

bool whatIsFirst(pair<int, int> red, pair<int, int> blue, int dir)
{
    if(dir == 0)
        return red.second < blue.second;
    if(dir == 1)
        return red.first < blue.first;
    if(dir == 2)
        return red.second > blue.second;
    return red.first > blue.first;
}

bool canProceed(const pair<int, int>& pos, const int& dir)
{
    int nr = pos.first + dy[dir];
    int nc = pos.second + dx[dir];
    if(nr < 0 || nr >= N || nc < 0 || nc >= M) return false;
    if(!(board[nr][nc] == '.' || board[nr][nc] == 'O')) return false;
    return true;
}

pair<int, int> calcNewPos(const pair<int, int>& cur, const int& dir)
{
    pair<int, int> newPos = {cur.first, cur.second};
    for(int step = 1; ; step++)
    {
        if(board[newPos.first][newPos.second] == 'O') return newPos;
        if(canProceed(newPos, dir))
        {
            newPos.first += dy[dir];
            newPos.second += dx[dir];
            continue;
        }
        break;
    }
    return newPos;
}

int DFS(int depth, const pair<int, int> red, const pair<int, int> blue, int dir)
{
    if(depth > 10)
    {
        board[red.first][red.second] = '.';
        board[blue.first][blue.second] = '.';
        return 1e9;
    }

    pair<int, int> redNewPos, blueNewPos;

    if(whatIsFirst(red, blue, dir)) // 빨강이 우선
    {
        redNewPos = calcNewPos(red, dir);
        board[red.first][red.second] = '.';
        if(board[redNewPos.first][redNewPos.second] == 'O')
        {
            board[blue.first][blue.second] = '.';
            blueNewPos = calcNewPos(blue, dir);
            if(board[blueNewPos.first][blueNewPos.second] == 'O') // 동시 탈출한 경우
                return 1e9;
            return depth;
        }
        else
        {
            board[redNewPos.first][redNewPos.second] = 'R';

            board[blue.first][blue.second] = '.';
            blueNewPos = calcNewPos(blue, dir);
            if(board[blueNewPos.first][blueNewPos.second] == 'O') // 파랑이 탈출한 경우
            {
                board[redNewPos.first][redNewPos.second] = '.';
                return 1e9;
            }
            board[blueNewPos.first][blueNewPos.second] = 'B';
        }
    }
    else
    {
        blueNewPos = calcNewPos(blue, dir);
        board[blue.first][blue.second] = '.';
        if(board[blueNewPos.first][blueNewPos.second] == 'O')
        {
            board[red.first][red.second] = '.';
            return 1e9;
        }
        else
        {
            board[blueNewPos.first][blueNewPos.second] = 'B';

            board[red.first][red.second] = '.';
            redNewPos = calcNewPos(red, dir);
            if(board[redNewPos.first][redNewPos.second] == 'O') // 빨강이 탈출한 경우
            {
                board[blueNewPos.first][blueNewPos.second] = '.';
                return depth;
            }
                
            board[redNewPos.first][redNewPos.second] = 'R';
        }
    }

    int ret = 1e9;
    for(int i = 0; i < 4; i++)
    {
        ret = min(ret, DFS(depth + 1, redNewPos, blueNewPos, i));
        
        board[redNewPos.first][redNewPos.second] = 'R';
        board[blueNewPos.first][blueNewPos.second] = 'B';
    }
    board[redNewPos.first][redNewPos.second] = '.';
    board[blueNewPos.first][blueNewPos.second] = '.';
    return ret;
}

int main(int argc, char* argv[])
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> M;
    for(int i = 0; i < N; i++)
        cin >> board[i];

    pair<int , int> redPos, bluePos;
    for(int i = 0; i < N; i++) for(int j = 0; j < M; j++)
    {
        if(board[i][j] == 'R') redPos = {i, j};
        if(board[i][j] == 'B') bluePos = {i, j};
    }

    int ans = 1e9;

    for(int i = 0; i < 4; i++)
    {
        ans = min(ans, DFS(1, redPos, bluePos, i));
        
        board[redPos.first][redPos.second] = 'R';
        board[bluePos.first][bluePos.second] = 'B';
    }

    cout << (ans == 1e9 ? 0 : 1);
    return 0;
}