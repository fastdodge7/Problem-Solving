#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
#include <string>
#include <cassert>
#include <tuple>

using namespace std;

int N, M, K;
int parent[1001];
int ans = 0;
vector<tuple<int, int, int>> arr;

int Find(int a)
{
    if(parent[a] == a) return a;
    return parent[a] = Find(parent[a]);
}

void Union(int a, int b, int cost)
{
    a = Find(a);
    b = Find(b);
    if(a > b) swap(a, b);
    if(a == b) return;
    parent[b] = a;
    ans += cost;
}

int main(int argc, char* argv[])
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> M >> K;
    for(int i = 0; i <= N; i++)
        parent[i] = i;
    for(int i = 0; i < K; i++)
    {
        int a; cin >> a;
        Union(0, a, 0);
    }
    for(int i = 0; i < M; i++)
    {
        int c, a, b; cin >> a >> b >> c;
        arr.push_back({c,a,b});
    }

    sort(arr.begin(), arr.end());

    for(int i = 0; i < arr.size(); i++)
    {
        auto [cost, a, b] = arr[i];
        Union(a, b, cost);
    }

    cout << ans;
    return 0;
}