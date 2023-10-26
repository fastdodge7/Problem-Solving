#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef struct Sticker {
    int r, c;
    bool sticker[10][10];
}Sticker;

int N, M, K;
bool board[40][40];

bool check0Degree(int r, int c, const Sticker& target)
{
    if (r + target.r > N || c + target.c > M) 
        return false;

    for (int i = 0; i < target.r; i++)
    {
        for (int j = 0; j < target.c; j++)
        {
            if (board[r + i][c + j] && target.sticker[i][j])
                return false;
        }
    }
    for (int i = 0; i < target.r; i++) for (int j = 0; j < target.c; j++)
        board[r + i][c + j] = board[r + i][c + j] || target.sticker[i][j];
    return true;
}

bool check90Degree(int r, int c, const Sticker& target)
{
    if (r + target.c > N || c + target.r > M)
        return false;

    for (int i = 0; i < target.c; i++)
    {
        for (int j = 0; j < target.r; j++)
        {
            if (board[r + i][c + j] && target.sticker[target.r - j - 1][i])
                return false;
        }
    }
    for (int i = 0; i < target.c; i++) for (int j = 0; j < target.r; j++)
        board[r + i][c + j] = board[r + i][c + j] || target.sticker[target.r - j - 1][i];
    return true;
}

bool check180Degree(int r, int c, const Sticker& target)
{
    if (r + target.r > N || c + target.c > M)
        return false;

    for (int i = 0; i < target.r; i++)
    {
        for (int j = 0; j < target.c; j++)
        {
            if (board[r + i][c + j] && target.sticker[target.r - i - 1][target.c - j - 1])
                return false;
        }
    }
    for (int i = 0; i < target.r; i++) for (int j = 0; j < target.c; j++)
        board[r + i][c + j] = board[r + i][c + j] || target.sticker[target.r - i - 1][target.c - j - 1];
    return true;
}

bool check270Degree(int r, int c, const Sticker& target)
{
    if (r + target.c > N || c + target.r > M)
        return false;

    for (int i = 0; i < target.c; i++)
    {
        for (int j = 0; j < target.r; j++)
        {
            if (board[r + i][c + j] && target.sticker[j][target.c - i - 1])
                return false;
        }
    }
    for (int i = 0; i < target.c; i++) for (int j = 0; j < target.r; j++)
        board[r + i][c + j] = board[r + i][c + j] || target.sticker[j][target.c - i - 1];
    return true;
}

void attach(const Sticker& target)
{
    for (int rot = 0; rot < 4; rot++)
    {
        for (int row = 0; row < N; row++)
        {
            for (int col = 0; col < M; col++)
            {
                bool flag = false;
                if (rot == 0)
                    flag = check0Degree(row, col, target);
                else if (rot == 1)
                    flag = check90Degree(row, col, target);
                else if (rot == 2)
                    flag = check180Degree(row, col, target);
                else
                    flag = check270Degree(row, col, target);

                if (flag) return;
            }
        }
    }
}

int main(int argc, char* argv[])
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> M >> K;

    for (int i = 0; i < K; i++)
    {
        Sticker cur;
        fill(&cur.sticker[0][0], &cur.sticker[9][9] + 1, false);
        cin >> cur.r >> cur.c;
        for (int j = 0; j < cur.r; j++) for (int k = 0; k < cur.c; k++)
        {
            int a; cin >> a;
            cur.sticker[j][k] = (a == 1);
        }

        attach(cur);
    }

    int ans = 0;
    for (int row = 0; row < N; row++)
    {
        for (int col = 0; col < M; col++)
        {
            if (board[row][col])
                ans++;
        }
    }
    cout << ans;
    return 0;
}