#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
#include <string>
#include <cassert>
#include <cmath>

using namespace std;

int N, ATK;
long long ans = 0;
long long curDmg = 0;

typedef struct Node{
    int t, a, h;
}Node;

Node rooms[123456];

bool check(long long maxHP)
{
    long long curHP = maxHP;
    long long curATK = ATK;
    for(int i = 0; i < N; i++)
    {
        if(rooms[i].t == 1)
        {
            long long mobATKCnt = (rooms[i].h / curATK) + (rooms[i].h % curATK == 0 ? 0 : 1) - 1;
            if(curHP <= (long long)rooms[i].a * mobATKCnt) return false;
            curHP -= (rooms[i].a * mobATKCnt);
        }
        else
        {
            curHP = min(curHP + rooms[i].h, maxHP);
            curATK += rooms[i].a;
        }
    }
    return true;
}

int main(int argc, char* argv[])
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> ATK;
    for(int i = 0; i < N; i++)
        cin >> rooms[i].t >> rooms[i].a >> rooms[i].h;

    long long left = 0;
    long long right = 999999000000 * 123456 + 1 + 1;

    while(left + 1 < right)
    {
        long long mid = (left + right) / 2;
        if(check(mid))
            right = mid;
        else
            left = mid;
    }

    cout << right << '\n';
    return 0;
}