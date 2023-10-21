#include <iostream>
#include <algorithm>

using namespace std;

int N;
int di[3] = {-1, 0, 1};

int board[2][3];
int minDp[2][3];
int maxDp[2][3];

int main(int argc, char *argv[])
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N;
    for(int j = 0; j < 3; j++)
    {
        cin >> board[0][j];
        minDp[0][j] = maxDp[0][j] = board[0][j];
    }

    for(int i = 1; i < N; i++)
    {
        for(int j = 0; j < 3; j++)
        {
            cin >> board[1][j];
            minDp[1][j] = 1e9 + 7;
            maxDp[1][j] = 0;
        }
        for(int j = 0; j < 3; j++)
        {
            for(int k = 0; k < 3; k++)
            {
                int before = j + di[k];
                if(before < 0 || before >= 3) continue;
                minDp[1][j] = min(minDp[1][j], minDp[0][before] + board[1][j]);
                maxDp[1][j] = max(maxDp[1][j], maxDp[0][before] + board[1][j]);
            }
        }
        for(int j = 0; j < 3; j++)
        {
            board[0][j] = board[1][j];
            minDp[0][j] = minDp[1][j];
            maxDp[0][j] = maxDp[1][j];
        }
    }
    
    cout << max(maxDp[0][0], max(maxDp[0][1], maxDp[0][2]))
    << ' ' << min(minDp[0][0], min(minDp[0][1], minDp[0][2]));

    return 0;
}