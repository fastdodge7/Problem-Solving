#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
#include <string>
#include <cassert>
#include <tuple>

using namespace std;

constexpr int MAX_SIZE = 101;

int N, M, K;
int arr[MAX_SIZE];
int tree[4 * MAX_SIZE];

void buildTree(int ptr, int start, int end)
{
    if(start == end)
    {
        tree[ptr] = arr[start];
        return;
    }

    int mid = (start + end) / 2;
    if(start < end)
    {
        buildTree(ptr * 2, start , mid);
        buildTree(ptr * 2 + 1, mid + 1, end);
        tree[ptr] = min(tree[ptr * 2], tree[ptr * 2 + 1]);
    }
}

int Find(int ptr, int start, int end, int tStart, int tEnd)
{
    if(tStart == start && end == tEnd)
        return tree[ptr];

    int mid = (start + end) / 2;
    if(tEnd <= mid) return Find(ptr * 2, start, mid, tStart, tEnd);
    if(mid < tStart) return Find(ptr * 2 + 1, mid + 1, end, tStart, tEnd);
    return min(Find(ptr * 2, start, mid, tStart, mid), Find(ptr * 2 + 1, mid + 1, end, mid + 1, tEnd));
}

int main(int argc, char* argv[])
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> M;
    for(int i = 0; i < N; i++)
        cin >> arr[i];

    buildTree(1, 0, N - 1);

    for(int i = 0; i < M; i++)
    {
        int a, b; cin >> a >> b;
        cout << Find(1, 0, N - 1, a - 1, b - 1) << '\n';
    }
    
    return 0;
}