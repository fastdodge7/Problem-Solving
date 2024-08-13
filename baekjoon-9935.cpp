#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
#include <string>
#include <cassert>
#include <cmath>

using namespace std;

string target;
string bomb;

vector<char> stck;

int main(int argc, char* argv[])
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> target >> bomb;
    int idx = 0;
    for(int i = 0; i < target.size(); i++)
    {
        stck.push_back(target[i]);
        if(stck.size() >= bomb.size() && target[i] == bomb.back())
        {
            bool match = true;
            for(int j = 0; j < bomb.size(); j++)
            {
                if(bomb[bomb.size() - 1 - j] != stck[stck.size() - 1 - j])
                {
                    match = false;
                    break;
                }
            }
            if(match)
            {
                for(int j = 0; j < bomb.size(); j++)
                    stck.pop_back();
            }
        }
    }

    for(char c : stck)
        cout << c;
    
    if(stck.empty())
    {
        cout << "FRULA";
    }
    return 0;
}