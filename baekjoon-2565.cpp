#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int N;
int dp[501];
int arr[501];

int main(int argc, char* argv[])
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N;
    for (int i = 0; i < N; i++)
    {
        int a, b; cin >> a >> b;
        arr[a] = b;
        dp[a] = 1;
    }
    
    for (int i = 1; i <= 500; i++)
    {
        if (arr[i] == 0) continue;
        for (int j = 1; j < i; j++)
        {
            if (arr[j] == 0) continue;

            if (arr[j] < arr[i])
                dp[i] = max(dp[i], dp[j] + 1);
        }
    }
    
    cout << N - (*max_element(dp, dp + 501));

    return 0;
}