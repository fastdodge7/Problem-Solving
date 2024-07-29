#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
#include <string>
#include <cassert>
#include <cmath>

using namespace std;

typedef struct Edge{
    pair<int, int> start, end;
    double dist;

    bool operator<(const Edge& other) const {
        return dist < other.dist;
    }
}Edge;

int N;
vector<Edge> edges[1000];
vector<pair<int, int>> point;

double calcDist(pair<int, int>& a, pair<int, int>& b)
{
    int dx = a.first - b.first;
    int dy = a.second - b.second;
    return sqrt(dx * dx + dy * dy);
}

int main(int argc, char* argv[])
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N;
    for(int i = 0; i < N; i++)
    {
        int a, b; cin >> a >> b;
        point.push_back({a, b});
    }

    for(int i = 0; i < point.size(); i++)
    {
        for(int j = i + 1; j < point.size(); j++)
        {
            double dist = calcDist(point[i], point[j]);
            edges[i].push_back({point[i], point[j], dist});
            edges[j].push_back({point[j], point[i], dist});
        }
    }

    double ansX = point[0].first, ansY = point[0].second;
    double dist = 900000.0;
    for(int i = 0; i < point.size(); i++)
    {
        double maxDist = 1e9;
        for(auto e : edges[i])
        {
            if(maxDist > 1e8)
            {
                maxDist = e.dist;
            }
            else
                maxDist = max(maxDist, e.dist);
        }
        if(maxDist < dist)
        {
            ansX = point[i].first;
            ansY = point[i].second;
            dist = maxDist;
        }
    }

    cout << ansX << ' ' << ansY;
    return 0;
}