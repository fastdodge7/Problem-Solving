#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
#include <string>
#include <cassert>
#include <cmath>

using namespace std;

int N;
int arr[2000][2];
int dp[2001][2001];

int solve(int left, int right)
{
    if(left == N || right == N) return 0;

    if(dp[left][right] >= 0 || visited[left][right]) return dp[left][right];

    if(arr[left][0] > arr[right][1])
    {
        dp[left][right] = max(dp[left][right], arr[right][1] + solve(left, right + 1));
    }
    dp[left][right] = max(dp[left][right], solve(left + 1, right + 1));
    dp[left][right] = max(dp[left][right], solve(left + 1, right));

    return dp[left][right];
}

int main(int argc, char* argv[])
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    fill(&dp[0][0], &dp[2000][2000] + 1, -1);

    cin >> N;
    for(int i = 0; i < N; i++)
        cin >> arr[i][0];
    for(int i = 0; i < N; i++)
        cin >> arr[i][1];

    cout << solve(0, 0);
    return 0;
}