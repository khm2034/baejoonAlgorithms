#include<cstdio>
#include<iostream>
using namespace std;

int N, M;
int arr[1030][1030];
int p_sum[1030][1030];
void input_data()
{
	scanf("%d %d", &N, &M);
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			scanf("%d", &arr[i][j]);

	for (int i = 1; i < N+1; i++)
		for (int j = 1; j < N+1; j++)
			p_sum[i][j] = arr[i-1][j-1] + p_sum[i][j - 1] + p_sum[i - 1][j] - p_sum[i - 1][j - 1];
}

void solution()
{
	int x1, y1, x2, y2;
	for (int i = 0; i < M; i++)
	{
		scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
		printf("%d\n", p_sum[x2][y2] - p_sum[x1-1][y2] - p_sum[x2][y1-1] + p_sum[x1-1][y1-1]);
	}
}

int main()
{
	freopen("input.txt", "r", stdin);
	input_data();
	solution();
	return 0;
}