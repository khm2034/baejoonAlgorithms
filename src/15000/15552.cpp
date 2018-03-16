#include <iostream>
#include <cstdio>
using namespace std;

int main()
{
	int T;
	scanf("%d", &T);
	int a, b;
	for (int tc = 0; tc < T; tc++)
	{
		scanf("%d %d", &a, &b);
		printf("%d\n", a + b);
	}
	return 0;
}