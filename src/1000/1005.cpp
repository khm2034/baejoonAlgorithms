#include<iostream>
#include<cstdio>
#include<vector>
#include<memory.h>
using namespace std;

int T, N, K, W;
int to, from;
int time[1001];
vector<int> graph[1001];
int visit[1001];

int dfs(int n)
{
	int size = graph[n].size();
	if (size == 0)
		return 0;
	int max = -1e9;
	for (int i = 0; i < size; i++)
	{
		if (visit[graph[n][i]] == -1)
			visit[graph[n][i]] += (dfs(graph[n][i]) + time[graph[n][i]] + 1);
		if (max < visit[graph[n][i]])
			max = visit[graph[n][i]];
	}
	return max;
}

int main()
{
	scanf("%d", &T);
	for (int tc = 0; tc < T; tc++)
	{
		memset(time, 0, sizeof(time));
		memset(visit, -1, sizeof(visit));
		for (int i = 1; i <= N; i++)
			graph[i].clear();
		scanf("%d%d", &N, &K);
		for (int i = 1; i <= N; i++)
			scanf("%d", &time[i]);
		for (int i = 0; i < K; i++)
		{
			scanf("%d%d", &to, &from);
			graph[from].push_back(to);
		}
		scanf("%d", &W);
		printf("%d\n", dfs(W) + time[W]);
	}
	return 0;
}