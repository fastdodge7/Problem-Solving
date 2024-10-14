#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <string>
#include <cassert>

using namespace std;

int T;
int dp[101][101][2];

int main(int argc, char* argv[])
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    cin >> T;
    dp[1][0][0] = dp[1][0][1] = 1;
    for(int i = 2; i <= 100; i++)
    {
        for(int j = 0; j < i; j++)
        {
            if(j == 0)
            {
                dp[i][j][1] = dp[i - 1][j][0];
            }
            else  
                dp[i][j][1] = dp[i - 1][j - 1][1] + dp[i - 1][j][0];

            dp[i][j][0] = dp[i - 1][j][0] + dp[i - 1][j][1];
        }
    }


    for(int test_case = 1; test_case <= T; test_case++)
    {
        int a, b; cin >> a >>  b;
        cout << dp[a][b][0] + dp[a][b][1] << '\n';
    }
    return 0;
}