#include<iostream>

using namespace std;

void input();
unsigned long long solution(int i, int j);

int mapSize;
int map[102][102] = { 0, } ;
unsigned long long visit[102][102] = { 0, };

int result = 0;

int main()
{
	input();
	solution(1, 1);

	cout << visit[1][1] << endl;
	return 0;
}

void input()
{
	cin >> mapSize;

	for (int i = 1; i <= mapSize; i++)
		for (int j = 1; j <= mapSize; j++)
			cin >> map[i][j];

}

unsigned long long solution(int i, int j)
{
	if (visit[i][j] > 0)
	{
		return visit[i][j];
	}

	if (i == mapSize && j == mapSize)
	{
		return 1;
	}

	if (map[i][j] == 0)
		return 0;

	visit[i][j] += solution(i + map[i][j], j);
	visit[i][j] += solution(i, j + map[i][j]);

	return visit[i][j];
}