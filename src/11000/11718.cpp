#include <iostream>
#include <cstdio>
using namespace std;

int main()
{
	freopen("input.txt", "r", stdin);
	char s;
	while (scanf("%c", &s) != EOF)
		printf("%c", s);
	return 0;
}