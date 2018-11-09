#include<iostream>
#include<queue>
#include<cstdio>
using namespace std;

int N, K;
queue<int> q;
int visit[100001];
int dx[3] = { 1, -1, 0 };
void bfs(int n)
{
	q.push(n);
	visit[n] = 1;
	while (!q.empty())
	{
		int t = q.front(); q.pop();
		dx[2] = t;
		for (int i = 0, tx; i < 3; i++)
		{
			tx = t + dx[i];
			if (tx >= 0 && tx <= 100000 && !visit[tx])
			{
				if (i == 2)
					visit[tx] = visit[t];
				else
					visit[tx] = visit[t] + 1;
				q.push(tx);
			}
			else if (tx >= 0 && tx <= 100000 && visit[tx])
				if (i == 2 && visit[tx] > visit[t])
				{
					visit[tx] = visit[t];
					q.push(tx);
				}
				else if (i < 2 && visit[tx] > visit[t] + 1)
				{
					visit[tx] = visit[t] + 1;
					q.push(tx);
				}
		}
	}
}
int main()
{
	scanf("%d%d", &N, &K);
	if (N == K)	printf("0\n");
	else
	{
		bfs(N);
		printf("%d\n", visit[K]-1);
	}
	return 0;
}