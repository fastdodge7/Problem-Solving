#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <string>
#include <cassert>

using namespace std;

string init, dest;
string cache;
int ans = 0;

void flip(int idx, string& f)
{
    ans++;
    if(idx > 0)
    {
        if(f[idx - 1] == '1')
            f[idx - 1] = '0';
        else
            f[idx - 1] = '1';
    }
    if(f[idx] == '1')
        f[idx] = '0';
    else
        f[idx] = '1';
    if(idx < f.size() - 1)
    {
        if(f[idx + 1] == '1')
            f[idx + 1] = '0';
        else
            f[idx + 1] = '1';
    }
}

int solve(string fromStr, string toStr)
{
    for(int i = 1; i <= dest.size() - 1; i++)
    {
        if(fromStr[i - 1] != toStr[i - 1])
        {
            flip(i, fromStr);
        }
    }
    for(int i = 0; i < fromStr.size(); i++)
    {
        if(fromStr[i] != toStr[i])
        {
            ans = 0;
            return 1e9;
        }
    }
    int ret = ans;
    ans = 0;
    return ret;
}

int main(int argc, char* argv[])
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    int N; cin >> N;
    cin >> init >> dest;
    cache = string(init);

    int ret = solve(init, dest);
    
    flip(0, init);
    ret = min(ret, solve(init, dest));

    cout << (ret == 1e9 ? -1 : ret);


    return 0;
}