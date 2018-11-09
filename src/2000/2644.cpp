#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int N, A, B, M, visit[101];
vector<int> g[101];
queue<int> q;
int bfs(int a)
{
	visit[a] = 1;
	q.push(a);
	while (!q.empty())
	{
		int t = q.front(); q.pop();
		for (auto v : g[t])
		{
			if (!visit[v])
			{
				if (v == B) return visit[t];
				visit[v] = visit[t] + 1;
				q.push(v);
			}
		}
	}
	return -1;
}
int main()
{
	scanf("%d%d%d%d", &N, &A, &B, &M);
	for (int i = 0, a, b; i < M; i++)
	{
		scanf("%d%d", &a, &b);
		g[a].push_back(b);
		g[b].push_back(a);
	}
	printf("%d\n",bfs(A));
	return 0;
}