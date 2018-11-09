#include<cstdio>
#include<queue>
using namespace std;

int N, K, dx[3] = { 1, -1, 0 };
queue<int> q;
int visit[100001];
int bfs()
{
	q.push(N);
	visit[N] = 1;
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
				if (tx == K)
					return visit[t];
				q.push(tx);
			}
		}
	}
}
int main()
{
	scanf("%d%d", &N, &K);
	if (N == K) printf("0\n");
	else	printf("%d\n", bfs());
	return 0;
}