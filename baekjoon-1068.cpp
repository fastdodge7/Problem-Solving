#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

constexpr int DELETED = 9999;

int parent[51];
int edges[51];
bool isLeaf[51];

int Find(int a)
{
    if(parent[a] == -1)
        return a;
    return parent[a] = Find(parent[a]);
}

void Union(int a, int b)
{
    a = Find(a);
    b = Find(b);

    if(a == b) return;
    parent[b] = a;
}

int main(int argc, char* argv[])
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    fill(isLeaf, isLeaf + 51, true);

    int N; cin >> N;
    for(int i = 0; i < N; i++)
    {
        cin >> parent[i];
    }
    memcpy(edges, parent, sizeof(parent));

    int target; cin >> target;
    parent[target] = -1;

    for(int i = 0; i < N; i++)
    {
        Find(i);
    }
    for(int i = 0; i < N; i++)
    {
        if(parent[i] == target)
            parent[i] = DELETED;
    }
    parent[target] = DELETED;

    for(int i = 0; i < N; i++)
    {
        if(parent[i] == DELETED) continue;
        if(edges[i] >= 0 && isLeaf[edges[i]])
        {
            isLeaf[edges[i]] = false;
        }
    }

    int ans = 0;
    for(int i = 0; i < N; i++)
    {
        if(parent[i] != DELETED && isLeaf[i])
            ans++;
    }

    cout << ans << '\n';
    return 0;
}