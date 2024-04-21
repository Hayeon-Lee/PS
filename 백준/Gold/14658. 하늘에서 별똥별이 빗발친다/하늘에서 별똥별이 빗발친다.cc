#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, M, L, K;

int Max = 0;

//별똥별의 갯수 세주기
int Check(int StartX, int StartY,int EndX, int EndY
, const vector<pair<int, int>>& vecPos)
{
	int Cnt = 0;

	for (int i = 0; i < K; ++i)
	{
		if (vecPos[i].first <= EndX &&
			vecPos[i].first >= StartX &&
			vecPos[i].second <= EndY &&
			vecPos[i].second >= StartY)
			++Cnt;
	}

	return Cnt;
}

int main()
{
	cin.tie(nullptr);
	cout.tie(nullptr);
	ios::sync_with_stdio(false);

	cin >> N >> M >> L >> K;

	vector<int> vecX;
	vector<int> vecY;
	vector<pair<int, int>> vecPos(K);

	for (int i = 0; i < K; ++i)
	{
		cin >> vecPos[i].first >> vecPos[i].second;

		vecX.push_back(vecPos[i].first);
		vecY.push_back(vecPos[i].second);
	}

	sort(vecX.begin(), vecX.end());
	sort(vecY.begin(), vecY.end());

	for (int i = 0; i < K; ++i)
	{
		for (int j = 0; j < K; ++j)
		{
			Max = max(Max, Check(vecX[i],vecY[j], vecX[i] + L, vecY[j] + L, vecPos));
		}
	}

	cout << K - Max;
	
}