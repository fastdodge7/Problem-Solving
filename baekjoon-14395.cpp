#include <iostream>
#include <algorithm>
#include <unordered_set>
#include <queue>

using namespace std;

long long S, T;
unordered_set<long long> visited;

bool isPowerOf2(long long num)
{
    while(num > 1)
    {
        if(num % 2 == 1) return false;
        num /= 2;
    }
    return true;
}

string BFS(long long start, long long end)
{
    queue<pair<long long, string>> Q; Q.push({start, ""});
    unordered_set<long long> visited; visited.insert(start);

    while(!Q.empty())
    {
        auto [cur, cnt] = Q.front(); Q.pop();

        if(cur * cur <= end && visited.find(cur * cur) == visited.end())
        {
            if(cur * cur == end)
            {
                return cnt + "*";
            }
            Q.push({cur * cur, cnt + "*"});
            visited.insert(cur * cur);
        }

        if(cur * 2 <= end && visited.find(cur * 2) == visited.end())
        {
            if(cur * 2 == end)
            {
                return cnt + "+";
            }
            Q.push({cur * 2, cnt + "+"});
            visited.insert(cur * 2);
        }        
    }
    return "-1";
}

int main(int argc, char* argv[])
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> S >> T;

    if(S == T)
    {
        cout << 0;
        return 0;
    }

    if(S == 0)
    {
        cout << -1;
        return 0;
    }

    if(T == 0)
    {
        cout << "-";
        return 0;
    }

    if(T == 1)
    {
        cout << "/";
        return 0;
    }

    string cand = "-1";
    if(T % S == 0)
    {
        cand = BFS(S, T);
    }

    if(isPowerOf2(T))
    {
        string temp = "/" + BFS(1, T);
        if(temp.size() < cand.size() || cand == "-1")
            cand = temp;
    }
    
    cout << cand;
    return 0;
}