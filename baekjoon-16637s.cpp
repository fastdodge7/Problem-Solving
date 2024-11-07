#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <queue>
#include <cmath>

using namespace std;

int N;
string expression;
bool paren[19];
long long ans = -1e18;

bool isOperator(const string& c)
{
	return c == "+" || c == "-" || c == "*";
}

string oneCalc(const string& a, const string& oper, const string& b)
{
	long long n1 = stoi(a);
	long long n2 = stoi(b);
	if(oper == "+")
		return to_string(n1 + n2);
	
	if(oper == "-")
		return to_string(n1 - n2);
	
	return to_string(n1 * n2);
}

long long calc(string exp)
{
	vector<string> stck;

	for(int i =  0; i < exp.size(); i++)
	{
		stck.push_back(string(1, exp[i]));

		while(1)
		{
			if(stck.size() == 1) break;
			else if(stck.back() == "(") break;
			
			else if(isOperator(stck.back())) break;

			else if(stck.back() == ")")
			{
				stck.pop_back();
				string temp = stck.back(); stck.pop_back();
				stck.pop_back();
				stck.push_back(temp);
			}

			else
			{
				if(stck.empty() || stck[stck.size() - 2] == "(") break;

				string b = stck.back(); stck.pop_back();
				string oper = stck.back(); stck.pop_back();
				string a = stck.back(); stck.pop_back();
				stck.push_back(oneCalc(a, oper, b));
			}
		}
	}

	return stoll(stck.back());
}

long long DFS(int curIdx, string exp, bool parOpen)
{
	if(curIdx >= N)
	{
		ans = max(ans, calc(exp));
		return ans;
	}

	if(!('0' <= expression[curIdx] && expression[curIdx] <= '9'))
	{
		return DFS(curIdx + 1, exp + expression[curIdx], parOpen);
	}
	else if(!parOpen)
	{
		int ret = DFS(curIdx + 1, exp + expression[curIdx], false);
		if(N - curIdx >= 3)
			ret = max(0ll, DFS(curIdx + 1, exp + '(' + expression[curIdx], true));
		return ret;
	}	
	else
	{	
		return DFS(curIdx + 1, exp + expression[curIdx] + ')', false);
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> N;
	cin >> expression;

	DFS(0, "", false);
	cout << ans;

	return 0;
}