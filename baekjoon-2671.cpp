#include <iostream>
#include <vector>
#include <string>

using namespace std;

enum State{
    INIT,
    ONEOO,
    ONE,
    NOISE
};

typedef struct Automata{
public:
    Automata(string str) : str(str), state(INIT), idx(0) {

    }

    bool solve()
    {
        while(idx < str.size() && state != NOISE)
        {
            state = step();
        }
        return state == INIT || state == ONE;
    }
private:
    State step()
    {
        if(state == INIT)
        {
            State ret = NOISE;
            if(str.size() - idx >= 2 && str.substr(idx, 2) == "01")
            {
                idx += 2;
                ret = INIT;
            }
            else if(str.size() - idx >= 3 && str.substr(idx, 3) == "100")
            {
                idx += 3;
                ret = ONEOO;
            }
            return ret; 
        }
        else if(state == ONEOO)
        {
            if(str.size() - idx == 0) return NOISE;

            State ret = NOISE;
            if(str.substr(idx, 1) == "1") ret = ONE;
            else if(str.substr(idx, 1) == "0") ret = ONEOO;
            idx++;
            return ret;
        }
        else if(state == ONE)
        {
            State ret = NOISE;
            if(str.size() == idx) return INIT;
            if(str.size() - idx >= 2 && str.substr(idx, 2) == "01")
            {
                idx += 2;
                ret = INIT;
            }
            else if(str.size() - idx >= 3 && str.substr(idx, 3) == "100")
            {
                idx += 3;
                ret = ONEOO;
            }
            else if(str.size() - idx >= 1 && str.substr(idx, 1) == "1")
            {
                idx += 1;
                ret = ONE;
            }
            return ret;
        }
        else
            return NOISE;
    }

    int idx;
    string str;
    State state;
}Automata;


int main(int argc, char* argv[])
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    string tape; cin >> tape;
    Automata at = Automata(tape);

    cout << (at.solve() ? "SUBMARINE" : "NOISE");
    return 0;
}