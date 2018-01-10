#include <iostream>

using namespace std;

void input();
void solution(int t);
void check(int x, int y);

int T;
int M;
int N;
int K;
int map[52][52];
int visit[52][52];
int cnt;
int* result;

int dx[4] = { 1, -1, 0, 0 };
int dy[4] = { 0, 0, 1, -1 };

int main()
{
	cin >> T;
	result = new int[T];
	for (int t = 0; t < T; t++)
	{
		input();
		solution(t);
	}

	for (int t = 0; t < T; t++)
	{
		cout << result[t] << endl;
	}
	return 0;
}

void input()
{
	cin >> M >> N >> K;

	cnt = 0;
	for (int i = 0; i <= M + 1; i++)
	{
		for (int j = 0; j <= N + 1; j++)
		{
			map[i][j] = 0;
			visit[i][j] = 0;
		}
	}

	for (int i = 0; i < K; i++)
	{
		int x, y;

		cin >> x >> y;

		map[x + 1][y + 1] = 1;
	}
}

void solution(int t)
{
	for (int i = 1; i <= M; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			if (visit[i][j] == 0 && map[i][j] == 1)
			{
				cnt++;
				check(i, j);
			}
		}
	}

	result[t] = cnt;
}

void check(int x, int y)
{
	visit[x][y] = 1;

	for (int i = 0; i < 4; i++)
	{
		if (visit[x + dx[i]][y + dy[i]] == 0 && map[x + dx[i]][y + dy[i]] == 1)
		{
			check(x + dx[i], y + dy[i]);
		}
	}
}