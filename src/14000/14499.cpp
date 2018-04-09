#include<cstdio>
using namespace std;

int N, M, K;
int x, y;
int map[21][21];
int dice[4][3] = { 
	{-1, 0, -1}, 
	{ 0, 0, 0 },
	{ -1, 0, -1 },
	{ -1, 0, -1 },
};

int dx[4] = { 1, -1, 0, 0, };
int dy[4] = { 0, 0, -1, 1 };

bool safe(int x, int y)
{
	return x >= 0 && x < M && y >= 0 && y < N;
}

void rotate(int dir)
{
	int tmp;
	switch (dir)
	{
	case 1:
		tmp = dice[3][1];
		dice[3][1] = dice[1][2];
		dice[1][2] = dice[1][1];
		dice[1][1] = dice[1][0];
		dice[1][0] = tmp;
		break;
	case 2:
		tmp = dice[3][1];
		dice[3][1] = dice[1][0];
		dice[1][0] = dice[1][1];
		dice[1][1] = dice[1][2];
		dice[1][2] = tmp;
		break;
	case 3:
		tmp = dice[0][1];
		dice[0][1] = dice[1][1];
		dice[1][1] = dice[2][1];
		dice[2][1] = dice[3][1];
		dice[3][1] = tmp;
		break;
	case 4:
		tmp = dice[0][1];
		dice[0][1] = dice[3][1];
		dice[3][1] = dice[2][1];
		dice[2][1] = dice[1][1];
		dice[1][1] = tmp;
		break;
	}
}
int main()
{
	scanf("%d%d%d%d%d", &N, &M, &y, &x, &K);

	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			scanf("%d", &map[i][j]);

	int dir;
	for (int i = 0; i < K; i++)
	{
		scanf("%d", &dir);
		int tmp_x = x + dx[dir - 1];
		int tmp_y = y + dy[dir - 1];
		if (safe(tmp_x, tmp_y))
		{
			x = tmp_x; y = tmp_y;
			rotate(dir);
			if (map[tmp_y][tmp_x])
			{
				dice[3][1] = map[tmp_y][tmp_x];
				map[tmp_y][tmp_x] = 0;
			}
			else
				map[tmp_y][tmp_x] = dice[3][1];
			printf("%d\n", dice[1][1]);
		}
	}
}