#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>

using namespace std;

typedef struct Node{
    long long distance;
    int dest;
    int step;

    bool operator>(const Node& other) const {
        return distance > other.distance;
    }
}Node;

long long foxDistance[4001];
long long wolfDistance[4001][2];
vector<pair<int, int>> matrix[4001];

int N, M;

void foxDijkstra()
{
    fill(foxDistance, foxDistance + 4001, (long long)2e9);
    priority_queue<Node, vector<Node>, greater<Node>> pQ;
    foxDistance[1] = 0;
    pQ.push({0, 1, 0});

    while(!pQ.empty())
    {
        Node cur = pQ.top(); pQ.pop();
        if(cur.distance > foxDistance[cur.dest]) continue;

        for(auto p : matrix[cur.dest])
        {
            int next = p.first;
            float cost = p.second;
            if(cur.distance + cost < foxDistance[next])
            {
                foxDistance[next] = cur.distance + cost;
                pQ.push({foxDistance[next], next, cur.step + 1});
            }
        }
    }
}

void wolfDijkstra()
{
    fill(&wolfDistance[0][0], &wolfDistance[4000][1] + 1, (long long)2e9);
    priority_queue<Node, vector<Node>, greater<Node>> pQ;
    wolfDistance[1][0] = 0;
    pQ.push({0, 1, 0});

    while(!pQ.empty())
    {
        Node cur = pQ.top(); pQ.pop();
        if(cur.distance > wolfDistance[cur.dest][cur.step % 2]) continue;

        for(auto p : matrix[cur.dest])
        {
            int next = p.first;
            long long cost = p.second;
            long long newDist = cur.distance
             + (cur.step % 2 == 1 ? cost * 2 : cost / 2);
            if(newDist < wolfDistance[next][(cur.step + 1) % 2])
            {
                wolfDistance[next][(cur.step + 1) % 2] = newDist;
                pQ.push({wolfDistance[next][(cur.step + 1) % 2], next, cur.step + 1});
            }
        }
    }
}

void printAll()
{
    cout << "Fox Dist : ";
    for(int i = 1; i <= N; i++)
    {
        cout << foxDistance[i] << ' ';
    }
    cout << '\n';

    cout << "Wolf Dist : ";
    for(int i = 1; i <= N; i++)
    {
        cout << min(wolfDistance[i][0], wolfDistance[i][1]) << ' ';
    }
    cout << '\n';
}

int main(int argc, char* argv[])
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> M;
    for(int i = 0; i < M; i++)
    {
        int a, b, c; cin >> a >> b >> c;
        matrix[a].push_back({b, 2 * c});
        matrix[b].push_back({a, 2 * c});
    }

    foxDijkstra();
    wolfDijkstra();

    int ans = 0;
    for(int i = 1; i <= N; i++)
    {
        if(foxDistance[i] < min(wolfDistance[i][0], wolfDistance[i][1]))
            ans++;
    }

    cout << ans;
    return 0;
}