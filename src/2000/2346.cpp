#include<iostream>
#include<cstdio>
#include<deque>
using namespace std;

int N;
deque<pair<int, int>> dq;
int main()
{
	scanf("%d", &N);
	for (int i = 0, x; i < N; i++)
	{
		scanf("%d", &x);
		dq.push_back(make_pair(i+1,x));
	}
	while (1)
	{
		pair<int, int> t = dq.front(); dq.pop_front();
		printf("%d ", t.first);
		if (dq.empty()) break;
		if (t.second > 0)
			for (int i = 0; i < t.second-1; i++)
			{
				dq.push_back(dq.front());
				dq.pop_front();
			}
		else
			for (int i = 0; i < (-t.second); i++)
			{
				dq.push_front(dq.back());
				dq.pop_back();
			}
	}
	return 0;
}