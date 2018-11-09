#include<iostream>
using namespace std;

int N, a, b;
int main()
{
	scanf("%d", &N);
	a = N / 5; b = N % 5;
	if (b & 1)
		if (!a) {
			printf("-1\n");
			return 0;
		}
		else a--, b += 5;
	b /= 2;
	printf("%d\n", a + b);
	return 0;
}