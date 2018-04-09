#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;

int N, ret;
int a[51];
int b[51];
bool cmp(int a, int b)
{
	return a > b;
}
int main()
{
	scanf("%d", &N);
	for (int i = 0; i < N; i++)
		scanf("%d", &a[i]);
	for (int i = 0; i < N; i++)
		scanf("%d", &b[i]);
	sort(a, a + N);
	sort(b, b + N, cmp);
	for (int i = 0; i < N; i++)
		ret += a[i] * b[i];
	printf("%d\n", ret);
	return 0;
}