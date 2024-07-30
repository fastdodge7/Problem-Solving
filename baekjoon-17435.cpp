#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
#include <string>
#include <cassert>
#include <cmath>

using namespace std;

int N, Q;
int arr[19][200001];

int solve(int n, int x)
{
    while(1)
    {
        if(n == 1) return arr[0][x];

        int nn = -1;
        int exp = -1;
        int mask = (1 << 18);
        for(int i = 18; i >= 0; i--)
        {
            if((mask & n) > 0)
            {
                if((mask & n) == n)
                    return arr[i][x];
                    
                exp = i;
                nn = ((mask - 1) & n);
                break;
            }
            mask >>= 1;
        }
        n = nn;
        x = arr[exp][x];
    }   
    return -1;
}

int main(int argc, char* argv[])
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N;
    for(int i = 1; i <= N; i++)
        cin >> arr[0][i];

    for(int exp = 1; exp <= 18; exp++)
    {
        for(int i = 1; i <= N; i++)
            arr[exp][i] = arr[exp - 1][arr[exp - 1][i]];
    }

    cin >> Q;
    for(int i = 0; i < Q; i++)
    {
        int a, b; cin >> a >> b;
        cout << solve(a, b) << '\n';
    }

    return 0;
}