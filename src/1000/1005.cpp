#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solution(int n);

int buildTime[1000] = { 0, };
int resultTime[1000] = { 0 };
int buildNum = 0;
int order = 0;
vector<vector<int>*> arr;
int visit[1000] = { 0, };

int main()
{
	int testCase;

	cin >> testCase;

	for (int i = 0; i < testCase; i++)
	{
		fill_n(buildTime, 1000, 0);
		fill_n(resultTime, 1000, 0);
		fill_n(visit, 1000, 0);
		buildNum = 0;
		order = 0;

		cin >> buildNum >> order;
		for (int j = 0; j < buildNum; j++)
		{
			cin >> buildTime[j];
			arr.push_back(new vector<int>);
		}


		for (int j = 0; j < order; j++)
		{
			int sTmp;
			int eTmp;

			cin >> sTmp >> eTmp;
			
			arr[eTmp - 1]->push_back(sTmp - 1);
			
		}


		for (int j = 0; j < arr.size(); j++)
		{
			sort(arr[j]->begin(), arr[j]->end());
		}

		for (int j = 0; j < arr.size(); j++)
		{
			solution(j);
		}

		int resultNum;
		cin >> resultNum;
		cout << resultTime[resultNum - 1] << endl;
		arr.clear();
	}
}

void solution(int n)
{
	if (visit[n] == 1)
		return;

	if (arr[n]->size() == 0)
	{
		resultTime[n] = buildTime[n];
	}
	else
	{
		for (int k = 0; k < arr[n]->size(); k++)
		{
			if (resultTime[(*arr[n])[k]] != 0)
			{
				if (resultTime[n] == 0)
				{
					resultTime[n] = resultTime[(*arr[n])[k]] + buildTime[n];
				}
				else
				{
					if (resultTime[n] < resultTime[(*arr[n])[k]] + buildTime[n])
						resultTime[n] = resultTime[(*arr[n])[k]] + buildTime[n];
				}
			}
			else if (resultTime[(*arr[n])[k]] == 0)
			{
				solution((*arr[n])[k]);
				k--;
			}
		}
	}

	visit[n] = 1;
}