#include <iostream>
#include <algorithm>
#include <numeric>
#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

constexpr char NUM = -1;

vector<char> stck;
vector<int> numStck;
unordered_map<char, char> braceMapper = {
    {')', '('},
    {']', '['}
};
unordered_map<char, int> valueMapper = {
    {')', 2},
    {']', 3}
};
int ans = 0;

int main(int argc, char* argv[])
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    string str; cin >> str;
    for(char c : str)
    {
        if(c == '(' || c == '[')
            stck.push_back(c);
        else
        {
            bool meetBrace = false;
            int acc = 0;
            while(!stck.empty())
            {
                char cur = stck.back();
                stck.pop_back();

                if(cur == braceMapper[c]) // 괄호가 올바르게 닫힘
                {
                    meetBrace = true;
                    break; 
                }

                if(cur != braceMapper[c] && cur != NUM) // 괄호가 이상하게 닫힘.
                { 
                    cout << 0;
                    return 0;
                }

                if(cur == NUM)
                {
                    acc += numStck.back();
                    numStck.pop_back();
                }
            }

            if(!meetBrace)
            { // 괄호가 안닫힘.
                cout << 0;
                return 0;
            }

            stck.push_back(NUM);
            if(acc == 0)
                numStck.push_back(valueMapper[c]);
            else
                numStck.push_back(valueMapper[c] * acc);

        }
    }

    for(int i = 0; i < stck.size(); i++)
    {
        if(stck[i] != NUM)
        {
            cout << 0 << '\n';
            return 0;
        } 
    }

    int sum = accumulate(numStck.begin(), numStck.end(), 0);
    cout << sum << '\n';
    return 0;
}