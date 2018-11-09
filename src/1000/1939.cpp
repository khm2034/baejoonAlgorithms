#include<iostream>
#include<vector>
#include<algorithm>
#include<memory.h>
#define QUEUESIZE 10000005
#define INF ((1<<31)-1)
using namespace std;
vector<pair<int, int>> node[10001];
bool visit[10001];
int N, M;
pair<int, int> q[QUEUESIZE];
int front, rear;
void push(int x, int val)
{
	rear++;
	rear = rear % QUEUESIZE;
	q[rear].first = x;
	q[rear].second = val;
}
pair<int, int> pop()
{
	front++;
	front = front % QUEUESIZE;
	return q[front];
}
bool bfs(int from, int to, int val)
{
	int ret = 0;
	push(from, INF);
	visit[from] = true;
	while (rear != front)
	{
		pair<int, int> t = pop();
		int size = node[t.first].size();
		for (int i = 0; i < size; i++)
		{
			int t_to = node[t.first][i].first;
			int t_val = node[t.first][i].second;
			if (!visit[t_to] && val <= t_val)
			{
				visit[t_to] = true;
				push(t_to, t_val);
			}
		}
	}
	return visit[to];
}
int main()
{
	freopen("input.txt", "r", stdin);
	cin >> N >> M;
	int to, from, val;
	int le = INF;
	int ri = -INF;
	for (int i = 0; i < M; i++)
	{
		cin >> from >> to >> val;
		pair<int, int> t1(from, val);
		pair<int, int> t2(to, val);
		node[to].push_back(t1);
		node[from].push_back(t2);
		if (le > val)
			le = val;
		if (ri < val)
			ri = val;
	}
	cin >> from >> to;
	int mid;
	int ret = 0;
	while (le <= ri)
	{
		memset(visit, false, sizeof(visit));
		mid = (le + ri) / 2;
		bool flag = bfs(from, to, mid);
		if (flag)
		{
			if (ret < mid)
				ret = mid;
			le = mid+1;
		}
		else
			ri = mid-1;
	}
	cout << ret << "\n";
	return 0;
}