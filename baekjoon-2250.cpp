#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
#include <string>
#include <cassert>

using namespace std;

struct Node{
    int cnt = 0;
    int left, right;
}arr[10001];

int N;
int ans[10001];

int inorder[10001];
int levelOrder[10001];

int idx = 0;
void inOrderIdx(int cur)
{
    if(cur < 0) return;
    inOrderIdx(arr[cur].left);
    inorder[cur] = idx++;
    inOrderIdx(arr[cur].right);
}

void BFS(int root)
{
    queue<pair<int, int>> Q; Q.push({root, 1});
    vector<pair<int, int>> curLevNodes;

    int curLev = 0;
    while(!Q.empty())
    {
        auto [cur, level] = Q.front(); Q.pop();
        if(level != curLev)
        {
            if(!curLevNodes.empty())
                ans[curLev] = max(ans[curLev], 1 + abs(inorder[curLevNodes[0].first] - inorder[curLevNodes.back().first]));
            curLev = level;
            curLevNodes.clear();
            curLevNodes.push_back({cur, level});
        }
        else
        {
            curLevNodes.push_back({cur, level});
        }
        if(arr[cur].left > 0)
            Q.push({arr[cur].left, level + 1});
        if(arr[cur].right > 0)
            Q.push({arr[cur].right, level + 1});
    }
    ans[curLev] = max(ans[curLev], 1 + abs(inorder[curLevNodes[0].first] - inorder[curLevNodes.back().first]));

    int ansLev = -1;
    int ansWidth = -1;
    for(int i = 1; i <= N; i++)
    {
        if(ansWidth < ans[i])
        {    
            ansLev = i;
            ansWidth = ans[i];
        }
    }
    assert(ansLev > 0 && ansWidth > 0);
    cout << ansLev << ' ' << ansWidth << '\n';
}

int main(int argc, char* argv[])
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N;
    int root = N * (N + 1) / 2;
    for(int i = 0; i < N; i++)
    {
        int a, b, c; cin >> a >> b >> c;
        arr[a].left = b;
        arr[a].right = c;
        if(b > 0) root -= b;
        if(c > 0) root -= c;
    }

    inOrderIdx(root);
    BFS(root);

    return 0;
}