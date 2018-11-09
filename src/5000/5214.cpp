#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
#define QUEUESIZE 10000005
using namespace std;

int N, K, M;
vector<int> node[100001], hyper[1001];
int visit[100001];
bool h_visit[1001];
int q[QUEUESIZE];
int front, rear;
void push(int x)
{
	rear++;
	rear = rear % QUEUESIZE;
	q[rear] = x;
}
int pop()
{
	front++;
	front = front % QUEUESIZE;
	return q[front];
}
void bfs()
{
	push(1);
	visit[1] = 1;
	while (front != rear)
	{
		int t = pop();
		int sz = node[t].size();
		for (int i = 0, sz2, x; i < sz; i++)
		{
			x = node[t][i];
			if (!h_visit[x])
			{
				h_visit[x] = true;
				sz2 = hyper[x].size();
				for (int j = 0; j < sz2; j++)
				{
					if (!visit[hyper[x][j]])
					{
						visit[hyper[x][j]] = visit[t] + 1;
						if (hyper[x][j] == N)
							return;
						push(hyper[x][j]);
					}
				}
			}
		}
	}
}
int main()
{
	freopen("input.txt", "r", stdin);
	scanf("%d%d%d", &N, &K, &M);
	for (int i = 0, x; i < M; i++)
	{
		for (int j = 0; j < K; j++)
		{
			scanf("%d", &x);
			hyper[i].push_back(x);
			node[x].push_back(i);
		}
	}

	bfs();
	if (!visit[N])	printf("-1\n");
	else	printf("%d\n", visit[N]);
	return 0;
}