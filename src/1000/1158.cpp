#include<cstdio>
#include<deque>
using namespace std;

int N, M;
deque<int> dq;
int main()
{
	scanf("%d%d", &N, &M);
	for (int i = 1; i <= N; i++)
		dq.push_back(i);
	printf("<");
	while (1)
	{
		for (int i = 0; i < M - 1; i++)
		{
			dq.push_back(dq.front());
			dq.pop_front();
		}
		printf("%d", dq.front());
		dq.pop_front();
		if (dq.empty())
			break;
		printf(", ");
	}
	printf(">\n");
	return 0;
}