#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
#include <string>
#include <cassert>
#include <cmath>

using namespace std;

string input;
int dp[5000];

int solve(int idx)
{
    if(idx == 0) return 1;
    if(idx < 0) return 1;
    if(dp[idx] > 0) return dp[idx];

    int code = stoi(input.substr(idx - 1, 2));
    if(code < 1 || code > 26)
        return dp[idx] = solve(idx - 1);
    else
        return dp[idx] = (solve(idx - 1) + solve(idx - 2)) % 1000000;
}


/*
    code == 10, 20의 경우는 1개
    code == 30 이상의 경우는 오류
    code == 10 미만인 경우 


 */

int check(int code)
{
    if(code == 0) return -1;
    if(code == 10 || code == 20) return 1;
    if(code % 10 == 0 && code > 20) return -1;
    if(code < 10 || code > 26) return 1;
    return 2;
}

int solve2()
{
    if(input[0] == '0') return 0;
    if(input.size() == 1) return 1;

    dp[0] = 1;
    int code = stoi(input.substr(0, 2));
    if(check(code) == -1) return 0;
    if(check(code) == 1) dp[1] = dp[0];
    else dp[1] = 2;


    for(int idx = 2; idx < input.size(); idx++)
    {
        int code = stoi(input.substr(idx - 1, 2));
        if(check(code) == -1) return 0;
        if(check(code) == 1)
        {
            dp[idx] = dp[idx - 1 - (int)(code % 10 == 0)];
        }
        else dp[idx] = (dp[idx - 1] + dp[idx - 2]) % 1000000;
    }
    return dp[input.size() - 1];
}

int main(int argc, char* argv[])
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> input;

    int ans = solve2();
    cout << (ans);

    //cout << solve2();
    return 0;
}