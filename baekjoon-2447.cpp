#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int N;

bool isStar(int r, int c, int curN)
{
    while(curN > 3)
    {
        int MOD = curN / 3;
        int rBlock = r / MOD;
        int cBlock = c / MOD;
        if(rBlock == 1 && cBlock == 1)
            return false;
        r = r % MOD;
        c = c % MOD;
        curN = curN / 3;
    }
    if(r == 1 && c == 1)
        return false;
    return true;
}

int main(int argc, char* argv[])
{
    scanf("%d", &N);
    for(int i = 0; i < N; i++) 
    {
        for(int j = 0; j < N; j++)
        {
            if(isStar(i, j, N))
                printf("*");
            else
                printf(" ");
        }
        printf("\n");
    }
    return 0;
}