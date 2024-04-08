#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

constexpr int SAME = 1;
constexpr int DIFF = -1;

int dy[9] = {0, -1, -1, -1, 0, 1, 1, 1, 0};
int dx[9] = {-1, -1, 0, 1, 1, 1, 0, -1, 0};

int N, M;

string query[50];
string target[50];

int board[50][50];
bool isFixed[50][50];

void flip(int i, int j)
{
    for(int dir = 0; dir < 9; dir++)
        board[i + dy[dir]][j + dx[dir]] *= -1;
}

int main(int argc, char* argv[])
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> M;
    for(int i = 0; i < N; i++)
        cin >> query[i];
    for(int i = 0; i < N; i++)
        cin >> target[i];

    for(int i = 0; i < N; i++) for(int j = 0; j < M; j++)
    {
        board[i][j] = (query[i][j] != target[i][j] ? DIFF : SAME);
    }

    int ans = 0;
    for(int i = 1; i < N - 1; i++)
    {
        for(int j = 1; j < M - 1; j++)
        {
            if(board[i - 1][j - 1] == DIFF)
            {
                ans++;
                flip(i, j);
            }
        }
    }

    for(int i = 0; i < N; i++) for(int j = 0; j < M; j++)
    {
        if(board[i][j] == DIFF)
        {
            cout << -1;
            return 0;
        }
    }

    cout << ans;
    return 0;
}