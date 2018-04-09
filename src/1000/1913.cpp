#include<iostream>
using namespace std;

int N, M, K;
int arr[1000][1000];
int i,j;
int main()
{
	cin >> N >> M;
	K = N * N;
	while (K > 0)
	{
		for (;i < N; i++)
		{
			if (arr[i][j])
				break;
			arr[i][j] = K--;
		}
		i--; j++;
		for (;j < N; j++)
		{
			if (arr[i][j])
				break;
			arr[i][j] = K--;
		}
		j--; i--;
		for (; i >= 0; i--)
		{
			if (arr[i][j])
				break;
			arr[i][j] = K--;
		}
		i++; j--;
		for (; j >=0; j--)
		{
			if (arr[i][j])
				break;
			arr[i][j] = K--;
		}
		j++; i++;
	}
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (arr[i][j] == M)
			{
				::i = i + 1;
				::j = j + 1;
			}
			printf("%d ", arr[i][j]);
		}
		printf("\n");
	}
	printf("%d %d\n", i, j);

}