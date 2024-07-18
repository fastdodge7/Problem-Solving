#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <unordered_map>

using namespace std;

unordered_map<string, int> typeMapper = {
	{"Subway", 1}, {"Bus", 2},
	{"Taxi", 3}, {"Airplane", 4},
	{"KTX", 5}, {"S-Train", 6},
	{"V-Train", 7}, {"ITX-Saemaeul", 8},
	{"ITX-Cheongchun", 9}, {"Mugunghwa", 10},
};

int N, R, M, K;
unordered_map<string, int> nameToId;
vector<int> travelList;

int matrix[100][100];
int fmatrix[100][100];

int clacFee(int type, int cost, bool hasFutureTicket)
{
	if(!hasFutureTicket) return cost;
	if(type == 8 || type == 9 || type == 10) return 0;
	if(type == 6 || type == 7) return cost / 2;
	return cost;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	fill(&matrix[0][0], &matrix[99][99] + 1, 1e9);
	fill(&fmatrix[0][0], &fmatrix[99][99] + 1, 1e9);
	cin >> N >> R; R *= 2;
	for(int i = 0; i < N; i++)
	{
		string name; cin >> name;
		if(nameToId.find(name) == nameToId.end())
		{
			nameToId.insert({name, i});
			matrix[i][i] = 0;
			fmatrix[i][i] = 0;
		}
	}
	cin >> M;
	for(int i = 0; i < M; i++)
	{
		string name; cin >> name;
		travelList.push_back(nameToId[name]);
	}
	cin >> K;
	for(int i = 0; i < K; i++)
	{
		string type, start, end; cin >> type >> start >> end;
		int cost; cin >> cost;
		int typeId = typeMapper[type], startId = nameToId[start], endId = nameToId[end];
		cost *= 2;
		matrix[startId][endId] = matrix[endId][startId] = min(matrix[startId][endId], clacFee(typeId, cost, false));
		fmatrix[startId][endId] = fmatrix[endId][startId] = min(fmatrix[startId][endId], clacFee(typeId, cost, true));
	}

	for(int k = 0; k < N; k++)
	{
		for(int i = 0; i < N; i++)
		{
			if(matrix[i][i] == 1e9) continue;
			for(int j = 0; j < N; j++)
			{
				if(matrix[j][j] == 1e9) continue;
				if(i == j) continue;
				if(matrix[i][k] == 1e9 || matrix[k][j] == 1e9) continue;
				matrix[i][j] = min(matrix[i][j], matrix[i][k] + matrix[k][j]);
				fmatrix[i][j] = min(fmatrix[i][j], fmatrix[i][k] + fmatrix[k][j]);
			}
		}
	}

	int normal = 0;
	int future = R;
	for(int i = 0; i < travelList.size() - 1; i++)
	{
		normal += matrix[travelList[i]][travelList[i + 1]];
		future += fmatrix[travelList[i]][travelList[i + 1]];
	}

	cout << (future < normal ? "Yes" : "No");
	return 0;
}