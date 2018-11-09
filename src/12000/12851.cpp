#include<cstdio>
#include<queue>
using namespace std;

int N, K, dx[3] = { 1, -1, 0 };
queue<int> q;
int visit[100001][2];
int ret = 1e8;
 void bfs()
{
	q.push(N);
	visit[N][0] = 1;
	visit[N][1] = 1;
	while (!q.empty())
	{
		int t = q.front(); q.pop();
		dx[2] = t;
		for (int i = 0, tx; i < 3; i++)
		{
			tx = t + dx[i];
			if (tx >= 0 && tx <= 100000 && !visit[tx][0] 
				&&	visit[t][0] <= ret)
			{
				visit[tx][0] = visit[t][0] + 1;

				visit[tx][1] += visit[t][1];
				if (tx == K)
					ret = visit[t][0];
				else
					q.push(tx);
			}
			else if (tx >= 0 && tx <= 100000 && visit[tx][0] == visit[t][0]+1
				&& visit[t][0] <= ret)
				visit[tx][1] += visit[t][1];
		}
	}
}
int main()
{
	scanf("%d%d", &N, &K);
	if (N == K) printf("0\n1\n");
	else
	{
		bfs();
		printf("%d\n%d\n", ret, visit[K][1]);
	}
	return 0;
}