#include <iostream>
using namespace std;

int N;

bool visited[30][30];

int dy[4] = {0, 0, 1, -1};
int dx[4] = {1, -1, 0, 0};
double prob[4];

double DFS(int depth, int r, int c)
{
	
	if(visited[r][c]) return 0.0;
	if(depth == N) return 1.0;
	visited[r][c] = true;
	
	double ret = 0.0;
	for(int i = 0; i < 4; i++)
		ret += prob[i] * DFS(depth + 1, r + dy[i], c + dx[i]);
		
	visited[r][c] = false;
	return ret;
}
int main() {
	cin >> N;
	for(int i = 0; i < 4; i++)
	{
		cin >> prob[i]; 
		prob[i] /= 100.0;
	}
	
	cout<<fixed;
	cout.precision(15);
		
	cout << DFS(0, 14, 14);
	return 0;
}