#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

typedef struct Building{
	int start, end;
	int height;

	bool operator<(const Building& other) const { 
        if(start == other.start)
            return height >= other.height;
        return start < other.start; 
    }
}Building;

int N;
Building arr[100000];
priority_queue<pair<int, int>> pQ;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> N;
	for(int i = 0; i < N; i++)
	{
		int L, H, R; cin >> L >> H >> R;
		arr[i] = {L, R, H};
	}

	sort(arr, arr + N);

	pQ.push({0, (int)2e9});

	int curPos = arr[0].start;
	for(int i = 0; i < N; i++)
	{
		if(arr[i].start <= pQ.top().second)
		{
			if(arr[i].height > pQ.top().first)
				cout << arr[i].start << ' ' << arr[i].height << ' ';
			pQ.push({arr[i].height, arr[i].end});
		}
		else
		{
			curPos = pQ.top().second; pQ.pop();
			while(pQ.top().second <= curPos)
				pQ.pop();
			
			cout << curPos << ' ' << pQ.top().first << ' ';
			i--;
		}
	}	

	while(!pQ.empty())
	{
		curPos = pQ.top().second; pQ.pop();
		while(!pQ.empty() && pQ.top().second <= curPos)
			pQ.pop();
		
		if(curPos != 2e9)
			cout << curPos << ' ' << pQ.top().first << ' ';
	}
	
	return 0;
}