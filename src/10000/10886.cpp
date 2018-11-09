#include<iostream>
#include<cstdio>
using namespace std;

int N;
int cnt[2];
int main()
{
	scanf("%d", &N);
	for (int i = 0, t; i < N; i++)
	{
		scanf("%d", &t);
		cnt[t]++;
	}
	cnt[0] > cnt[1] ? printf("Junhee is not cute!\n") : printf("Junhee is cute!\n");
}