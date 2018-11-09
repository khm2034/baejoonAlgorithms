#include<iostream>
#include<cstdio>
#include<memory.h>
#define QUEUESIZE 250005
using namespace std;

bool graph[501][501];
bool visit[501];
int N, M, cnt, T;
int q[QUEUESIZE], front, rear;
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
	bool ret = true;
	bool chk[501];
	push(n);
	visit[n] = true;
	while (rear != front)
	{
		int t = pop();
		for (int i = 1; i <= N; i++)
		{
			if (t == i) continue;
			if (graph[t][i] && !visit[i])
			{
				chk[i] = visit[i] = true;
				graph[i][t] = false;
				push(i);
			}
			else if (graph[t][i] && visit[i] && chk[i])
				ret = false;
		}
	}
	return ret;
}
int main()
{
	freopen("input.txt", "r", stdin);
	while(1)
	{
		scanf("%d%d", &N, &M);
		if (!N && !M)
			break;
		memset(graph, false, sizeof(graph));
		memset(visit, false, sizeof(visit));
		cnt = 0;
		for (int i = 0, from, to; i < M; i++)
		{
			scanf("%d%d", &from, &to);
			graph[from][to] = true;
			graph[to][from] = true;
		}
		for (int i = 1; i <= N; i++)
		{
			if (!visit[i])
				if (bfs(i))
					cnt++;
		}
		if (cnt == 0) printf("Case %d: No trees.\n", ++T);
		else if (cnt == 1) printf("Case %d: There is one tree.\n", ++T);
		else	printf("Case %d: A forest of %d trees.\n", ++T, cnt);
	}
	return 0;
}