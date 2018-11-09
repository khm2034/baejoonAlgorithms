#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;

vector<vector<int>> node;
int visit[100005] = { 0, };
int depth[100005] = { 0, };
int parent[100005] = { 0, };

void dfs(int here, int d)
{
	visit[here] = 1;
	depth[here] = d;

	for (int i = 0; i < node[here].size(); i++)
	{
		int there = node[here][i];

		if (visit[there] == 0)
		{
			dfs(there, d + 1);
			parent[there] = here;
		}
	}
}

void inputData()
{
	int N;
	scanf("%d", &N);
	node.resize(N + 1);
	int a, b;
	for (int i = 0; i < N - 1; i++)
	{
		scanf("%d%d", &a, &b);
		node[a].push_back(b);
		node[b].push_back(a);
	}
}

void solution()
{
	dfs(1, 1);

	int M;
	int a, b;
	scanf("%d", &M);
	for (int i = 0; i < M; i++)
	{
		scanf("%d%d", &a, &b);
		if (depth[a] < depth[b])
		{
			int tmp = a;
			a = b;
			b = tmp;
		}

		while (depth[a] != depth[b])
		{
			a = parent[a];
		}

		while (a != b)
		{
			a = parent[a];
			b = parent[b];
		}

		printf("%d\n", a);
	}
}

int main()
{
	inputData();
	solution();
	return 0;
}