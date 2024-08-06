#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
#include <string>
#include <cassert>
#include <cmath>

using namespace std;

int N;
long long dp[1000][3];
int cost[1000][3];

int main(int argc, char* argv[])
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N;
    for(int i = 0; i < N; i++)
    {
        cin >> cost[i][0];
        cin >> cost[i][1];
        cin >> cost[i][2];
    }

    dp[0][0] = cost[0][0];
    dp[0][1] = cost[0][1];
    dp[0][2] = cost[0][2];

    for(int i = 1; i < N; i++)
    {
        dp[i][0] = (long long)cost[i][0] + min(dp[i - 1][1], dp[i - 1][2]);
        dp[i][1] = (long long)cost[i][1] + min(dp[i - 1][0], dp[i - 1][2]);
        dp[i][2] = (long long)cost[i][2] + min(dp[i - 1][0], dp[i - 1][1]);
    }

    cout << min(dp[N - 1][0], min(dp[N - 1][1], dp[N - 1][2])) << '\n';
    return 0;
}