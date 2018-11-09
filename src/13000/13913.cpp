#include<iostream>
#include<cstdio>
#include<queue>
using namespace std;

int N, K;
queue<int> q;
int visit[100001], dx[3] = { 1, -1, 0 };
int p[100001];
void print_path(int n)
{
	if (p[n] == n)
	{
		printf("%d ", n);
		return;
	}
	print_path(p[n]);
	printf("%d ", n);
}
void dfs(int n)
{
	q.push(n);
	visit[n] = 1;
	p[n] = n;
	while (!q.empty())
	{
		int t = q.front(); q.pop();
		dx[2] = t;
		for (int i = 0, tx; i < 3; i++)
		{
			tx = t + dx[i];
			if (tx >= 0 && tx <= 100000 && !visit[tx])
			{
				visit[tx] = visit[t] + 1;
				p[tx] = t;
				if (tx == K)
				{
					printf("%d\n", visit[t]);
					print_path(tx);
					return;
				}
				q.push(tx);
			}
		}
	}
}
int main()
{
	scanf("%d%d", &N, &K);
	if (N == K) printf("0\n%d\n", N);
	else dfs(N);
	return 0;
}