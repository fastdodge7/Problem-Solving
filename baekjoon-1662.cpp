#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<int> stck;
bool visited[50];

int DFS(int idx)
{
    int ret = 0;
    int mult = -1;
    for(int i = idx; i < stck.size(); i++)
    {
        if(visited[i]) continue;
        visited[i] = true;
        if(stck[i] == -1)
        {
            ret += mult * DFS(i + 1);
            ret--;
            continue;
        }
        if(stck[i] == -2) return ret;
        ret++;
        mult = stck[i];
    }
    return ret;
}

int main(int argc, char* argv[])
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    string str; cin >> str;
    for(char c : str){
        if(c == ')')
            stck.push_back(-2);
        else if(c == '(')
            stck.push_back(-1);
        else
            stck.push_back(c - '0');
    }
    
    cout << DFS(0) << '\n';
    return 0;
}