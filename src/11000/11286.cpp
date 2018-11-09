#include<iostream>
#include<queue>
#include<algorithm>
#include<functional>
using namespace std;

priority_queue<pair<int, int>,vector<pair<int,int>>, greater<pair<int,int>>> pq;
int N, x;
int main()
{
	freopen("input.txt", "r", stdin);
	scanf("%d", &N);
	while (N--)
	{
		scanf("%d", &x);
		if (!x)
		{
			if (pq.empty()) printf("0\n");
			else
			{
				printf("%d\n", pq.top().second);
				pq.pop();
			}
		}
		else
			pq.push(make_pair(abs(x), x ));
	}
	return 0;
}