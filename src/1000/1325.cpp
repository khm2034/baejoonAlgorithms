#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

void input();
void solution();
int dfs(int n);

vector<vector<int>> map(10000);
vector<int> result(10000) ;
vector<int> maxIndex;
int visit[10000] = { 0, };
int comNum;
int connect;
int nowIndex;
int maxResult = 0;

int main()
{
	input();
	solution();

	for (int i = 0; i < maxIndex.size(); i++)
	{
		cout << maxIndex[i]+1 << " ";
	}

	/*cout << endl;
	for (int i = 0; i < comNum; i++)
	{
		cout << i + 1 << " : " << result[i] << endl;
	}*/

	return 0;
}

void input()
{
	cin >> comNum >> connect;

	/*for (int i = 0; i < comNum; i++)
	{
		map.push_back(new vector<int>);
		result.push_back(0);
	}*/

	for (int i = 0; i < connect; i++)
	{
		int x, y;
		cin >>x >> y;

		map[y - 1].push_back(x-1);
	}
}

void solution()
{
	for (int i = 0; i < comNum; i++)
	{
		if(map[i].size() == 0)
			continue;

		result[i] = dfs(i);

		if (result[i] == maxResult) 
		{
			maxIndex.push_back(i);
		}
		else if (result[i] > maxResult)
		{
			maxResult = result[i];
			maxIndex.clear();
			maxIndex.push_back(i);
		}

		for (int j = 0; j < comNum; j++)
			visit[j] = 0;
	}
}

int dfs(int n) 
{
	//if (visit[n] != 0)
	//	return result[n];

	visit[n] = 1;
	int ret = 1;

	for (int i = 0; i < map[n].size(); i++)
	{
		if(visit[map[n][i]] == 0)
			ret +=  dfs(map[n][i]);
	}

	return ret;
}