#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
#include <string>
#include <cassert>

using namespace std;

long long W, H, f, c, xpos1, ypos1, xpos2, ypos2;

int main(int argc, char* argv[])
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> W >> H >> f >> c >> xpos1 >> ypos1 >> xpos2 >> ypos2;

    long long fnWidth = max(W - f, f);
    long long fnHeight = H / (c + 1);
    long long dblWidth = min(W - f, f);

    if(xpos1 >= dblWidth)
    {
        cout << W * H - (xpos2 - xpos1) * (ypos2 - ypos1) * (c + 1);
        return 0;
    }
    else if(xpos2 <= dblWidth)
    {
        cout << W * H - (xpos2 - xpos1) * (ypos2 - ypos1) * (c + 1) * 2;
        return 0;
    }
    else
    {
        cout << W * H - (dblWidth - xpos1) * (ypos2 - ypos1) * (c + 1) * 2ll - (xpos2 - dblWidth) * (ypos2 - ypos1) * (c + 1);;
        return 0;
    }

    return 0;
}