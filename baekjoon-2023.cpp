#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
#include <string>
#include <cassert>
#include <cmath>

using namespace std;

int N;
vector<int> arr[9];

int adder[4] = {1, 3, 7, 9};

bool isPrime(int target)
{
    int lim = sqrt(target) + 1;
    for(int i = 2; i <= lim; i++)
    {
        if(target % i == 0) return false;
    }
    return true;
}

int main(int argc, char* argv[])
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N;
    arr[1] = {2, 3, 5, 7};

    for(int i = 2; i <= N; i++)
    {
        for(int seed : arr[i - 1])
        {
            for(int j = 0; j < 4; j++)
            {
                int newCand = seed * 10 + adder[j];
                if(isPrime(newCand))
                    arr[i].push_back(newCand);
            }
        }
    }

    for(int ans : arr[N])
        cout << ans << '\n';

    return 0;
}