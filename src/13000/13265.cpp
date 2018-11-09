#include<iostream>
#include<cstdio>
#include<vector>
#include<memory.h>
#define QUEUESIZE 1000005
using namespace std;

int T, N, M;
vector<int> graph[1001];
int q[QUEUESIZE], rear, front;
int visit[1001];
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
bool bfs(int n)
{
	push(n);
	visit[n] = true;
	while (rear != front)
	{
		int t = pop();
		int sz = graph[t].size();
		for (int i = 0; i < sz; i++)
		{
			if (!visit[graph[t][i]])
			{
				visit[graph[t][i]] = -visit[t];
				push(graph[t][i]);
			}
			else if (visit[graph[t][i]] == visit[t])
				return false;
		}
	}
	return true;
}
int main()
{
	scanf("%d", &T);
	for (int tc = 0; tc < T; tc++)
	{
		memset(visit, 0, sizeof(visit));
		front = rear;
		for (int i = 0; i < 1001; i++)
			graph[i].clear();
		scanf("%d%d", &N, &M);
		for (int i = 0, a, b; i < M; i++)
		{
			scanf("%d%d", &a, &b);
			graph[a].push_back(b);
			graph[b].push_back(a);
		}
		bool ret = true;
		for (int i = 0; i < N; i++)
		{
			memset(visit, 0, sizeof(visit));
			front = rear;
			ret &= bfs(i);
		}
		if (ret)	printf("possible\n");
		else	printf("impossible\n");
	}
	return 0;
}