#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
#include <deque>
#include <cassert>
#include <tuple>

using namespace std;

int N, M, R;
int board[300][300];

void rotate(int depth, int step)
{
    deque<int> dq;
    int startR = 0 + depth;
    int endR = N - 1 - depth;
    int startC = 0 + depth;
    int endC = M - 1 - depth;

    for(int i = startR; i <= endR; i++)
        dq.push_back(board[i][startC]);
    for(int i = startC + 1; i <= endC; i++)
        dq.push_back(board[endR][i]);
    for(int i = endR - 1; i >= startR; i--)
        dq.push_back(board[i][endC]);
    for(int i = endC - 1; i >= startC + 1; i--)
        dq.push_back(board[startR][i]);

    assert(dq.size() == 2 * (endR - startR) + 2 * (endC - startC));

    step = step % (int)dq.size();

    for(int i = 0; i < step; i++)
    {
        int t = dq.back();
        dq.pop_back();
        dq.push_front(t);
    }

    for(int i = startR; i <= endR; i++)
    {
        board[i][startC] = dq.front(); dq.pop_front();
    }
    for(int i = startC + 1; i <= endC; i++)
    {
        board[endR][i] = dq.front(); dq.pop_front();
    }
    for(int i = endR - 1; i >= startR; i--)
    {
        board[i][endC] = dq.front(); dq.pop_front();
    }
    for(int i = endC - 1; i >= startC + 1; i--)
    {
        board[startR][i] = dq.front(); dq.pop_front();
    }
}

int main(int argc, char* argv[])
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> M >> R;
    for(int i = 0; i < N; i++) for(int j = 0; j < M; j++)
        cin >> board[i][j];
    
    for(int i = 0; i < min(N, M) / 2; i++)
        rotate(i, R);

    for(int i = 0; i < N; i++) 
    {
        for(int j = 0; j < M; j++)
            cout << board[i][j] << ' ';
        cout << '\n';
    }
    return 0;
}