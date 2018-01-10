#include<iostream>

using namespace std;

void input();
int solution(int x, int y);
void result();

int height;
int width;
int map[502][502];
int dp[501][501] = { 0, };
int visit[501][501] = { 0, };
int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };

int main()
{
	input();
	solution(1, 1);
	cout << dp[1][1]<< endl;
	return 0;
}

void input()
{
	cin >> height >> width;

	for (int i = 0; i <= height+1; i++)
		for (int j = 0; j <= width+1; j++)
			map[i][j] = -1;

	for (int i = 1; i <= height; i++)
		for (int j = 1; j <= width; j++)
			cin >> map[i][j];
}

int solution(int x, int y)
{
	if (x == height && y == width)
		dp[x][y] = 1;

	if (dp[x][y] > 0 || visit[x][y] == 1)
		return dp[x][y];

	visit[x][y] = 1;
	for (int i = 0; i < 4; i++)
	{
		if (map[x + dx[i]][y + dy[i]] > 0 && 
			map[x][y] > map[x + dx[i]][y + dy[i]])
		{
			dp[x][y] += solution(x + dx[i], y + dy[i]);
			//result();
			//cout << endl;
		}
	}
	
	return dp[x][y];
}


void result()
{
	for (int i = 0; i <= height+1; i++)
	{
		for (int j = 0; j <= width+1; j++)
			cout << dp[i][j] << ' ';

		cout << endl;
	}
}